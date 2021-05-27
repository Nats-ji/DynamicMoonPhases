#include "pch.h"

static HANDLE hMutexHandle = nullptr;

static std::filesystem::path cwd = std::filesystem::current_path();

static void Initialize()
{
    try
    {
        //Single instance check
        hMutexHandle = CreateMutex(NULL, TRUE, L"dynamic_moon_phases");
        if (GetLastError() == ERROR_ALREADY_EXISTS)
        {
            return;
        }
        time_t time_now = std::time(nullptr);
        MoonPhase::Moon_Phase phase = MoonPhase::calc(time_now);
        Archive::link(phase);
    }
    catch (...)
    {}
}

static void Shutdown()
{
    Archive::remove();

    if (hMutexHandle)
    {
        ReleaseMutex(hMutexHandle);
        CloseHandle(hMutexHandle);
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Initialize();
        break;
    case DLL_PROCESS_DETACH:
        Shutdown();
        break;
    default:
        break;
    }
    return TRUE;
}
