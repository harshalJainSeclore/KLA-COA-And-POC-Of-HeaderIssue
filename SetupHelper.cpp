#define NOMINMAX
#include <Windows.h>

#include <cwchar>
#include <iostream>
#include <stdexcept>

#include "setupHelper.h"

namespace
{
using RegisterComponentExWFn = long (*)(ComponentInfoExW*, wchar_t*);
using UnregisterComponentWFn = long (*)(wchar_t*, wchar_t*);

constexpr wchar_t kDllPath[] = L"D:\\Work\\KLA COA\\build\\setuphelper.dll";
constexpr wchar_t kComponentId[] = L"MyComponent";
constexpr wchar_t kCompany[] = L"Seclore Technology Pvt. Ltd.";
constexpr wchar_t kName[] = L"My Component";
constexpr wchar_t kDescription[] = L"My component description";
constexpr wchar_t kVersion[] = L"1.0.0.0";
constexpr wchar_t kInstallPath[] = L"C:\\Program Files\\MyComponent";
constexpr wchar_t kReleaseNotes[] = L"ReleaseNotes.txt";
constexpr wchar_t kAssistant[] = L"MyAssistant.dll";
constexpr wchar_t kResCollFolder[] = L"Resources";
constexpr wchar_t kUrl[] = L"/downloads/mycomponent";
constexpr wchar_t kUninstallString[] = L"{PRODUCT-CODE}";
constexpr wchar_t kCurrentVersion[] = L"1.0.0.0";

void copyToBuffer(const wchar_t* source, wchar_t* destination, std::size_t destinationCount)
{
    const std::size_t length = std::wcslen(source);
    if (length >= destinationCount)
    {
        throw std::runtime_error("Hardcoded value exceeds destination buffer size.");
    }

    std::wmemset(destination, 0, destinationCount);
    std::wmemcpy(destination, source, length);
}

ComponentInfoExW createComponentInfo()
{
    ComponentInfoExW info{};
    info.mlSize = COMPONENTINFOEXW_SIZE_VER_1;
    info.mType = CompTypeApp;
    info.mbUpdatable = true;
    info.mbDependent = false;
    info.mlSequence = 0;
    info.mUnistType = UninstTypeProductCode;

    copyToBuffer(kComponentId, info.mstrId, std::size(info.mstrId));
    copyToBuffer(kCompany, info.mstrCompany, std::size(info.mstrCompany));
    copyToBuffer(kName, info.mstrName, std::size(info.mstrName));
    copyToBuffer(kDescription, info.mstrDescription, std::size(info.mstrDescription));
    copyToBuffer(kVersion, info.mstrVersion, std::size(info.mstrVersion));
    copyToBuffer(kInstallPath, info.mstrInstallPath, std::size(info.mstrInstallPath));
    copyToBuffer(kReleaseNotes, info.mstrReleaseNotes, std::size(info.mstrReleaseNotes));
    copyToBuffer(kAssistant, info.mstrAssistant, std::size(info.mstrAssistant));
    copyToBuffer(kResCollFolder, info.mstrResCollFolder, std::size(info.mstrResCollFolder));
    copyToBuffer(kUrl, info.mstrURL, std::size(info.mstrURL));
    copyToBuffer(kUninstallString, info.mstrUninstallString, std::size(info.mstrUninstallString));
    copyToBuffer(kCurrentVersion, info.mstrCurrentVersion, std::size(info.mstrCurrentVersion));

    return info;
}

template <typename FunctionPointer>
FunctionPointer getFunction(HMODULE module, const char* name)
{
    return reinterpret_cast<FunctionPointer>(GetProcAddress(module, name));
}

int registerComponent(HMODULE module)
{
    const auto registerFn = getFunction<RegisterComponentExWFn>(module, "IRegisterComponentExW");
    if (!registerFn)
    {
        std::cerr << "Unable to locate export: IRegisterComponentExW\n";
        return 1;
    }

    ComponentInfoExW info = createComponentInfo();
    wchar_t error[ERROR_MSG_MAX_LEN + 1]{};
    const long result = registerFn(&info, error);

    std::wcout << L"Register result: " << result << L'\n';
    if (error[0] != L'\0')
    {
        std::wcout << L"Register error: " << error << L'\n';
    }

    return result == SETUP_SUCCESS ? 0 : static_cast<int>(result);
}

int unregisterComponent(HMODULE module)
{
    const auto unregisterFn = getFunction<UnregisterComponentWFn>(module, "IUnregisterComponentW");
    if (!unregisterFn)
    {
        std::cerr << "Unable to locate export: IUnregisterComponentW\n";
        return 1;
    }

    wchar_t componentId[MAX_COMP_ID_LEN + 1]{};
    copyToBuffer(kComponentId, componentId, std::size(componentId));

    wchar_t error[ERROR_MSG_MAX_LEN + 1]{};
    const long result = unregisterFn(componentId, error);

    std::wcout << L"Unregister result: " << result << L'\n';
    if (error[0] != L'\0')
    {
        std::wcout << L"Unregister error: " << error << L'\n';
    }

    return result == SETUP_SUCCESS ? 0 : static_cast<int>(result);
}
} // namespace

int wmain(int argc, wchar_t* argv[])
{
    if (argc != 2)
    {
        std::wcout << L"Usage: SetupHelper.exe register|unregister\n";
        return 1;
    }

    HMODULE module = LoadLibraryW(kDllPath);
    if (!module)
    {
        std::wcout << L"Unable to load DLL: " << kDllPath << L'\n';
        return 1;
    }

    int exitCode = 1;
    if (_wcsicmp(argv[1], L"register") == 0)
    {
        exitCode = registerComponent(module);
    }
    else if (_wcsicmp(argv[1], L"unregister") == 0)
    {
        exitCode = unregisterComponent(module);
    }
    else
    {
        std::wcout << L"Usage: SetupHelper.exe register|unregister\n";
    }

    FreeLibrary(module);
    return exitCode;
}
