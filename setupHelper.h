#ifndef __FSSETUPHELPER_H_
#define __FSSETUPHELPER_H_

/*******************************************************************************
* SetupHelper.h: 1.2.0.0													   *
* Seclore: 2.64.0.0														   *
* Desktop Client: 2.39.0.0													   *
*******************************************************************************/

#ifdef FSSETUPHELPER_EXPORTS
#define FSSETUPHELPER_API __declspec(dllexport)
#else
#define FSSETUPHELPER_API __declspec(dllimport)
#endif

// --------------------------- Constants

/* Max. length of error message. */
#ifndef ERROR_MSG_MAX_LEN
	#define ERROR_MSG_MAX_LEN				1000
#endif

/* Max. length of Component Identifier. */
#ifndef MAX_COMP_ID_LEN
	#define MAX_COMP_ID_LEN					100
#endif

// CHANGE#4282 - STARTS
/* Max. length of GUID. */
#ifndef MAX_GUID_LEN
#define MAX_GUID_LEN						63
#endif
// CHANGE#4282 - ENDS

/* Max. length of Company name. */
#ifndef MAX_COMPANY_LEN
	#define MAX_COMPANY_LEN					100
#endif

/* Max. length of Component name. */
#ifndef MAX_COMP_NAME_LEN
	#define MAX_COMP_NAME_LEN				200
#endif

/* Max. length of Component description. */
#ifndef MAX_COMP_DESC_LEN
	#define MAX_COMP_DESC_LEN				1000
#endif

/* Max. length of Component version. */
#ifndef MAX_COMP_VERSION_LEN
	#define MAX_COMP_VERSION_LEN			50
#endif

/* Max. length of Component upgrade URL. */
#ifndef MAX_URL_LEN
	#define MAX_URL_LEN						1000
#endif

/* Max. length of uninstallation string. */
#ifndef MAX_COMP_UNISTSTRING
	#define MAX_COMP_UNISTSTRING			500
#endif

/* Max. length of verb name. */
#ifndef MAX_VERB_NAME_LEN
	#define MAX_VERB_NAME_LEN				50
#endif

/* Max. length of verb's menu caption. */
#ifndef MAX_VERB_CAPTION_LEN
	#define MAX_VERB_CAPTION_LEN			1000	//CHANGE#5905_Faiz:1
#endif

/* Max. length of verb command. */
#ifndef MAX_VERB_CMD_LEN
	#define MAX_VERB_CMD_LEN				1024
#endif

/* Max. length of verb DDE command. */
#ifndef MAX_VERB_DDECMD_LEN
	#define MAX_VERB_DDECMD_LEN				2048
#endif

/* Max. length of verb DDE application name. */
#ifndef MAX_VERB_DDEAPP_LEN
	#define MAX_VERB_DDEAPP_LEN				50
#endif

/* Max. length of verb DDE topic. */
#ifndef MAX_VERB_DDETOPIC_LEN
	#define MAX_VERB_DDETOPIC_LEN			50
#endif

/* Max. length of file type identifier. */
#ifndef MAX_FILETYPE_ID_LEN
	#define MAX_FILETYPE_ID_LEN				100
#endif

/* Max. length of file type name. */
#ifndef MAX_FILETYPE_NAME_LEN
	#define MAX_FILETYPE_NAME_LEN			200
#endif

/* Max. length of path of default icon. */
#ifndef MAX_FILETYPE_DEFICON_LEN
	#define MAX_FILETYPE_DEFICON_LEN		500
#endif

/* Max. length of Custom Editor name. */
#ifndef MAX_EDITOR_NAME_LEN
	#define MAX_EDITOR_NAME_LEN				100
#endif

/* Max. length of file extension. */
#ifndef MAX_EXT_LEN
	#define MAX_EXT_LEN						25
#endif

/* Max. length of locale code. */
#ifndef MAX_LOCALE_LEN
	#define MAX_LOCALE_LEN					25
#endif

/* Max. length of identifier of Offline Identity Establishment component. */
#ifndef MAX_OFFLINE_COMP_ID_LEN
	#define MAX_OFFLINE_COMP_ID_LEN			100
#endif // #ifndef MAX_OFFLINE_COMP_ID_LEN

/* Max. length of name of Offline Identity Establishment component. */
#ifndef MAX_OFFLINE_COMP_NAME_LEN
	#define MAX_OFFLINE_COMP_NAME_LEN		100
#endif // #ifndef MAX_OFFLINE_COMP_NAME_LEN

/* Max. length of version of Offline Identity Establishment component. */
#ifndef MAX_OFFLINE_COMP_VER_LEN
	#define MAX_OFFLINE_COMP_VER_LEN		100
#endif // #ifndef MAX_OFFLINE_COMP_VER_LEN

/* Max. length of description of Offline Identity Establishment component. */
#ifndef MAX_OFFLINE_COMP_DESC_LEN
	#define MAX_OFFLINE_COMP_DESC_LEN		1000
#endif // #ifndef MAX_OFFLINE_COMP_DESC_LEN


/* Max. length of identifier of Seclore Event Handler. */
#ifndef MAX_FSEVENT_COMP_ID_LEN
	#define MAX_FSEVENT_COMP_ID_LEN			100
#endif // #ifndef MAX_FSEVENT_COMP_ID_LEN

/* Max. length of name of Seclore Event Handler. */
#ifndef MAX_FSEVENT_COMP_NAME_LEN
	#define MAX_FSEVENT_COMP_NAME_LEN		100
#endif // #ifndef MAX_FSEVENT_COMP_NAME_LEN

/* Max. length of version of Offline Identity Establishment component. */
#ifndef MAX_FSEVENT_COMP_VER_LEN
	#define MAX_FSEVENT_COMP_VER_LEN		100
#endif // #ifndef MAX_FSEVENT_COMP_VER_LEN

/* Max. length of description of Offline Identity Establishment component. */
#ifndef MAX_FSEVENT_COMP_DESC_LEN
	#define MAX_FSEVENT_COMP_DESC_LEN		1000
#endif // #ifndef MAX_FSEVENT_COMP_DESC_LEN

// CHANGE#4423 - STARTS
/* Max. length of identifier of Seclore Event Handler. */
#ifndef MAX_FSEVENT_COMP_ID_LEN_BYTES
	#define MAX_FSEVENT_COMP_ID_LEN_BYTES			MAX_FSEVENT_COMP_ID_LEN * sizeof(TCHAR)
#endif // #ifndef MAX_FSEVENT_COMP_ID_LEN_BYTES

/* Max. length of name of Seclore Event Handler. */
#ifndef MAX_FSEVENT_COMP_NAME_LEN_BYTES
	#define MAX_FSEVENT_COMP_NAME_LEN_BYTES			MAX_FSEVENT_COMP_NAME_LEN * sizeof(TCHAR)
#endif // #ifndef MAX_FSEVENT_COMP_NAME_LEN_BYTES

/* Max. length of version of Offline Identity Establishment component. */
#ifndef MAX_FSEVENT_COMP_VER_LEN_BYTES
	#define MAX_FSEVENT_COMP_VER_LEN_BYTES			MAX_FSEVENT_COMP_VER_LEN * sizeof(TCHAR)
#endif // #ifndef MAX_FSEVENT_COMP_VER_LEN_BYTES

/* Max. length of description of Offline Identity Establishment component. */
#ifndef MAX_FSEVENT_COMP_DESC_LEN_BYTES
	#define MAX_FSEVENT_COMP_DESC_LEN_BYTES			MAX_FSEVENT_COMP_DESC_LEN * sizeof(TCHAR)
#endif // #ifndef MAX_FSEVENT_COMP_DESC_LEN_BYTES
// CHANGE#4423 - ENDS

#ifndef FSDCASSIST_FLAGS
#define FSDCASSIST_FLAGS

/* Perform only User level actions. */
#define FSDCASSIST_FLAG_USER				(0x00000001L)
/* Perform only Machine level actions. */
#define FSDCASSIST_FLAG_MACHINE				(0x00000002L)
/* Perform User and Machine level actions. */
#define FSDCASSIST_FLAG_BOTH				((0x00000001L)|(0x00000002L))

#endif // #ifndef FSDCASSIST_FLAGS

/* Indicates successful execution of APP. */
#ifndef SETUP_SUCCESS
	#define SETUP_SUCCESS					1
#endif

// CHANGE#4282 - STARTS
/* Type of shell extension handler. */
#ifndef SHELLEX_TYPE
#define SHELLEX_TYPE

#define SHELLEX_TYPE_ICON_HANDLER						1
#define SHELLEX_TYPE_CTX_MENU_HANDLER					2
#define SHELLEX_TYPE_PROP_SHEET_HANDLER					3
#define SHELLEX_TYPE_PREVIEW_HANDLER					4	//CHANGE#7145:P2

#endif SHELLEX_TYPE
// CHANGE#4282 - ENDS

/* MaskIdentity() can be used/called in interactive mode where user input is 
required. Desktop Client will allow users to create Offline Package using Offline 
Identity Estblishment Component only if this option returned by GetOptions(). */
#ifndef OPTION_MASK_INTERACTIVE
#define OPTION_MASK_INTERACTIVE				0x00000001
#endif // #ifndef OPTION_MASK_INTERACTIVE

/* MaskIdentity() can be used/called in non-interactive mode where user input is 
not required. This is reserved for later use. In future, Seclore components like 
Hot Folder Server will allow to create Offline Package using Offline Identity 
Estblishment Component only if this option returned by GetOptions(). */
#ifndef OPTION_MASK_NONINTERACTIVE
#define OPTION_MASK_NONINTERACTIVE			0x00000002
#endif // #ifndef OPTION_MASK_NONINTERACTIVE

/* UnmaskIdentity() can be used/called in interactive mode where user input is 
required. Desktop Client will allow users to unpackage/repackage Offline 
Package using Offline Identity Estblishment Component only if this option 
returned by GetOptions(). */
#ifndef OPTION_UNMASK_INTERACTIVE
#define OPTION_UNMASK_INTERACTIVE			0x00000010
#endif // #ifndef OPTION_UNMASK_INTERACTIVE

