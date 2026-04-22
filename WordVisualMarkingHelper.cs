using Microsoft.Office.Interop.Word;
using Seclore.Util;
using System;
using System.Collections.Generic;
using System.Linq;
using WordInteropDocument = Microsoft.Office.Interop.Word.Document;
using WordInteropApplication = Microsoft.Office.Interop.Word.Application;   //CHANGE#17356_SHUBHAM

namespace OfficePlugin.Office.Word
{


   

    public class WordVisualMarkingHelper : OfficeVisualMarkingHelper
    {
        private Tuple<WordInteropDocument, ComAttributes> mInteropDocument;		//CHANGE#17356_2_SANJEEV
        private readonly Dictionary<AttributedString.Alignment, WdParagraphAlignment> mReverseWordAlignmentMap;


        private bool IsRangeRtl(Range pRange, PluginsCommon.Util.ComObjectManager pComObjectManager)
        {
            try
            {
                ParagraphFormat lParaFormat = pComObjectManager.DisposableComObject(
                    pRange.ParagraphFormat) as ParagraphFormat;
                return lParaFormat.ReadingOrder == WdReadingOrder.wdReadingOrderRtl;
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Could not read ReadingOrder in {MethodHelper.GetMethodName()} - {pException.Message}. Defaulting to LTR.");
                return false;
            }
        }

        public WordVisualMarkingHelper(OfficeDocument pDocument) : base(pDocument)
        {
            mInteropDocument = new Tuple<WordInteropDocument, ComAttributes>(mDocument.GetInnerDocument() as WordInteropDocument, new ComAttributes());		//CHANGE#17356_2_SANJEEV
            mReverseWordAlignmentMap = new Dictionary<AttributedString.Alignment, WdParagraphAlignment>()
            {
                {AttributedString.Alignment.Center, WdParagraphAlignment.wdAlignParagraphCenter },
                {AttributedString.Alignment.Left, WdParagraphAlignment.wdAlignParagraphLeft },
                {AttributedString.Alignment.Right, WdParagraphAlignment.wdAlignParagraphRight }
            };
        }
        //CHANGE#17356_2_SANJEEV_STARTS
        public override void Close()
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();
            if (mInteropDocument is not null && mInteropDocument.Item2.mbShouldDispose)
            {
                _ = lComObjectManager.DisposableComObject(mInteropDocument.Item1);
                mInteropDocument = null;
            }
        }
        //CHANGE#17356_2_SANJEEV_ENDS
        public override void RefreshVisualMarkings(bool pbShouldRemoveExising = false)
        {
            using (new CLogTraceHelper())
            {
                LoggerWrapper.LogInfo($"Refreshing Visual Markings");
                SetHeaderInternal();
                SetFooterInternal();
            }
        }
        public override void RemoveHeader()
        {
            using (new CLogTraceHelper())
            {
                RemoveHeaderInternal();
            }
        }
        public override void RemoveFooter()
        {
            using (new CLogTraceHelper())
            {
                RemoveFooterInternal();
            }
        }