/* UnmaskIdentity() can be used/called in non-interactive mode where user input is 
not required. This is reserved for later use. In future, Seclore components like 
Hot Folder Server will allow to unpackge/repackage Offline Package using 
Offline Identity Estblishment Component only if this option returned by 
GetOptions(). */
#ifndef OPTION_UNMASK_NONINTERACTIVE
#define OPTION_UNMASK_NONINTERACTIVE		0x00000020
#endif // #ifndef OPTION_UNMASK_NONINTERACTIVE

// --------------------------- Enums

#ifndef ENUM_COMPONENTTYPE
#define ENUM_COMPONENTTYPE

/* Type of components. */
enum ComponentType 
{
	/* Application plugins. */
	CompTypePlugin	= 1,

	/* Addon (extended features) dependent of Descktop Client. */
	CompTypeAddon	= 2,

	/* Component installed with Desktop Client. */
	CompTypeBasic	= 3,

	/* Applications. */
	CompTypeApp		= 4
};

#endif // #ifndef ENUM_COMPONENTTYPE

#ifndef ENUM_UNINSTALLSTRING_TYPE
#define ENUM_UNINSTALLSTRING_TYPE

/* Type of uninstall string. */
enum UnistallStringType
{
	/* Uninstall string is MSI product code. */
	UninstTypeProductCode		= 1,

	/* Uninstall string is FSDC Assistant library. */
	UninstTypeAssistant			= 2,

	/* Unisntall string is batch file. */
	UninstTypeBatchScript		= 3
};

#endif // #define ENUM_UNINSTALLSTRING_TYPE

// --------------------------- Structures

#ifndef STRUCT_COMPONENTINFOEX
#define STRUCT_COMPONENTINFOEX

/* Component information. */
typedef struct _sComponentInfoExW
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Unique identifier of the Component. */
	wchar_t mstrId[MAX_COMP_ID_LEN+1];

	/* Type of the Component. */
	ComponentType mType;

	/* Whether Component can be updated using patchs or not. */
	bool mbUpdatable;
	
	/* Whether Component is dependent on Desktop Client or not. If Compoent is 
	is dependent on the Desktop Client, it will be unistalled befoer Desktop
	Client is uninstalled. */
	bool mbDependent;
	
	/* Name of the company. This must be 'Seclore Technology Pvt. Ltd.' */
	wchar_t mstrCompany[MAX_COMPANY_LEN+1];
	
	/* Friendly name of the Component. */
	wchar_t mstrName[MAX_COMP_NAME_LEN+1];
	
	/* Description of the Component. */
	wchar_t mstrDescription[MAX_COMP_DESC_LEN+1];
	
	/* Version of the Component. */
	wchar_t mstrVersion[MAX_COMP_VERSION_LEN+1];
	
	/* Path of the directory where Component is installed. */
	wchar_t mstrInstallPath[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the file which contains 
	'Release Notes' of Component. */
	wchar_t mstrReleaseNotes[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the FSDC Assistant Library (DLL)
	for Component. */
	wchar_t mstrAssistant[MAX_PATH+1];

	/* Path of Resource folder which contains 
	'<InstalledLocale>/ResColl.<InstalledLocale>.xml' and 
	'<DefaultLocale>/ResColl.<DefaultLocale>.xml' file. This path must be 
	relative to installation directory of component. 
	'<InstalledLocale>/ResColl.<InstalledLocale>.xml' and 
	'<DefaultLocale>/ResColl.<DefaultLocale>.xml' file must contain section 
	called 'DesktopClient'.*/
	wchar_t mstrResCollFolder[MAX_PATH+1];

	/***** If Component is updatable using patches *****/
	
	/* 
	URL to download patches of Component. 

	Note: While registering component, user should specify relative URL.
	*/
	wchar_t mstrURL[MAX_URL_LEN+1];
	
	/* 
	Sequence in which Component should be updated. 

	Note: While registering component, this value is ignored.
	*/
	unsigned long mlSequence;

	/***** If Component is dependent on Desktop Client *****/
	
	/* String used to uninstall component. It can be MSI product code, batch 
	file or FSDC Assistant Library. */
	wchar_t mstrUninstallString[MAX_COMP_UNISTSTRING+1];
	
	/* Type of the Unistall String. */
	UnistallStringType mUnistType;

	/* Current Version of the Component. */
	wchar_t mstrCurrentVersion[MAX_COMP_VERSION_LEN+1];


} ComponentInfoExW;


typedef struct _sComponentInfoExA
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Unique identifier of the Component. */
	char mstrId[MAX_COMP_ID_LEN+1];

	/* Type of the Component. */
	ComponentType mType;

	/* Whether Component can be updated using patchs or not. */
	bool mbUpdatable;
	
	/* Whether Component is dependent on Desktop Client or not. If Compoent is 
	is dependent on the Desktop Client, it will be unistalled befoer Desktop
	Client is uninstalled. */
	bool mbDependent;
	
	/* Name of the company. This must be 'Seclore Technology Pvt. Ltd.' */
	char mstrCompany[MAX_COMPANY_LEN+1];
	
	/* Friendly name of the Component. */
	char mstrName[MAX_COMP_NAME_LEN+1];
	
	/* Description of the Component. */
	char mstrDescription[MAX_COMP_DESC_LEN+1];
	
	/* Version of the Component. */
	char mstrVersion[MAX_COMP_VERSION_LEN+1];
	
	/* Path of the directory where Component is installed. */
	char mstrInstallPath[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the file which contains 
	'Release Notes' of Component. */
	char mstrReleaseNotes[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the FSDC Assistant Library (DLL)
	for Component. */
	char mstrAssistant[MAX_PATH+1];

	/* Path of Resource folder which contains 
	'<InstalledLocale>/ResColl.<InstalledLocale>.xml' and 
	'<DefaultLocale>/ResColl.<DefaultLocale>.xml' file. This path must be 
	relative to installation directory of component. 
	'<InstalledLocale>/ResColl.<InstalledLocale>.xml' and 
	'<DefaultLocale>/ResColl.<DefaultLocale>.xml' file must contain section 
	called 'DesktopClient'.*/
	char mstrResCollFolder[MAX_PATH+1];

	/***** If Component is updatable using patches *****/
	
	/* 
	URL to download patches of Component. 

	Note: While registering component, user should specify relative URL.
	*/
	char mstrURL[MAX_URL_LEN+1];
	
	/* 
	Sequence in which Component should be updated. 

	Note: While registering component, this value is ignored.
	*/
	unsigned long mlSequence;

	/***** If Component is dependent on Desktop Client *****/
	
	/* String used to uninstall component. It can be MSI product code, batch 
	file or FSDC Assistant Library. */
	char mstrUninstallString[MAX_COMP_UNISTSTRING+1];
	
	/* Type of the Unistall String. */
	UnistallStringType mUnistType;

	/* Current Version of the Component. */
	char mstrCurrentVersion[MAX_COMP_VERSION_LEN+1];


} ComponentInfoExA;

#define COMPONENTINFOEXW_SIZE_VER_1			(sizeof(ComponentInfoExW))
#define COMPONENTINFOEXA_SIZE_VER_1			(sizeof(ComponentInfoExA))

#endif // #define STRUCT_COMPONENTINFOEX

#ifndef STRUCT_SUBCOMPONENTINFO
#define STRUCT_SUBCOMPONENTINFO

/* Sub-Component (Language Pack etc.) information. */
typedef struct _sSubComponentInfoW
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Name of the company. This must be 'Seclore Technology Pvt. Ltd.' */
	wchar_t mstrCompany[MAX_COMPANY_LEN+1];

	/* Unique identifier of the sub-component. */
	wchar_t mstrId[MAX_COMP_ID_LEN+1];

	/* Friendly name of the Component. */
	wchar_t mstrName[MAX_COMP_NAME_LEN+1];

	/* Version of the Component. */
	wchar_t mstrVersion[MAX_COMP_VERSION_LEN+1];

	/* 	URL to download patches of Component. 
	Note: While registering component, user should specify relative URL. */
	wchar_t mstrURL[MAX_URL_LEN+1];

	/* Current Version of the Component. */
	wchar_t mstrCurrentVersion[MAX_COMP_VERSION_LEN+1];


} SubComponentInfoW;

typedef struct _sSubComponentInfoA
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Name of the company. This must be 'Seclore Technology Pvt. Ltd.' */
	char mstrCompany[MAX_COMPANY_LEN+1];

	/* Unique identifier of the sub-component. */
	char mstrId[MAX_COMP_ID_LEN+1];

	/* Friendly name of the Component. */
	char mstrName[MAX_COMP_NAME_LEN+1];

	/* Version of the Component. */
	char mstrVersion[MAX_COMP_VERSION_LEN+1];

	/* 	URL to download patches of Component. 
	Note: While registering component, user should specify relative URL. */
	char mstrURL[MAX_URL_LEN+1];

	/* Current Version of the Component. */
	char mstrCurrentVersion[MAX_COMP_VERSION_LEN+1];


} SubComponentInfoA;

#define SUBCOMPONENTINFOW_SIZE_VER_1		(sizeof(SubComponentInfoW))
#define SUBCOMPONENTINFOA_SIZE_VER_1		(sizeof(SubComponentInfoA))

#endif // #define STRUCT_SUBCOMPONENTINFO

#ifndef STRUCT_COMPONENTINFO
#define STRUCT_COMPONENTINFO

/* Deprecated. Use ComponentInfoEx. */

/* Component information. */
typedef struct _sComponentInfoW
{
	/* Unique identifier of the Component. */
	wchar_t mstrId[MAX_COMP_ID_LEN+1];

	/* Type of the Component. */
	ComponentType mType;

	/* Whether Component can be updated using patchs or not. */
	bool mbUpdatable;
	
	/* Whether Component is dependent on Desktop Client or not. If Compoent is 
	is dependent on the Desktop Client, it will be unistalled befoer Desktop
	Client is uninstalled. */
	bool mbDependent;
	
	/* Name of the company. This must be 'Seclore Technology Pvt. Ltd.' */
	wchar_t mstrCompany[MAX_COMPANY_LEN+1];
	
	/* Friendly name of the Component. */
	wchar_t mstrName[MAX_COMP_NAME_LEN+1];
	
	/* Description of the Component. */
	wchar_t mstrDescription[MAX_COMP_DESC_LEN+1];
	
	/* Version of the Component. */
	wchar_t mstrVersion[MAX_COMP_VERSION_LEN+1];
	
	/* Path of the directory where Component is installed. */
	wchar_t mstrInstallPath[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the file which contains 
	'Release Notes' of Component. */
	wchar_t mstrReleaseNotes[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the FSDC Assistant Library (DLL)
	for Component. */
	wchar_t mstrAssistant[MAX_PATH+1];

	/***** If Component is updatable using patches *****/
	
	/* 
	URL to download patches of Component. 

	Note: While registering component, user should specify relative URL.
	*/
	wchar_t mstrURL[MAX_URL_LEN+1];
	
	/* 
	Sequence in which Component should be updated. 

	Note: While registering component, this value is ignored.
	*/
	unsigned long mlSequence;

	/***** If Component is dependent on Desktop Client *****/
	
	/* String used to uninstall component. It can be MSI product code, batch 
	file or FSDC Assistant Library. */
	wchar_t mstrUninstallString[MAX_COMP_UNISTSTRING+1];
	
	/* Type of the Unistall String. */
	UnistallStringType mUnistType;

} ComponentInfoW;


typedef struct _sComponentInfoA
{
	/* Unique identifier of the Component. */
	char mstrId[MAX_COMP_ID_LEN+1];

	/* Type of the Component. */
	ComponentType mType;

	/* Whether Component can be updated using patchs or not. */
	bool mbUpdatable;
	
	/* Whether Component is dependent on Desktop Client or not. If Compoent is 
	is dependent on the Desktop Client, it will be unistalled befoer Desktop
	Client is uninstalled. */
	bool mbDependent;
	
	/* Name of the company. This must be 'Seclore Technology Pvt. Ltd.' */
	char mstrCompany[MAX_COMPANY_LEN+1];
	
	/* Friendly name of the Component. */
	char mstrName[MAX_COMP_NAME_LEN+1];
	
	/* Description of the Component. */
	char mstrDescription[MAX_COMP_DESC_LEN+1];
	
	/* Version of the Component. */
	char mstrVersion[MAX_COMP_VERSION_LEN+1];
	
	/* Path of the directory where Component is installed. */
	char mstrInstallPath[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the file which contains 
	'Release Notes' of Component. */
	char mstrReleaseNotes[MAX_PATH+1];

	/* Path relative to mstrInstallPath of the FSDC Assistant Library (DLL)
	for Component. */
	char mstrAssistant[MAX_PATH+1];

	/***** If Component is updatable using patches *****/
	
	/* 
	URL to download patches of Component. 

	Note: While registering component, user should specify relative URL.
	*/
	char mstrURL[MAX_URL_LEN+1];
	
	/* 
	Sequence in which Component should be updated. 

	Note: While registering component, this value is ignored.
	*/
	unsigned long mlSequence;

	/***** If Component is dependent on Desktop Client *****/
	
	/* String used to uninstall component. It can be MSI product code, batch 
	file or FSDC Assistant Library. */
	char mstrUninstallString[MAX_COMP_UNISTSTRING+1];
	
	/* Type of the Unistall String. */
	UnistallStringType mUnistType;

} ComponentInfoA;

#endif // #define STRUCT_COMPONENTINFO

#ifndef STRUCT_FILETYPEVERB
#define STRUCT_FILETYPEVERB

/*
	Represents Verb of File Class or ProgId which handles file actions.

	Representation in registry:
		HKEY_CLASSES_ROOT
			- <FileType>
				- @ = <File Type Name>
				- DefaultIcon
					- @ = <Icon Path>
				- shell
					- @ = {mstrName}
					- {mstrName}
						- @ = {mstrMenuCaption}
						- command
							- @ = {mstrCommand}
						- ddeexec
							- @ = {mstrDDECmd}
							- Application = {mstrDDEApp}
							- Topic = {mstrDDETopic}
							- ifexec = {mstrDDEIfExec}
*/
typedef struct _sFileTypeVerbW 
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Name of the verb. */
	wchar_t mstrName[MAX_VERB_NAME_LEN+1];

	/* The user-visible text that must be displayed on the Windows shell 
	context menu to represent the shell verb. You can use an ampersand 
	('&') prefix to designate a keyboard accelerator. */
	wchar_t mstrMenuCaption[MAX_VERB_CAPTION_LEN+1];

	/* The command to be executed when this verb is selected. In case of DDE, 
	it is used to start DDE service or application. */
	wchar_t mstrCommand[MAX_VERB_CMD_LEN+1];

	/* Is default verb? */
	bool mbDefault;

	/* Is extended (visible if user uses Shift+RightClick) verb? */
	bool mbExtended;

	/* Whether supports DDE or not. */
	bool mbDDE;

	/* The DDE command string if the shell verb must start a DDE conversation 
	with the application; leave it empty for no DDE conversation. In that case, 
	the remaining DDE-related arguments are ignored.
	The DDE command is typically Open("%1") or [open("%1")], using the same 
	placeholders as above. 
	If application does not support DDE, set to empty string. */
	wchar_t mstrDDECmd[MAX_VERB_DDECMD_LEN+1];

	/* The name of the application with which to conduct the DDE conversation, 
	or leave empty to use the file name from the 'mstrCommand' field. 
	If application does not support DDE, set to empty string. */
	wchar_t mstrDDEApp[MAX_VERB_DDEAPP_LEN+1];

	/* The topic name for the DDE conversation. 
	If application does not support DDE, set to empty string. */
	wchar_t mstrDDETopic[MAX_VERB_DDETOPIC_LEN+1];

	/* The DDE command that must be used if the DDE conversation cannot be 
	initialized (DDE pplication is not running). If you specify this field, it 
	will be used as the DDE command when the conversation is retried by 
	executing 'mstrCommand'. If you leave this field empty, DDE command is used 
	instead. 
	If application does not support DDE, set to empty string. */
	wchar_t mstrDDEIfExec[MAX_VERB_DDECMD_LEN+1];

} FileTypeVerbW;

typedef struct _sFileTypeVerbA 
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Name of the verb. */
	char mstrName[MAX_VERB_NAME_LEN+1];

	/* The user-visible text that must be displayed on the Windows shell 
	context menu to represent the shell verb. You can use an ampersand 
	('&') prefix to designate a keyboard accelerator. */
	char mstrMenuCaption[MAX_VERB_CAPTION_LEN+1];

	/* The command to be executed when this verb is selected. In case of DDE, 
	it is used to start DDE service or application. */
	char mstrCommand[MAX_VERB_CMD_LEN+1];

	/* Is default verb? */
	bool mbDefault;

	/* Is extended (visible if user uses Shift+RightClick) verb? */
	bool mbExtended;

	/* Whether supports DDE or not. */
	bool mbDDE;

	/* The DDE command string if the shell verb must start a DDE conversation 
	with the application; leave it empty for no DDE conversation. In that case, 
	the remaining DDE-related arguments are ignored.
	The DDE command is typically Open("%1") or [open("%1")], using the same 
	placeholders as above. 
	If application does not support DDE, set to empty string. */
	char mstrDDECmd[MAX_VERB_DDECMD_LEN+1];

	/* The name of the application with which to conduct the DDE conversation, 
	or leave empty to use the file name from the 'mstrCommand' field. 
	If application does not support DDE, set to empty string. */
	char mstrDDEApp[MAX_VERB_DDEAPP_LEN+1];

	/* The topic name for the DDE conversation. 
	If application does not support DDE, set to empty string. */
	char mstrDDETopic[MAX_VERB_DDETOPIC_LEN+1];

	/* The DDE command that must be used if the DDE conversation cannot be 
	initialized (DDE pplication is not running). If you specify this field, it 
	will be used as the DDE command when the conversation is retried by 
	executing 'mstrCommand'. If you leave this field empty, DDE command is used 
	instead. 
	If application does not support DDE, set to empty string. */
	char mstrDDEIfExec[MAX_VERB_DDECMD_LEN+1];

} FileTypeVerbA;

#define FILETYPEVERBW_SIZE_VER_1			(sizeof(FileTypeVerbW))
#define FILETYPEVERBA_SIZE_VER_1			(sizeof(FileTypeVerbA))

#endif // #define STRUCT_FILETYPEVERB

// CHANGE#4282 - STARTS
#ifndef STRUCT_SHELLEX
#define STRUCT_SHELLEX

typedef struct _sShellExW
{
	/* Size of the structure. */
	DWORD mlSize;

	/* 
	Type of shell extension. 
	This must be 1 of the values defined by the constants SHELLEX_TYPE. 
	*/
	DWORD mlType;

	/* CLSID of the Icon Handler*/
	wchar_t mstrCLSID[MAX_GUID_LEN + 1];

}ShellExW;

typedef struct _sShellExA
{
	/* Size of the structure. */
	DWORD mlSize;

	/*
	Type of shell extension.
	This must be 1 of the values defined by the constants SHELLEX_TYPE.
	*/
	DWORD mlType;

	/* CLSID of the Icon Handler*/
	char mstrCLSID[MAX_GUID_LEN + 1];

}ShellExA;

#define SHELLEXW_SIZE_VER_1			136
#define SHELLEXA_SIZE_VER_1			72

#endif // #define STRUCT_SHELLEX
// CHANGE#4282 - ENDS

#ifndef STRUCT_FILETYPE
#define STRUCT_FILETYPE

/*
	Represents File Class or ProgId which handles file actions.

	Representation in registry:
		HKEY_CLASSES_ROOT
			- {mstrId}
				- @ = {mstrName}
				- DefaultIcon
					- @ = {mstrDefaultIcon}
				- shell
					- <verb-1>
					- <verb-2>
*/
typedef struct _sFileTypeW 
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Identifier of the file, like Word.Document.12, OpenOffice.org.Odt. */
	wchar_t mstrId[MAX_FILETYPE_ID_LEN+1];

	/* Name of the file type, like Word Document, AutoCAD Drawing. */
	wchar_t mstrName[MAX_FILETYPE_NAME_LEN+1];

	/* Path of the icon file. */
	wchar_t mstrDefaultIcon[MAX_FILETYPE_DEFICON_LEN+1];

	/* No. of verbs in 'mVerbs'. */
	DWORD mlVerbCount;

	/* Verbs for file type. */
	FileTypeVerbW ** mVerbs;

	//------------------ VERSION 1 ------------------------
	// CHANGE#4282 - STARTS
	/* No. of verbs in 'mShellExList'. */
	DWORD mlShellExCount;

	/* ShellEx list for file type. */
	ShellExW ** mShellExList;
	// CHANGE#4282 - ENDS
	//------------------ VERSION 2 ------------------------

} FileTypeW;