        #region Header APIs
        private void RemoveHeaderInternal()
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            try
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument.Item1.Application) as WordInteropApplication).UndoRecord) as UndoRecord).StartCustomRecord(ResourceCollectionWrapper.GetResourceById(Constants.Message_Remove_Header));
                List<Range> lHeaderRanges = GetAllHeaderRanges();
                for (int i = 0; i < lHeaderRanges.Count; i++)
                {
                    RemoveHeaderFromRange(lComObjectManager.DisposableComObject(lHeaderRanges[i]) as Range);
                }
                DeleteMetadataForHeader();
            }
            finally
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument.Item1.Application) as WordInteropApplication).UndoRecord) as UndoRecord).EndCustomRecord();
            }
        }
        private void RemoveHeaderFromRange(Range pRange)
        {
            try
            {
                using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
                bool lbIsSecloreHeaderPresent = IsSeclorePropertyPresent(pRange, out Dictionary<string, Field> lKeyVsFieldMap, Constants.Header_Text_Value);
                lKeyVsFieldMap.ToList().ForEach(field => lComObjectManager.DisposableComObject(field.Value));
                if (!lbIsSecloreHeaderPresent)
                {
                    //Nothing to delete
                    return;
                }
                DeleteFields(lKeyVsFieldMap);
                RemoveOrphanedSeparator(pRange);
                pRange.Collapse(WdCollapseDirection.wdCollapseStart);
                /*REVIEW_DONE#SAYALI#24-06-2024: Should we be releasing deleted Fields? Does it cause any error? debug. => No it does not
                if not, ToList and ForEach can add extra references. In case of exception it will not be disposed*/
                // extra ref wont be added. Moved disposable code up to consider exception handling
            }
            catch
            {

            }
        }
        private void SetHeaderInternal()
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            AttributedString lAttributedString = GetHeaderAttributeStringFromMetaData();
            if (lAttributedString is null)
            {
                return;
            }

            List<Range> lRanges = GetAllHeaderRanges();
            try
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument
                    .Item1.Application) as WordInteropApplication)
                    .UndoRecord) as UndoRecord)
                    .StartCustomRecord(ResourceCollectionWrapper.GetResourceById(Constants.Message_Update_Header));

                for (int i = 0; i < lRanges.Count; i++)
                {
                    try
                    {
                        SetHeaderToRange(lComObjectManager.DisposableComObject(lRanges[i]) as Range, lAttributedString);
                    }
                    catch (Exception pException)
                    {
                        LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
                    }
                }
            }
            finally
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument.Item1
                    .Application) as WordInteropApplication)
                    .UndoRecord) as UndoRecord)
                    .EndCustomRecord();
            }
        }
        private List<Range> GetAllHeaderRanges()
        {
            bool lbIsSaved = mInteropDocument.Item1.Saved;      //CHANGE#ETM23180
            /*NOTE: we are caching dirty status and resetting it before returning, because accessing ranges was making document dirty.
            In future if this gets fixed, we don't neet to cache and reset dirty state.*/

            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            List<Range> lRanges = new List<Range>();
            HeadersFooters lHeadersFooters = lComObjectManager.DisposableComObject((
                lComObjectManager.DisposableComObject((
                lComObjectManager.DisposableComObject(mInteropDocument.Item1
                .Sections) as Sections)
                .First) as Section)
                .Headers) as HeadersFooters;

            try
            {
                Range lPrimaryRange = (lComObjectManager.DisposableComObject(
                    lHeadersFooters[WdHeaderFooterIndex.wdHeaderFooterPrimary]) as HeaderFooter).Range;
                if (lPrimaryRange is not null)
                {
                    lRanges.Add(lPrimaryRange);
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
            }
            try
            {
                Range lEvenPageRange = (lComObjectManager.DisposableComObject(
                    lHeadersFooters[WdHeaderFooterIndex.wdHeaderFooterEvenPages]) as HeaderFooter).Range;
                if (lEvenPageRange is not null)
                {
                    lRanges.Add(lEvenPageRange);
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
            }
            try
            {
                Range lFirstPageRange = (lComObjectManager.DisposableComObject(
                    lHeadersFooters[WdHeaderFooterIndex.wdHeaderFooterFirstPage]) as HeaderFooter).Range;
                if (lFirstPageRange is not null)
                {
                    lRanges.Add(lFirstPageRange);
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
            }
            mInteropDocument.Item1.Saved = lbIsSaved;      //CHANGE#ETM23180
            return lRanges;
        }
        private void SetHeaderToRange(Range pHeaderRange, AttributedString pAttributedString)
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            bool lbIsSecloreHeaderPresent = IsSeclorePropertyPresent(pHeaderRange, out Dictionary<string, Field> lKeyVsFieldMap, Constants.Header_Text_Value);
            lKeyVsFieldMap.ToList().ForEach(element => lComObjectManager.DisposableComObject(element.Value));
            if (!lbIsSecloreHeaderPresent)
            {
                //Seclore Header Not Present, Add our header
                AddHeader(pHeaderRange, pAttributedString);
                return;
            }
            bool lbIsHeaderModificationRequired = !AreAllSectionsValid(pHeaderRange, lKeyVsFieldMap, pAttributedString);
            if (lbIsHeaderModificationRequired)
            {
                //Added this to avoid deleting entire header
                DeleteFields(lKeyVsFieldMap);
                RemoveOrphanedSeparator(pHeaderRange);
                pHeaderRange.Collapse(WdCollapseDirection.wdCollapseStart);
                AddHeader(pHeaderRange, pAttributedString);
                return;
            }
        }
        private void AddHeader(Range pHeaderRange, AttributedString pAttributedString)
        {
            //REVIEW_DONE#SAHIL : Have we taken this this string from PMG? multilingual

            string[] lstrOriginalKeys = new string[] { Constants.Header_Text_Value };
            string[] lstrChunkedKeys = mDocument.mMetaDataChunkHelper.GetChunkedKeysFromOriginalKeys(lstrOriginalKeys);
            if (!string.IsNullOrEmpty(pAttributedString.GetStringValue()))
            {
                pHeaderRange.InsertBefore("\r");
            }
            pHeaderRange.Collapse(WdCollapseDirection.wdCollapseStart);
            foreach (string lstrChunkedKey in lstrChunkedKeys.Reverse())
            {
                AddAndPopulateHeaderField(pHeaderRange, pAttributedString, lstrChunkedKey);
            }
        }
        private void AddAndPopulateHeaderField(Range pHeaderRange, AttributedString pAttributedString, string pstrKey)
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            try
            {
                Field lNewField = lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(pHeaderRange.Fields) as Fields)
                    .Add(pHeaderRange,
                        WdFieldType.wdFieldDocProperty,
                        pstrKey,
                        true)) as Field;
                PopulateField(lNewField, pAttributedString);
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured {MethodHelper.GetMethodName()} - {pException.Message}");
            }
        }
        #endregion

        #region Footer APIs
        private void RemoveFooterInternal()
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            try
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument.Item1
                    .Application) as WordInteropApplication)
                    .UndoRecord) as UndoRecord)
                    .StartCustomRecord(ResourceCollectionWrapper.GetResourceById(Constants.Message_Remove_Footer));
                List<Range> lFooterRanges = GetAllFooterRanges();
                for (int i = 0; i < lFooterRanges.Count; i++)
                {
                    RemoveFooterFromRange(lComObjectManager.DisposableComObject(lFooterRanges[i]) as Range);
                }
                DeleteMetadataForFooter();
            }
            finally
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument.Item1
                    .Application) as WordInteropApplication)
                    .UndoRecord) as UndoRecord)
                    .EndCustomRecord();
            }
        }
        private void RemoveFooterFromRange(Range pRange)
        {
            try
            {
                using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();
                bool lbIsSecloreFooterPresent = IsSeclorePropertyPresent(pRange, out Dictionary<string, Field> lKeyVsFieldMap, Constants.Footer_Text_Value);
                lKeyVsFieldMap.ToList().ForEach(field => lComObjectManager.DisposableComObject(field.Value));
                if (!lbIsSecloreFooterPresent)
                {
                    //Nothing to delete
                    return;
                }
                DeleteFields(lKeyVsFieldMap);
                RemoveOrphanedSeparator(pRange, WdCollapseDirection.wdCollapseEnd);
                pRange.Collapse(WdCollapseDirection.wdCollapseStart);
            }
            catch
            {

            }
        }
        private void SetFooterInternal()
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            AttributedString lAttributedString = GetFooterAttributeStringFromMetaData();
            if (lAttributedString is null)
            {
                return;
            }
            try
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument.Item1.Application) as WordInteropApplication).UndoRecord) as UndoRecord)
                    .StartCustomRecord(ResourceCollectionWrapper.GetResourceById(Constants.Message_Update_Footer));
                List<Range> lRanges = GetAllFooterRanges();
                for (int i = 0; i < lRanges.Count; i++)
                {
                    try
                    {
                        SetFooterToRange(lComObjectManager.DisposableComObject(lRanges[i]) as Range, lAttributedString);
                    }
                    catch (Exception pException)
                    {
                        LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
                    }
                }
            }
            finally
            {
                (lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(mInteropDocument.Item1
                    .Application) as WordInteropApplication)
                    .UndoRecord) as UndoRecord)
                    .EndCustomRecord();
            }
        }
        private List<Range> GetAllFooterRanges()
        {
            bool lbIsSaved = mInteropDocument.Item1.Saved;      //CHANGE#ETM23180

            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            List<Range> lRanges = new List<Range>();
            HeadersFooters lFooters = lComObjectManager.DisposableComObject((
                lComObjectManager.DisposableComObject((
                lComObjectManager.DisposableComObject(mInteropDocument.Item1
                .Sections) as Sections)
                .First) as Section)
                .Footers) as HeadersFooters;

            try
            {
                Range lPrimaryRange = (lComObjectManager.DisposableComObject(
                    lFooters[WdHeaderFooterIndex.wdHeaderFooterPrimary]) as HeaderFooter).Range;
                if (lPrimaryRange is not null)
                {
                    lRanges.Add(lPrimaryRange);
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
            }
            try
            {
                Range lEvenPageRange = (lComObjectManager.DisposableComObject(
                    lFooters[WdHeaderFooterIndex.wdHeaderFooterEvenPages]) as HeaderFooter).Range;
                if (lEvenPageRange is not null)
                {
                    lRanges.Add(lEvenPageRange);
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
            }
            try
            {
                Range lFirstPageRange = (lComObjectManager.DisposableComObject(
                    lFooters[WdHeaderFooterIndex.wdHeaderFooterFirstPage]) as HeaderFooter).Range;
                if (lFirstPageRange is not null)
                {
                    lRanges.Add(lFirstPageRange);
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
            }
            mInteropDocument.Item1.Saved = lbIsSaved;      //CHANGE#ETM23180
            return lRanges;
        }
        private void SetFooterToRange(Range pFooterRange, AttributedString pAttributedString)
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();
            bool lbIsSecloreFooterPresent = IsSeclorePropertyPresent(pFooterRange, out Dictionary<string, Field> lKeyVsFieldMap, Constants.Footer_Text_Value);
            lKeyVsFieldMap.ToList().ForEach(element => lComObjectManager.DisposableComObject(element.Value));
            if (!lbIsSecloreFooterPresent)
            {
                //Footer Not Present, Add our footer
                pFooterRange.Collapse(WdCollapseDirection.wdCollapseEnd);
                AddFooter(pFooterRange, pAttributedString);
                return;
            }
            bool lbIsFooterModificationRequired = !AreAllSectionsValid(pFooterRange, lKeyVsFieldMap, pAttributedString);
            if (lbIsFooterModificationRequired)
            {
                //Added this to avoid deleting entire footer
                DeleteFields(lKeyVsFieldMap);
                RemoveOrphanedSeparator(pFooterRange, WdCollapseDirection.wdCollapseEnd);
                pFooterRange.Collapse(WdCollapseDirection.wdCollapseEnd);
                AddFooter(pFooterRange, pAttributedString);
                return;
            }
        }
        // AFTER
        private void AddFooter(Range pFooterRange, AttributedString pAttributedString)
        {
            string[] lstrOriginalKeys = new string[] { Constants.Footer_Text_Value };
            string[] lstrChunkedKeys = mDocument.mMetaDataChunkHelper.GetChunkedKeysFromOriginalKeys(lstrOriginalKeys);
            if (!string.IsNullOrEmpty(pAttributedString.GetStringValue()))
            {
                pFooterRange.InsertAfter("\r");
            }
            pFooterRange.Collapse(WdCollapseDirection.wdCollapseEnd);
            foreach (string lstrChunkedKey in lstrChunkedKeys.Reverse())
            {
                AddAndPopulateFooterField(pFooterRange, pAttributedString, lstrChunkedKey);
            }
        }
        private void AddAndPopulateFooterField(Range pFooterRange, AttributedString pAttributedString, string pstrKey)
        {
            try
            {
                using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
                Field lNewField = lComObjectManager.DisposableComObject((
                    lComObjectManager.DisposableComObject(pFooterRange
                    .Fields) as Fields)
                    .Add(pFooterRange,
                        WdFieldType.wdFieldDocProperty,
                        pstrKey,
                        true)) as Field;
                PopulateField(lNewField, pAttributedString);
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured {MethodHelper.GetMethodName()} - {pException.Message}");
            }
        }
        #endregion

        #region Common APIs
        private void RemoveOrphanedSeparator(Range pRange, WdCollapseDirection pDirection = WdCollapseDirection.wdCollapseStart)
        {
            try
            {
                string lstrText = pRange.Text;
                if (string.IsNullOrEmpty(lstrText) || lstrText.Length <= 1)
                {
                    return;
                }
                using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();
                Range lOrphanRange = lComObjectManager.DisposableComObject(pRange.Duplicate) as Range;

                if (pDirection == WdCollapseDirection.wdCollapseStart)
                {
                    // Header: separator is at the START
                    if (lstrText.StartsWith("\n\r") && lstrText.Length > 2)
                    {
                        lOrphanRange.SetRange(pRange.Start, pRange.Start + 2);
                        lOrphanRange.Delete();
                    }
                    else if (lstrText.StartsWith("\n") && lstrText.Length > 1)
                    {
                        lOrphanRange.SetRange(pRange.Start, pRange.Start + 1);
                        lOrphanRange.Delete();
                    }
                    else if (lstrText.StartsWith("\r") && lstrText.Length > 1)
                    {
                        lOrphanRange.SetRange(pRange.Start, pRange.Start + 1);
                        lOrphanRange.Delete();
                    }
                }
                else
                {
                    // Footer: separator is at the END
                    if (lstrText.EndsWith("\r\n") && lstrText.Length > 2)
                    {
                        lOrphanRange.SetRange(pRange.End - 2, pRange.End);
                        lOrphanRange.Delete();
                    }
                    else if (lstrText.EndsWith("\n") && lstrText.Length > 1)
                    {
                        lOrphanRange.SetRange(pRange.End - 1, pRange.End);
                        lOrphanRange.Delete();
                    }
                    else if (lstrText.EndsWith("\r") && lstrText.Length > 1)
                    {
                        lOrphanRange.SetRange(pRange.End - 1, pRange.End);
                        lOrphanRange.Delete();
                    }
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured in {MethodHelper.GetMethodName()} - {pException.Message}");
            }
        }


        private WdParagraphAlignment GetAlignment(AttributedString.Alignment pAlignment, bool pbIsRtl = false)
        {
            if (pbIsRtl)
            {
                if (pAlignment == AttributedString.Alignment.Left)
                    pAlignment = AttributedString.Alignment.Right;
                else if (pAlignment == AttributedString.Alignment.Right)
                    pAlignment = AttributedString.Alignment.Left;
                // Center stays as-is
            }
            return mReverseWordAlignmentMap.TryGetValue(pAlignment, out WdParagraphAlignment lWdParagraphAlignment) ?
                lWdParagraphAlignment : WdParagraphAlignment.wdAlignParagraphJustify;
        }
        private bool AreAllSectionsValid(Range pRange, Dictionary<string, Field> pFieldMap, AttributedString pAttributedString)
        {
            string lstrExistingSectionText = pRange.Text.Trim();
            string lstrSectionTextAsInput = pAttributedString.GetStringValue();

            if (!lstrExistingSectionText.Contains(lstrSectionTextAsInput))     //CHANGE#ETM23284: Srinivas
            {
                return false;
            }

            Dictionary<string, string> lChunkedMetaData = mDocument.GetEntireMetaData();
            foreach (KeyValuePair<string, Field> lPair in pFieldMap)
            {
                if (!lChunkedMetaData.TryGetValue(lPair.Key, out string lstrValue))
                {
                    return false;
                }
                bool lbIsTextContentValidInField = IsTextContentValidInField(lPair.Value, lstrValue);
                if (!lbIsTextContentValidInField)
                {
                    return false;
                }
                bool lbIsFiledValid = IsFieldValid(lPair.Value, pAttributedString);
                if (!lbIsFiledValid)
                {
                    return false;
                }
            }
            return true;
        }
        private bool IsSeclorePropertyPresent(Range pRange, out Dictionary<string, Field> pFieldMap, string pstrProperty)
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            pFieldMap = new Dictionary<string, Field>();
            Dictionary<string, bool> lstrChunkedKeysPresentMap = mDocument.mMetaDataChunkHelper
                .GetChunkedKeysFromOriginalKeys(new string[] { pstrProperty })
                .ToDictionary(element => element, element => false);

            Fields lFields = lComObjectManager.DisposableComObject(pRange.Fields) as Fields;
            for (int i = 1; i <= lFields.Count; i++)
            {
                Field lField = lFields[i];
                if (lField.Type != WdFieldType.wdFieldDocProperty)
                {
                    lComObjectManager.DisposableComObject(lField);
                    continue;
                }
                string lstrActualPropertyName = GetActualPropertyNameFromFieldCode(
                    (lComObjectManager.DisposableComObject(lField.Code) as Range).Text);
                if (lstrActualPropertyName.StartsWith(pstrProperty))
                {
                    lstrChunkedKeysPresentMap[lstrActualPropertyName] = true;
                    pFieldMap[lstrActualPropertyName] = lField;
                }
                else
                {
                    lComObjectManager.DisposableComObject(lField);
                }
            }
            return lstrChunkedKeysPresentMap.Any(kvp => kvp.Value == true);
        }
        private string GetActualPropertyNameFromFieldCode(string pstrFieldCode)
        {
            string[] lParts = pstrFieldCode.Trim().Split(' ');
            return lParts[1];
        }
        private void PopulateField(Field pField, AttributedString pAttributedString)
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();
            Range lResult = lComObjectManager.DisposableComObject(pField.Result) as Range;
            Font lFont = lComObjectManager.DisposableComObject(lResult.Font) as Font;
            ParagraphFormat lParaFormat = lComObjectManager.DisposableComObject(lResult.ParagraphFormat) as ParagraphFormat;

            bool lbIsRtl = IsRangeRtl(lResult, lComObjectManager);  // ← NEW

            lParaFormat.Alignment = GetAlignment(pAttributedString.GetAlignment(), lbIsRtl);  // ← CHANGED

            lFont.Size = pAttributedString.GetFontSize();
            System.Drawing.Color lColor = System.Drawing.ColorTranslator.FromHtml(pAttributedString.GetColorHexValue());
            (lComObjectManager.DisposableComObject(lFont.TextColor) as ColorFormat)
                .RGB = (lColor.R + 0x100 * lColor.G + 0x10000 * lColor.B);
        }
        private void DeleteFields(Dictionary<string, Field> pKeyVsFieldMap)
        {
            pKeyVsFieldMap.ToList().ForEach(kvp => kvp.Value.Delete());
        }
        private bool IsTextContentValidInField(Field pField, string pstrValue)
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            return (lComObjectManager.DisposableComObject(pField.Result) as Range).Text.Equals(pstrValue);
        }
        private bool IsFieldValid(Field pField, AttributedString pAttributedString)
        {
            using var lComObjectManager = new PluginsCommon.Util.ComObjectManager();    //CHANGE#17356_SHUBHAM
            Range lResult = lComObjectManager.DisposableComObject(pField.Result) as Range;
            Font lFont = lComObjectManager.DisposableComObject(lResult.Font) as Font;
            if (!AreFloatsEqual(lFont.Size,
                pAttributedString.GetFontSize()))
            {
                return false;
            }
            // Replace the Alignment check block with this:

            bool lbIsRtl = IsRangeRtl(lResult, lComObjectManager);  // ← NEW

            if (!(lComObjectManager.DisposableComObject(lResult
                .ParagraphFormat) as ParagraphFormat)
                .Alignment
                .Equals(GetAlignment(pAttributedString.GetAlignment(), lbIsRtl)))  // ← CHANGED
            {
                return false;
            }

            //Return true if getting color fails, will not re add header/footer
            try
            {
                System.Drawing.Color lColor = System.Drawing.ColorTranslator.FromHtml(pAttributedString.GetColorHexValue());
                System.Drawing.Color lPresentColor = GetColorForOfficeFromInt(
                    (lComObjectManager.DisposableComObject(lFont
                            .TextColor) as ColorFormat)
                            .RGB);

                if (!lColor.Equals(lPresentColor))
                {
                    return false;
                }
            }
            catch (Exception pException)
            {
                LoggerWrapper.LogDebug($"Exception Occured {MethodHelper.GetMethodName()} - {pException.Message}");
                LoggerWrapper.LogDebug($"Absorbing Exception and returning as color Mismatched");
                return true;
            }
            return true;
        }
        #endregion

    }
}