typedef struct _sFileTypeA 
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Identifier of the file, like Word.Document.12, OpenOffice.org.Odt. */
	char mstrId[MAX_FILETYPE_ID_LEN+1];

	/* Name of the file type, like Word Document, AutoCAD Drawing. */
	char mstrName[MAX_FILETYPE_NAME_LEN+1];

	/* Path of the icon file. */
	char mstrDefaultIcon[MAX_FILETYPE_DEFICON_LEN+1];

	/* No. of verbs in 'mVerbs'. */
	DWORD mlVerbCount;

	/* Verbs for file type. */
	FileTypeVerbA ** mVerbs;

	//------------------ VERSION 1 ------------------------
	// CHANGE#4282 - STARTS
	/* No. of ShellExtn in 'mShellExList'. */
	DWORD mlShellExCount;

	/* ShellExtn list for file type. */
	ShellExA ** mShellExList;
	// CHANGE#4282 - ENDS
	//------------------ VERSION 2 ------------------------

} FileTypeA;

//------------------ VERSION 1 ------------------------

#define FILETYPEW_SIZE_VER_1				1620	// CHANGE#4282
#define FILETYPEA_SIZE_VER_1				816		// CHANGE#4282

//------------------ VERSION 2 ------------------------

// CHANGE#4282 - STARTS
#define FILETYPEW_SIZE_VER_2				1628
#define FILETYPEA_SIZE_VER_2				824
// CHANGE#4282 - ENDS

#endif // #define STRUCT_FILETYPE

#ifndef STRUCT_CUSTOMEDITOR
#define STRUCT_CUSTOMEDITOR

/*
	Information of Custom Editor.
*/
typedef struct _sCustomEditorW
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Identifier of the editor, like Word.Document.12, OpenOffice.org.Odt. */
	wchar_t mstrId[MAX_FILETYPE_ID_LEN+1];

	/* Name of the application which handles this file type, like Microsoft 
	Word 2003, Open Office 3.x, AutoCAD 2004. */
	wchar_t mstrName[MAX_EDITOR_NAME_LEN+1];

	/* Name of the verb to be used to open protected file. In case is we modify 
	existing file type and add new verb to pass additional parameters, that verb
	should be used to open protected file. */
	wchar_t mstrVerb[MAX_VERB_NAME_LEN+1];

	/* Identifier of the file, like Word.Document.12, OpenOffice.org.Odt.*/
	wchar_t mstrFileType[MAX_FILETYPE_ID_LEN+1];

	/* Is this file type default file type for given extension? */
	bool mbDefault;

	/* This will weightage to decide preference of the editor over other editor for same file type */
	long mlWeightage;

	/* This verb will be overridden and the following commands will be used while DC is installed on machine*/
	wchar_t mstrVerbToOverride[MAX_VERB_NAME_LEN+1];

} CustomEditorW;

typedef struct _sCustomEditorA
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Identifier of the editor, like Word.Document.12, OpenOffice.org.Odt. */
	char mstrId[MAX_FILETYPE_ID_LEN+1];

	/* Name of the application which handles this file type, like Microsoft 
	Word 2003, Open Office 3.x, AutoCAD 2004. */
	char mstrName[MAX_EDITOR_NAME_LEN+1];

	/* Name of the verb to be used to open protected file. In case is we modify 
	existing file type and add new verb to pass additional parameters, that verb
	should be used to open protected file. */
	char mstrVerb[MAX_VERB_NAME_LEN+1];

	/* Identifier of the file, like Word.Document.12, OpenOffice.org.Odt.*/
	char mstrFileType[MAX_FILETYPE_ID_LEN+1];

	/* Is this file type default file type for given extension? */
	bool mbDefault;

	/* This will weightage to decide preference of the editor over other editor for same file type */
	long mlWeightage;

	/* This verb will be overridden and the following commands will be used while DC is installed on machine*/
	char mstrVerbToOverride[MAX_VERB_NAME_LEN+1];

} CustomEditorA;

#define CUSTOMEDITORW_SIZE_VER_1			((CUSTOMEDITORW_SIZE_VER_2)-(sizeof(wchar_t)*((MAX_VERB_NAME_LEN)+1)))
#define CUSTOMEDITORA_SIZE_VER_1			((CUSTOMEDITORA_SIZE_VER_2)-(sizeof(char)*((MAX_VERB_NAME_LEN)+1)))

#define CUSTOMEDITORW_SIZE_VER_2			(sizeof(CustomEditorW))
#define CUSTOMEDITORA_SIZE_VER_2			(sizeof(CustomEditorA))

#endif // #define STRUCT_CUSTOMEDITOR

//CHANGE#ETM24666_25625_SHUBHAM - STARTS
#ifndef STRUCT_OFFLINECOMPCONFIG
#define STRUCT_OFFLINECOMPCONFIG

enum OffIDEstCompConfigFeature
{
	OFFLINE_ID_EST_COMP_CONFIG_FEATURE_NONE			= 0,
	OFFLINE_ID_EST_COMP_CONFIG_FEATURE_CACHING		= 1 << 0
};

#define CACHEMODE_DISABLED								((DWORD)0)
#define CACHEMODE_INFINITE								((DWORD)1)
#define CACHEMODE_EXPIRY_AND_USAGE						((DWORD)2)

typedef DWORD SECOND;
typedef DWORD CACHEMODE;

/* While installation OfflineCompConfig registries will be created by the Offline Component Assistant */
typedef struct _sOfflineCompConfigW
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Flags for features supported by the Component */
	DWORD mlSupportedFeatures;

	/* Preferred Cache mode of the Component */
	CACHEMODE mlCacheMode;

	/* Timed Cache Expiry */
	SECOND mlCacheExpiry;

	/* Timed Cache max usage count */
	DWORD mlCacheMaxUsageCount;

} OfflineCompConfigW;

typedef struct _sOfflineCompConfigA
{
	/* Size of the structure. */
	DWORD mlSize;

	/* Flags for features supported by the Component */
	DWORD mlSupportedFeatures;

	/* Preferred Cache mode of the Component */
	CACHEMODE mlCacheMode;

	/* Timed Cache Expiry */
	SECOND mlCacheExpiry;

	/* Timed Cache max usage count */
	DWORD mlCacheMaxUsageCount;

} OfflineCompConfigA;

#define OFFLINE_COMP_CONFIGW_VER1_SIZE              sizeof(OfflineCompConfigW)
#define OFFLINE_COMP_CONFIGA_VER1_SIZE				sizeof(OfflineCompConfigA)

#endif  //STRUCT_OFFLINECOMPCONFIG
//CHANGE#ETM24666_25625_SHUBHAM - ENDS

#ifndef STRUCT_OFFLINE_COMPONENT
#define STRUCT_OFFLINE_COMPONENT

/*
	this structure contain information about offline id establishment component
*/
typedef struct _sOfflineIdEstCompInfoW
{
	/* Size of the structure. */
	DWORD mlSize;
	
	/* Identifier of the Offline Identity Establishment component. */
	wchar_t mstrId[MAX_OFFLINE_COMP_ID_LEN + 1];
	
	/* Path of the Win32 library (DLL) which implements Offline Identity Establishment component interface. */
	wchar_t mstrPath[MAX_PATH + 1];
	
	/* Name of the Offline Identity Establishment component. */
	wchar_t mstrName[MAX_OFFLINE_COMP_NAME_LEN + 1];
	
	/* Description of the Offline Identity Establishment component. */
	wchar_t mstrDesc[MAX_OFFLINE_COMP_DESC_LEN + 1];	
	
	/* Version of the Offline Identity Establishment component. */
	wchar_t mstrVersion[MAX_OFFLINE_COMP_VER_LEN + 1];

	/* Install Path of the Offline Identity Establishment component interface. */
	wchar_t mstrInstallDir[MAX_PATH + 1];

	/* 
	Options.
	It can have combination of following values:
		- OPTION_MASK_INTERACTIVE
		- OPTION_MASK_NONINTERACTIVE
		- OPTION_UNMASK_INTERACTIVE
		- OPTION_UNMASK_NONINTERACTIVE
	*/
	DWORD mlOptions;


	/* Path of the X64 library (DLL) which implements Offline Identity Establishment component interface. */
	wchar_t mstrPath64[MAX_PATH + 1];

	DWORD mlPackageOptions;					//CHANGE#24666_SHUBHAM

	OfflineCompConfigW mOfflineCompConfig;	//CHANGE#ETM24666_25625_SHUBHAM

} OfflineIdEstCompInfoW;

typedef struct _sOfflineIdEstCompInfoA
{
	/* Size of the structure. */
	DWORD mlSize;
	
	/* Identifier of the Offline Identity Establishment component. */
	char mstrId[MAX_OFFLINE_COMP_ID_LEN + 1];
	
	/* Path of the Win32 library (DLL) which implements Offline Identity Establishment component interface. */
	char mstrPath[MAX_PATH + 1];
	
	/* Name of the Offline Identity Establishment component. */
	char mstrName[MAX_OFFLINE_COMP_NAME_LEN + 1];
	
	/* Description of the Offline Identity Establishment component. */
	char mstrDesc[MAX_OFFLINE_COMP_DESC_LEN + 1];	
	
	/* Version of the Offline Identity Establishment component. */
	char mstrVersion[MAX_OFFLINE_COMP_VER_LEN + 1];

	/* Install Path of the Offline Identity Establishment component interface. */
	char mstrInstallDir[MAX_PATH + 1];

	/* 
	Options.
	It can have combination of following values:
		- OPTION_MASK_INTERACTIVE
		- OPTION_MASK_NONINTERACTIVE
		- OPTION_UNMASK_INTERACTIVE
		- OPTION_UNMASK_NONINTERACTIVE
	*/
	DWORD mlOptions;


	/* Path of the x64 library (DLL) which implements Offline Identity Establishment component interface. */
	char mstrPath64[MAX_PATH + 1];

	DWORD mlPackageOptions;					//CHANGE#24666_SHUBHAM

	OfflineCompConfigA mOfflineCompConfig;	//CHANGE#ETM24666_25625_SHUBHAM

} OfflineIdEstCompInfoA;

//CHANGE#24666_SHUBHAM - STARTS
#define OFFLINE_ID_EST_COMP_INFOW_VER3		sizeof(OfflineIdEstCompInfoW)
#define OFFLINE_ID_EST_COMP_INFOA_VER3		sizeof(OfflineIdEstCompInfoA)

#define OFFLINE_ID_EST_COMP_INFOW_VER2		((OFFLINE_ID_EST_COMP_INFOW_VER3) - (sizeof(DWORD) + OFFLINE_COMP_CONFIGW_VER1_SIZE))
#define OFFLINE_ID_EST_COMP_INFOA_VER2		((OFFLINE_ID_EST_COMP_INFOA_VER3) - (sizeof(DWORD) + OFFLINE_COMP_CONFIGA_VER1_SIZE))
//CHANGE#24666_SHUBHAM - ENDS

#define OFFLINE_ID_EST_COMP_INFOW_VER1		((OFFLINE_ID_EST_COMP_INFOW_VER2) - (sizeof(wchar_t) * ((MAX_PATH) + 1)))
#define OFFLINE_ID_EST_COMP_INFOA_VER1		((OFFLINE_ID_EST_COMP_INFOA_VER2) - (sizeof(char) * ((MAX_PATH) + 1)))



#endif // #define STRUCT_OFFLINE_COMPONENT


typedef struct _sFSEventHandlerCompW
{
	/* Size of the structure. */
	DWORD mlSize;
	
	/* Identifier of the FS Event handler component. */
	wchar_t mstrId[MAX_FSEVENT_COMP_ID_LEN + 1];
	
	/* Path of the Win32 library (DLL) which implements FS Event gandler component interface. */
	wchar_t mstrPath[MAX_PATH + 1];
	
	/* Name of the FS Event handler component. */
	wchar_t mstrName[MAX_FSEVENT_COMP_NAME_LEN + 1];
	
	/* Description of the FS Event handler component. */
	wchar_t mstrDesc[MAX_FSEVENT_COMP_DESC_LEN + 1];	
	
	/* Version of the FS Event handler component. */
	wchar_t mstrVersion[MAX_FSEVENT_COMP_VER_LEN + 1];

	/* Install Path of the FS Event handler component. */
	wchar_t mstrInstallDir[MAX_PATH + 1];

} FSEventHandlerCompW;

typedef struct _sFSEventHandlerCompA
{
	/* Size of the structure. */
	DWORD mlSize;
	
	/* Identifier of the FS Event handler component. */
	char mstrId[MAX_FSEVENT_COMP_ID_LEN + 1];
	
	/* Path of the Win32 library (DLL) which implements FS Event gandler component interface. */
	char mstrPath[MAX_PATH + 1];
	
	/* Name of the FS Event handler component. */
	char mstrName[MAX_FSEVENT_COMP_NAME_LEN + 1];
	
	/* Description of the FS Event handler component. */
	char mstrDesc[MAX_FSEVENT_COMP_DESC_LEN + 1];	
	
	/* Version of the FS Event handler component. */
	char mstrVersion[MAX_FSEVENT_COMP_VER_LEN + 1];

	/* Install Path of the FS Event handler component. */
	char mstrInstallDir[MAX_PATH + 1];

} FSEventHandlerCompA;

// --------------------------- Macros for generic type

#ifdef UNICODE

#define COMPONENTINFOEX_SIZE_VER_1			COMPONENTINFOEXW_SIZE_VER_1

#define SUBCOMPONENTINFO_SIZE_VER_1			SUBCOMPONENTINFOW_SIZE_VER_1

#define FILETYPEVERB_SIZE_VER_1				FILETYPEVERBW_SIZE_VER_1

#define FILETYPE_SIZE_VER_1					FILETYPEW_SIZE_VER_1
#define FILETYPE_SIZE_VER_2					FILETYPEW_SIZE_VER_2  // CHANGE#4282

#define SHELLEX_SIZE_VER_1					SHELLEXW_SIZE_VER_1   // CHANGE#4282

#define CUSTOMEDITOR_SIZE_VER_1				CUSTOMEDITORW_SIZE_VER_1
#define CUSTOMEDITOR_SIZE_VER_2				CUSTOMEDITORW_SIZE_VER_2


#define OFFLINE_ID_EST_COMP_INFO_VER1		OFFLINE_ID_EST_COMP_INFOW_VER1
#define OFFLINE_ID_EST_COMP_INFO_VER2		OFFLINE_ID_EST_COMP_INFOW_VER2
#define OFFLINE_ID_EST_COMP_INFO_VER3		OFFLINE_ID_EST_COMP_INFOW_VER3				//CHANGE#24666_SHUBHAM

#define OFFLINE_COMP_CONFIG_VER1_SIZE		OFFLINE_COMP_CONFIGW_VER1_SIZE				//CHANGE#ETM24666_25625_SHUBHAM

#define ComponentInfoEx						ComponentInfoExW
#define ComponentInfo						ComponentInfoW
#define SubComponentInfo					SubComponentInfoW
#define FileTypeVerb						FileTypeVerbW
#define FileType							FileTypeW
#define CustomEditor						CustomEditorW
#define OfflineIdEstCompInfo				OfflineIdEstCompInfoW
#define OfflineCompConfig					OfflineCompConfigW							//CHANGE#ETM24666_25625_SHUBHAM

#define FSEventHandlerComp					FSEventHandlerCompW
#define ShellEx								ShellExW       // CHANGE#4282


#ifdef __SETUPHELPER_COMPILETIME_LINK__

#define IRegisterComponent					IRegisterComponentW
#define IRegisterComponentEx				IRegisterComponentExW
#define IUnregisterComponent				IUnregisterComponentW
#define IRegisterSubComponent				IRegisterSubComponentW
#define IUnregisterSubComponent				IUnregisterSubComponentW
#define IGetInstallationBasePath			IGetInstallationBasePathW
#define	IGetComponentInfoEx					IGetComponentInfoExW
#define	IGetComponentInfo					IGetComponentInfoW
#define IGetSubComponentInfo				IGetSubComponentInfoW
#define IUpgradeComponent					IUpgradeComponentW
#define IRegisterFileType					IRegisterFileTypeW
#define IUnregisterFileType					IUnregisterFileTypeW
#define IAddVerb							IAddVerbW
#define IRemoveVerb							IRemoveVerbW
#define IRegisterCustomEditor				IRegisterCustomEditorW
#define IUnregisterCustomEditor				IUnregisterCustomEditorW
#define IIsFileTypeRegistered				IIsFileTypeRegisteredW
#define IIsCustomEditorRegistered			IIsCustomEditorRegisteredW
#define IIsVerbPresent						IIsVerbPresentW
#define ICreateShortcut						ICreateShortcutW

#define ILoadResourceSection				ILoadResourceSectionW
#define IGetStringByString					IGetStringByStringW
#define IGetStringByNumber					IGetStringByNumberW
#define IGetInstalledLocale					IGetInstalledLocaleW

#define IRegisterFSEventHandlerComp			IRegisterFSEventHandlerCompW
#define IUnregisterFSEventHandlerComp		IUnregisterFSEventHandlerCompW
#define IGetFSEventHandlerCompInfo			IGetFSEventHandlerCompInfoW

#endif // #ifdef __SETUPHELPER_COMPILETIME_LINK__

#else

#define COMPONENTINFOEX_SIZE_VER_1			COMPONENTINFOEXA_SIZE_VER_1

#define SUBCOMPONENTINFO_SIZE_VER_1			SUBCOMPONENTINFOA_SIZE_VER_1

#define FILETYPEVERB_SIZE_VER_1				FILETYPEVERBA_SIZE_VER_1

#define FILETYPE_SIZE_VER_1					FILETYPEA_SIZE_VER_1
#define FILETYPE_SIZE_VER_2					FILETYPEA_SIZE_VER_2 // CHANGE#4282

#define SHELLEX_SIZE_VER_1					SHELLEXA_SIZE_VER_1   // CHANGE#4282

#define CUSTOMEDITOR_SIZE_VER_1				CUSTOMEDITORA_SIZE_VER_1
#define CUSTOMEDITOR_SIZE_VER_2				CUSTOMEDITORA_SIZE_VER_2


#define OFFLINE_ID_EST_COMP_INFO_VER1		OFFLINE_ID_EST_COMP_INFOA_VER1
#define OFFLINE_ID_EST_COMP_INFO_VER2		OFFLINE_ID_EST_COMP_INFOA_VER2
#define OFFLINE_ID_EST_COMP_INFO_VER3		OFFLINE_ID_EST_COMP_INFOA_VER3		//CHANGE#ETM24666_25189_SHUBHAM_1


#define ComponentInfoEx						ComponentInfoExA
#define ComponentInfo						ComponentInfoA
#define SubComponentInfo					SubComponentInfoA
#define FileTypeVerb						FileTypeVerbA
#define FileType							FileTypeA
#define CustomEditor						CustomEditorA
#define OfflineIdEstCompInfo				OfflineIdEstCompInfoA

#define FSEventHandlerComp					FSEventHandlerCompA


#ifdef __SETUPHELPER_COMPILETIME_LINK__

#define IRegisterComponent					IRegisterComponentA
#define IRegisterComponentEx				IRegisterComponentExA
#define IUnregisterComponent				IUnregisterComponentA
#define IRegisterSubComponent				IRegisterSubComponentA
#define IUnregisterSubComponent				IUnregisterSubComponentA
#define IGetInstallationBasePath			IGetInstallationBasePathA
#define	IGetComponentInfoEx					IGetComponentInfoExA
#define	IGetComponentInfo					IGetComponentInfoA
#define IGetSubComponentInfo				IGetSubComponentInfoA
#define IUpgradeComponent					IUpgradeComponentA
#define IRegisterFileType					IRegisterFileTypeA
#define IUnregisterFileType					IUnregisterFileTypeA
#define IAddVerb							IAddVerbA
#define IRemoveVerb							IRemoveVerbA
#define IRegisterCustomEditor				IRegisterCustomEditorA
#define IUnregisterCustomEditor				IUnregisterCustomEditorA
#define IIsFileTypeRegistered				IIsFileTypeRegisteredA
#define IIsCustomEditorRegistered			IIsCustomEditorRegisteredA
#define IIsVerbPresent						IIsVerbPresentA
#define ICreateShortcut						ICreateShortcutA

#define IRegisterFSEventHandlerComp			IRegisterFSEventHandlerCompA
#define IUnregisterFSEventHandlerComp		IUnregisterFSEventHandlerCompA
#define IGetFSEventHandlerCompInfo			IGetFSEventHandlerCompInfoA
#define ShellEx								ShellExA		// CHANGE#4282

#endif // #ifdef __SETUPHELPER_COMPILETIME_LINK__

#endif

// --------------------------- API Types

#ifdef UNICODE

typedef long (* IRegisterComponentExW_type)(	
	/* [in] */ ComponentInfoExW * pComponentInfoExW,
	/* [out] */ wchar_t * pstrError);

typedef long (* IRegisterComponentW_type)(	
	/* [in] */ ComponentInfoW * pComponentInfoW,
	/* [out] */ wchar_t * pstrError);

typedef long (* IUnregisterComponentW_type)(
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);

typedef long (* IRegisterSubComponentW_type) (
	/* [in] */ wchar_t * pstrComponentId,
	/* [in] */ SubComponentInfoW * pSubComponentInfo,
	/* [out] */ wchar_t * pstrError);

typedef long (* IUnregisterSubComponentW_type) (
	/* [in] */ wchar_t * pstrComponentId,
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);

typedef long (* IGetInstallationBasePathW_type)(	
	/*[in]*/ ComponentType pComponentType, 
	/*[out]*/ wchar_t * pstrInstallPath,
	/*[out]*/ wchar_t * pstrError) ;

typedef long (* IGetComponentInfoExW_type) (	
	/* [in,out] */ ComponentInfoExW * pComponentInfoEx,
	/* [out] */ wchar_t * pstrError);

typedef long (* IGetComponentInfoW_type)(	
	/* [in,out] */ ComponentInfoW * pComponentInfoW,
	/* [out] */ wchar_t * pstrError);

typedef long (* IGetSubComponentInfoW_type) (	
	/* [in] */ wchar_t * pstrComponentId,
	/* [in,out] */ SubComponentInfoW * pSubComponentInfo,
	/* [out] */ wchar_t * pstrError);

typedef long (* IUpgradeComponentW_type)(	
	/* [in] */ wchar_t * pstrProxyServer,
	/* [in] */ wchar_t * pstrProxyPort,
	/* [in] */ wchar_t * pstrProxyUser,
	/* [in] */ wchar_t * pstrProxyPassword,
	/* [in] */ wchar_t * pstrId,
	/* [in] */ bool pbUpgradeCore,
	/* [out] */ wchar_t * pstrError);

typedef long (* IRegisterFileTypeW_type) (
	/* [in] */ FileTypeW * pFileType, 
	/* [out] */ wchar_t * pstrError);

typedef long (* IUnregisterFileTypeW_type) (
	/* [in] */ FileTypeW * pFileType, 
	/* [out] */ wchar_t * pstrError);

typedef long (* IAddVerbW_type) (
	/* [in] */ wchar_t * pstrFileType,
	/* [in] */ FileTypeVerbW * pVerb, 
	/* [out] */ wchar_t * pstrError);

typedef long (* IRemoveVerbW_type) (
	/* [in] */ wchar_t * pstrFileType,
	/* [in] */ FileTypeVerbW * pVerb, 
	/* [out] */ wchar_t * pstrError);

typedef long (* IRegisterCustomEditorW_type) (
	/* [in] */ wchar_t * pstrExt,
	/* [in] */ CustomEditorW * pCustomEditor,
	/* [out] */ wchar_t * pstrError);

typedef long (* IUnregisterCustomEditorW_type) (
	/* [in] */ wchar_t * pstrExt,
	/* [in] */ CustomEditorW * pCustomEditor,
	/* [out] */ wchar_t * pstrError);

typedef bool (* IIsFileTypeRegisteredW_type) (
	/* [in] */ wchar_t * pstrFileType);

typedef bool (* IIsCustomEditorRegisteredW_type) (
	/* [in] */ wchar_t * pstrExt, 
	/* [in] */ wchar_t * pstrEditor);

typedef bool (* IIsVerbPresentW_type) (
	/* [in] */ wchar_t * pstrFileType, 
	/* [in] */ wchar_t * pstrVerb);

typedef long (*ILoadResourceSectionW_type) (
	/* [in] */ wchar_t * pstrSectionName,
	/* [in,opt] */ wchar_t * pstrResCollPathLang,
	/* [in,opt] */ wchar_t * pstrResCollPathDef,
	/* [out] */ wchar_t * pstrError);

typedef void (*IGetStringByStringW_type) (
	/* [in] */ wchar_t * pstrId,
	/* [out, opt] */ wchar_t * pstrStringLang,
	/* [out, opt] */ wchar_t * pstrStringDef,
	...);

typedef void (*IGetStringByNumberW_type) (
	/* [in] */ long plId,
	/* [out, opt] */ wchar_t * pstrStringLang,
	/* [out, opt] */ wchar_t * pstrStringDef,
	...);

typedef long (* IGetInstalledLocaleW_type) (
	/* [out] */ wchar_t * pstrLocale,
	/* [out] */ bool * pbDefault,
	/* [out] */ wchar_t * pstrError);

typedef long ( * IRegisterOffIdEstComponentW_type)(	
	/* [in] */ OfflineIdEstCompInfoW * pOfflineIdEstCompInfo,
	/* [out] */ wchar_t * pstrError);

typedef long ( * IUnregisterOffIdEstComponentW_type)(	
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);

typedef long ( * IGetOffIdEstComponentInfoW_type)(	
	/* [in,out] */ OfflineIdEstCompInfoW * pOfflineIdEstCompInfo,
	/* [out] */ wchar_t * pstrError);

typedef long ( * ICreateShortcutW_type)(
	/* [in] */ wchar_t * pstrTarget,
	/* [in] */ wchar_t * pstrLinkPath,
	/* [in,opt] */ wchar_t * pstrIconPath,
	/* [in,opt] */ int piIconIndex,
	/* [in,opt] */ wchar_t * pstrDescription,
	/* [in,opt] */ wchar_t * pstrArguments,
	/* [out] */ wchar_t * pstrError);


typedef long (* IGetFSEventHandlerCompInfoW_type)(
	/* [in, out] */ FSEventHandlerCompW * pFSEventHandlerComp,
	/* [out] */ wchar_t * pstrError);

typedef long (* IRegisterFSEventHandlerCompW_type)(
	/* [in, out] */ FSEventHandlerCompW * pFSEventHandlerComp,
	/* [out] */ wchar_t * pstrError);

typedef long (* IUnregisterFSEventHandlerCompW_type)(
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);


#else

typedef long (* IRegisterComponentExA_type)(	
	/* [in] */ ComponentInfoExA * pComponentInfoExA,
	/* [out] */ char * pstrError);

typedef long (* IRegisterComponentA_type)(	
	/* [in] */ ComponentInfoA * pComponentInfoW,
	/* [out] */ char * pstrError);

typedef long (* IUnregisterComponentA_type)(
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);

typedef long (* IRegisterSubComponentA_type) (
	/* [in] */ char * pstrComponentId,
	/* [in] */ SubComponentInfoA * pSubComponentInfoA,
	/* [out] */ char * pstrError);

typedef long (* IUnregisterSubComponentA_type) (
	/* [in] */ char * pstrComponentId,
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);

typedef long (* IGetInstallationBasePathA_type)(	
	/*[in]*/ ComponentType pComponentType, 
	/*[out]*/ char * pstrInstallPath,
	/*[in]*/ char * pstrError) ;

typedef long (* IGetComponentInfoExA_type) (	
	/* [in,out] */ ComponentInfoExA * pComponentInfoEx,
	/* [out] */ char * pstrError);

typedef long (* IGetComponentInfoA_type)(
	/* [in,out] */ ComponentInfoA * pComponentInfo,
	/* [out] */ char * pstrError);

typedef long (* IGetSubComponentInfoA_type) (	
	/* [in] */ char * pstrComponentId,
	/* [in,out] */ SubComponentInfoA * pSubComponentInfo,
	/* [out] */ char * pstrError);

typedef long (* IUpgradeComponentA_type)(	
	/* [in] */ char * pstrProxyServer,
	/* [in] */ char * pstrProxyPort,
	/* [in] */ char * pstrProxyUser,
	/* [in] */ char * pstrProxyPassword,
	/* [in] */ char * pstrId,
	/* [in] */ bool pbUpgradeCore,
	/* [out] */ char * pstrError);

typedef long (* IRegisterFileTypeA_type) (
	/* [in] */ FileTypeA * pFileType, 
	/* [out] */ char * pstrError);

typedef long (* IUnregisterFileTypeA_type) (
	/* [in] */ FileTypeA * pFileType, 
	/* [out] */ char * pstrError);

typedef long (* IAddVerbA_type) (
	/* [in] */ char * pstrFileType,
	/* [in] */ FileTypeVerbA * pVerb, 
	/* [out] */ char * pstrError);

typedef long (* IRemoveVerbA_type) (
	/* [in] */ char * pstrFileType,
	/* [in] */ FileTypeVerbA * pVerb, 
	/* [out] */ char * pstrError);

typedef long (* IRegisterCustomEditorA_type) (
	/* [in] */ char * pstrExt,
	/* [in] */ CustomEditorA * pCustomEditor,
	/* [out] */ char * pstrError);

typedef long (* IUnregisterCustomEditorA_type) (
	/* [in] */ char * pstrExt,
	/* [in] */ CustomEditorA * pCustomEditor,
	/* [out] */ char * pstrError);

typedef bool (* IIsFileTypeRegisteredA_type) (
	/* [in] */ char * pstrFileType);

typedef bool (* IIsFileTypeRegisteredA_type) (
	/* [in] */ char * pstrFileType);

typedef bool (* IIsCustomEditorRegisteredA_type) (
	/* [in] */ char * pstrExt, 
	/* [in] */ char * pstrEditor);

typedef bool (* IIsVerbPresentA_type) (
	/* [in] */ char * pstrFileType, 
	/* [in] */ char * pstrVerb);

typedef long ( * IRegisterOffIdEstComponentA_type)(	
	/* [in] */ OfflineIdEstCompInfoW * pOfflineIdEstCompInfo,
	/* [out] */ char * pstrError);

typedef long ( * IUnregisterOffIdEstComponentA_type)(	
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);

typedef long ( * IGetOffIdEstComponentInfoA_type)(	
	/* [in,out] */ OfflineIdEstCompInfoW * pOfflineIdEstCompInfo,
	/* [out] */ char * pstrError);

typedef long ( * ICreateShortcutA_type)(
	/* [in] */ char * pstrTarget,
	/* [in] */ char * pstrLinkPath,
	/* [in,opt] */ char * pstrIconPath,
	/* [in,opt] */ int piIconIndex,
	/* [in,opt] */ char * pstrDescription,
	/* [in,opt] */ char * pstrArguments,
	/* [out] */ char * pstrError);


typedef long (* IGetFSEventHandlerCompInfoA_type)(
	/* [in, out] */ FSEventHandlerCompA * pFSEventHandlerComp,
	/* [out] */ char * pstrError);

typedef long (* IRegisterFSEventHandlerCompA_type)(
	/* [in, out] */ FSEventHandlerCompA * pFSEventHandlerComp,
	/* [out] */ char * pstrError);

typedef long (* IUnregisterFSEventHandlerCompA_type)(
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);


#endif

#ifdef __SETUPHELPER_COMPILETIME_LINK__

// --------------------------- APIs

/*
	This function will register component for auto upgrade. 
	Function need to be called while installing the component.

	Parameters: 
		pComponentInfoEx: 
			Details of component.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/

long FSSETUPHELPER_API IRegisterComponentExW(	
	/* [in] */ ComponentInfoExW * pComponentInfoEx,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IRegisterComponentExA(	
	/* [in] */ ComponentInfoExA * pComponentInfoEx,
	/* [out] */ char * pstrError);

/*
	This function will register component for auto upgrade. 
	Function need to be called while installing the component.

	Parameters: 
		pComponentInfo: 
			Details of component.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/

long FSSETUPHELPER_API IRegisterComponentW(	
	/* [in] */ ComponentInfoW * pComponentInfo,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IRegisterComponentA(	
	/* [in] */ ComponentInfoA * pComponentInfo,
	/* [out] */ char * pstrError);

/*
	This function will register offline id establishment component. 
	Function need to be called while installing the component.

	Parameters: 
		pOfflineIdEstCompInfo: 
			Details of component.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/

long FSSETUPHELPER_API IRegisterOffIdEstComponentW(	
	/* [in] */ OfflineIdEstCompInfoW * pOfflineIdEstCompInfo,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IRegisterOffIdEstComponentA(	
	/* [in] */ OfflineIdEstCompInfoA * pOfflineIdEstCompInfo,
	/* [out] */ char * pstrError);


/*
	This function will unregister offline component. 
	Function need to be called while uninstalling the component.

	Parameters: 
		pstrId: 
			Unique Identifier for the offline component.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IUnregisterOffIdEstComponentW(	
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IUnregisterOffIdEstComponentA(	
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);

/* This function will return offline component info depending on passed component 
	identifier.
	Parameters: 
		pOfflineIdEstCompInfo: 
			Pass unique Identifier for the offline component and all other details will 
			be returned.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IGetOffIdEstComponentInfoW(	
	/* [in,out] */ OfflineIdEstCompInfoW * pOfflineIdEstCompInfo,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IGetOffIdEstComponentInfoA(	
	/* [in,out] */ OfflineIdEstCompInfoA * pOfflineIdEstCompInfo,
	/* [out] */ char * pstrError);

/*
	This function will unregister component for auto upgrade. 
	Function need to be called while uninstalling the component.

	Parameters: 
		pstrId: 
			Unique Identifier for the component. This should be same as passed 
			while installation.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IUnregisterComponentW(	
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IUnregisterComponentA(	
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);

/*
	This function will registers sub-component for auto upgrade. 
	Function need to be called while installing the component.

	Parameters: 
		pstrComponentId:
			Identifier of the parent component.
		pSubComponentInfo: 
			Details of sub-component.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/

long FSSETUPHELPER_API IRegisterSubComponentW(
	/* [in] */ wchar_t * pstrComponentId,
	/* [in] */ SubComponentInfoW * pSubComponentInfo,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IRegisterSubComponentA(	
	/* [in] */ char * pstrComponentId,
	/* [in] */ SubComponentInfoA * pSubComponentInfo,
	/* [out] */ char * pstrError);

/*
	This function will unregister component for auto upgrade. 
	Function need to be called while uninstalling the component.

	Parameters: 
		pstrComponentId:
			Identifier of the parent component.
		pstrId: 
			Unique Identifier for the sub-component. This should be same as 
			passed while installation.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IUnregisterSubComponentW(
	/* [in] */ wchar_t * pstrComponentId,
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IUnregisterSubComponentA(	
	/* [in] */ char * pstrComponentId,
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);

/*
	This function will return base installation path for plugin for installation.

	Parameters : 
		pComponentType: 
			Type of component.
		pstrInstallPath: 
			Required installation path.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return :
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark :
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IGetInstallationBasePathW(	
	/* [in] */ ComponentType pComponentType, 
	/* [out] */ wchar_t * pstrInstallPath,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IGetInstallationBasePathA(	
	/* [in] */ ComponentType pComponentType, 
	/* [out] */ char * pstrInstallPath,
	/* [out] */ char * pstrError);

/*
	This function will return component info depending on passed component 
	identifier.

	Parameters: 
		pComponentInfo: 
			Pass unique Identifier for the component and all other details will 
			be returned.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IGetComponentInfoExW(	
	/* [in,out] */ ComponentInfoExW * pComponentInfoEx,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IGetComponentInfoExA(	
	/* [in,out] */ ComponentInfoExA * pComponentInfoEx,
	/* [out] */ char * pstrError);

long FSSETUPHELPER_API IGetComponentInfoW(	
	/* [in,out] */ ComponentInfoW * pComponentInfo,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IGetComponentInfoA(	
	/* [in,out] */ ComponentInfoA * pComponentInfo,
	/* [out] */ char * pstrError);

/*
	This function will return sub-component info depending on passed component 
	identifier.

	Parameters: 
		pstrComponentId
			Identifier of the parent component.
		pSubComponentInfoEx: 
			Pass unique Identifier for the sub-component and all other details 
			will be returned.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IGetSubComponentInfoW(	
	/* [in] */ wchar_t * pstrComponentId,
	/* [in,out] */ SubComponentInfoW * pSubComponentInfo,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IGetSubComponentInfoA(	
	/* [in] */ char * pstrComponentId,
	/* [in,out] */ SubComponentInfoA * pSubComponentInfo,
	/* [out] */ char * pstrError);

/*
	This function upgrades the component passed as parameter. 

	Parameters : 
		pstrProxyServer: 
			Proxy server address, in case proxy is required to connect to the 
			upgrade URL.
		pstrPort: 
			Proxy server port, in case proxy is required to connect to the 
			upgrade URL.
		pstrUserName: 
			Proxy server username, in case proxy is required to connect to the 
			upgrade URL.
		pstrPassword: 
			Proxy server password, in case proxy is required to connect to the 
			upgrade URL
		pstrId: 
			Pass unique Identifier for the component, which needs to be upgraded.
			In case this value is NULL, all components are upgraded.
		pbUpgradeCore: 
			If the core component of Desktop Client needs to be upgraded with 
			the passed component, pass this value as true.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Return SETUP_SUCCESS in case of success. Return negative number in case 
		of error and error message will be returned in pstrError

*/
long FSSETUPHELPER_API IUpgradeComponentW(	
	/* [in] */ wchar_t * pstrProxyServer,
	/* [in] */ wchar_t * pstrProxyPort,
	/* [in] */ wchar_t * pstrProxyUser,
	/* [in] */ wchar_t * pstrProxyPassword,
	/* [in] */ wchar_t * pstrId,
	/* [in] */ bool pbUpgradeCore,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IUpgradeComponentA(
	/* [in] */ char * pstrProxyServer,
	/* [in] */ char * pstrProxyPort,
	/* [in] */ char * pstrProxyUser,
	/* [in] */ char * pstrProxyPassword,
	/* [in] */ char * pstrId,
	/* [in] */ bool pbUpgradeCore,
	/* [out] */ char * pstrError);

/*
	Registers new File Type (Class) or ProgId which handles file actions.

	This method can be used by developer of Custom Editor/Viewer to register
	new File Type (Class) so files which are associated with new File Type 
	can be opened in new Custom Edtior/Viewer using standard way of open files,
	like double click of file.

	Parameters:
		pFileType:
			File Type (Class) details.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API IRegisterFileTypeW(
	/* [in] */ FileTypeW * pFileType, 
	/* [out] */ wchar_t * pstrError);
long FSSETUPHELPER_API IRegisterFileTypeA(
	/* [in] */ FileTypeA * pFileType, 
	/* [out] */ char * pstrError);

/*
	Unregisters File Type (Class) or ProgId.

	Parameters:
		pFileType:
			File Type (Class) details.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API IUnregisterFileTypeW(
	/* [in] */ FileTypeW * pFileType, 
	/* [out] */ wchar_t * pstrError);
long FSSETUPHELPER_API IUnregisterFileTypeA(
	/* [in] */ FileTypeA * pFileType, 
	/* [out] */ char * pstrError);

/*
	Adds given verb to given File Type.

	This method can be used to add new verb/action if any of the existing 
	verb/action does not fulfill requirements to open the protected file
	in handler editor/application. This verb should be specified while 
	registering Custome Edtior using IRegisterCustomEditor() API so protected
	file are opened using newly added verb.

	Parameters:
		pstrFileType: 
			Identifier of the File Type (Class).
		pVerb:
			Details of the verb to be added.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API IAddVerbW(
	/* [in] */ wchar_t * pstrFileType,
	/* [in] */ FileTypeVerbW * pVerb, 
	/* [out] */ wchar_t * pstrError);
long FSSETUPHELPER_API IAddVerbA(
	/* [in] */ wchar_t * pstrFileType,
	/* [in] */ FileTypeVerbA * pVerb, 
	/* [out] */ char * pstrError);

/*
	Removes given verb from given File Type.

	This method can be used to register Custom Editor/Viewer with Seclore 
	Seclore so user can choose this Custom Editor/Viewer
	to open protected files.

	Parameters:
		pstrFileType: 
			Identifier of the File Type (Class).
		pVerb:
			Details of the verb to be removed.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API IRemoveVerbW(
	/* [in] */ wchar_t * pstrFileType,
	/* [in] */ FileTypeVerbW * pVerb, 
	/* [out] */ wchar_t * pstrError);
long FSSETUPHELPER_API IRemoveVerbA(
	/* [in] */ wchar_t * pstrFileType,
	/* [in] */ FileTypeVerbA * pVerb, 
	/* [out] */ char * pstrError);

/*
	Registers new Custom Editor.

	Parameters:
		pstrExt:
			File extension.
		pCustomEditor:
			Details of Custom Editors.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API IRegisterCustomEditorW(
	/* [in] */ wchar_t * pstrExt,
	/* [in] */ CustomEditorW * pCustomEditor,
	/* [out] */ wchar_t * pstrError);
long FSSETUPHELPER_API IRegisterCustomEditorA(
	/* [in] */ char * pstrExt,
	/* [in] */ CustomEditorA * pCustomEditor,
	/* [out] */ char * pstrError);

/*
	Unregisters new Custom Editor.

	Parameters:
		pstrExt:
			File extension.
		pCustomEditor:
			Details of Custom Editors.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API IUnregisterCustomEditorW(
	/* [in] */ wchar_t * pstrExt,
	/* [in] */ CustomEditorW * pCustomEditor,
	/* [out] */ wchar_t * pstrError);
long FSSETUPHELPER_API IUnregisterCustomEditorA(
	/* [in] */ char * pstrExt,
	/* [in] */ CustomEditorA * pCustomEditor,
	/* [out] */ char * pstrError);

/*
	Checks whether a FileType is registered

	Parameters:
		pstrFileType:
			File type to be queried for.

	Returns:
		Returns true if File type is registered, else false. 
*/
bool FSSETUPHELPER_API IIsFileTypeRegisteredW(
	/* [in] */ wchar_t * pstrFileType);
bool FSSETUPHELPER_API IIsFileTypeRegisteredA(
	/* [in] */ char * pstrFileType);

/*
	Checks whether a Custom Editor is registered for an extention.

	Parameters:
		pstrExt:
			Extention for which custom editor entry is to be queried for.
		pstrEditor:
			Custom editor to be queried for.

	Returns:
		Returns true if custom editor is registered, else false. 
*/
bool FSSETUPHELPER_API IIsCustomEditorRegisteredW(
	/* [in] */ wchar_t * pstrExt, 
	/* [in] */ wchar_t * pstrEditor);
bool FSSETUPHELPER_API IIsCustomEditorRegisteredA(
	/* [in] */ char * pstrExt, 
	/* [in] */ char * pstrEditor);

/*
	Checks whether a verb is present for a file type

	Parameters:
		pstrExt:
			File type for which verb entry is to be queried for.
		pstrVerb:
			Verb to be queried for.

	Returns:
		Returns true if verb is present, else false. 
*/
bool FSSETUPHELPER_API IIsVerbPresentW(
	/* [in] */ wchar_t * pstrFileType, 
	/* [in] */ wchar_t * pstrVerb);
bool FSSETUPHELPER_API IIsVerbPresentA(
	/* [in] */ char * pstrFileType, 
	/* [in] */ char * pstrVerb);

/*
	Parameters

		pstrSectionName
			Name of the section.
		pstrResCollPathLang
			Path of resource collection file for installed language.
		pstrResCollPathDef
			Path of resource collection file for default language.
		pstrError
			Buffer to receive error message.

	Return Value

		This method returns FSDC_SUCCESS if given section is loaded successfully, 
		else return -ve value.
		
	Description

		Loads given section from given resource collection file.

*/
long FSSETUPHELPER_API ILoadResourceSectionW (
	/* [in] */ wchar_t * pstrSectionName,
	/* [in,opt] */ wchar_t * pstrResCollPathLang,
	/* [in,opt] */ wchar_t * pstrResCollPathDef,
	/* [out] */ wchar_t * pstrError);

/*
	Parameters

		pstrId/plId
			Identifier of the resource/string.
		pstrStringLang
			Buffer to receive language specific string. It must be enough to 
			store ERROR_MSG_MAX_LEN characters excluding terminating null 
			character.
		pstrStringDef
			Buffer to receive string in default language. It must be enough to 
			store ERROR_MSG_MAX_LEN characters excluding terminating null 
			character.
		...
			The string can be pattern/format as used in printf() function. User 
			can pass arguments to this method to get formatted/final message.

	Return Value

		Returns true if resource/string with given resource is found.
		
	Description

		Returns formatted string identified by given identifer.

*/
void FSSETUPHELPER_API IGetStringByStringW (
	/* [in] */ wchar_t * pstrId,
	/* [out, opt] */ wchar_t * pstrStringLang,
	/* [out, opt] */ wchar_t * pstrStringDef,
	...);
void FSSETUPHELPER_API IGetStringByNumberW (
	/* [in] */ long plId,
	/* [out, opt] */ wchar_t * pstrStringLang,
	/* [out, opt] */ wchar_t * pstrStringDef,
	...);

/*
	Returns installed locale for Seclore.

	Parameters:
		pstrLocale:
			Buffer to receive installed locale. It should be large enough to 
			store MAX_LOCALE_LEN excluding terminating null character.
		pbDefault:
			Whether installed locale is also default locale or not.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API IGetInstalledLocaleW(
	/* [out] */ wchar_t * pstrLocale,
	/* [out] */ bool * pbDefault,
	/* [out] */ wchar_t * pstrError);

/*
	Creates a shortcut of given file.

	Parameters:
		pstrTarget:
			Path of the file for which shortcut needs to be created. This path 
			should not be longer than MAX_PATH excluding terminating NULL character.
		pstrLinkPath:
			Path of the shortcut file. This path should not be longer than 
			MAX_PATH excluding terminating NULL character.
		pstrIconPath:
			Optional. Path of file containng icon of shortcut. This path should 
			not be longer than MAX_PATH excluding terminating NULL character.
		piIconIndex:
			Optional. Index of the icon of shortcut in the icon file.
		pstrDescription:
			Optional. Description of the shortcut.
		pstrArguments:
			Optional. Arguments to pstrTarget.
		pstrError:
			Buffer to receive error message in case of failure.

	Returns:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and fills error message in 
		pstrError.
*/
long FSSETUPHELPER_API ICreateShortcutW(
	/* [in] */ wchar_t * pstrTarget,
	/* [in] */ wchar_t * pstrLinkPath,
	/* [in,opt] */ wchar_t * pstrIconPath,
	/* [in,opt] */ int piIconIndex,
	/* [in,opt] */ wchar_t * pstrDescription,
	/* [in,opt] */ wchar_t * pstrArguments,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API ICreateShortcutA(
	/* [in] */ char * pstrTarget,
	/* [in] */ char * pstrLinkPath,
	/* [in,opt] */ char * pstrIconPath,
	/* [in,opt] */ int piIconIndex,
	/* [in,opt] */ char * pstrDescription,
	/* [in,opt] */ char * pstrArguments,
	/* [out] */ char * pstrError);


/*
	This function will register FS Event Handler component. 
	Function need to be called while installing the component.

	Parameters: 
		pFSEventHandlerComp: 
			Details of component.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IRegisterFSEventHandlerCompW(	
	/* [in] */ FSEventHandlerCompW * pFSEventHandlerComp,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IRegisterFSEventHandlerCompA(	
	/* [in] */ FSEventHandlerCompA * pFSEventHandlerComp,
	/* [out] */ char * pstrError);

/*
	This function will unregister FS Event Handler component. 
	Function need to be called while uninstalling the component.

	Parameters: 
		pstrId: 
			Unique Identifier for the offline component.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IUnregisterFSEventHandlerCompW(	
	/* [in] */ wchar_t * pstrId,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IUnregisterFSEventHandlerCompA(	
	/* [in] */ char * pstrId,
	/* [out] */ char * pstrError);

/* This function will return FS Event Handler component info depending on passed component 
	identifier.
	Parameters: 
		pOfflineIdEstCompInfo: 
			Pass unique Identifier for the offline component and all other details will 
			be returned.
		pstrError: 
			Buffer to receive error message in case of failure.

	Return:
		Returns SETUP_SUCCESS in case of success. 
		Returns negative number in case of error and error message will be 
		returned in pstrError.

	Remark:
		None of the parameter should be NULL.
*/
long FSSETUPHELPER_API IGetFSEventHandlerCompInfoW(	
	/* [in,out] */ FSEventHandlerCompW * pFSEventHandlerComp,
	/* [out] */ wchar_t * pstrError);

long FSSETUPHELPER_API IGetFSEventHandlerCompInfoA(	
	/* [in,out] */ FSEventHandlerCompA * pFSEventHandlerComp,
	/* [out] */ char * pstrError);


#endif // #ifdef __SETUPHELPER_COMPILETIME_LINK__

#endif //__FSSETUPHELPER_H_