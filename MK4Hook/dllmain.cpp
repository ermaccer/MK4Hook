// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include "settings.h"

#include "MemoryMgr.h"
#include "mk4.h"
#include "wrapper.h"
#include "freecamera.h"
#include "IniReader.h"

using namespace Memory::VP;
void WINAPI HookUpdate()
{
    while (true)
    {
        FreeCamera::Update();
        Sleep(1);
    }
}

void _null() {}
bool _true() { return true;  }

void Init()
{
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    eSettingsManager::Init();
    CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(HookUpdate), nullptr, 0, nullptr);

    if (eSettingsManager::bDisableBackground)
    {
        Nop(0x4B9EB5, 5);
        Nop(0x4B9F27, 5);
    }

    if (eSettingsManager::bDisableFatalityCamera)
    {
        // scorpion cam
        InjectHook(0x444FE0, _null, PATCH_JUMP);
        // raiden cam
        InjectHook(0x443420, _null, PATCH_JUMP);
        // sonya
        InjectHook(0x48A420, _null, PATCH_JUMP);
        // lk
        InjectHook(0x452000, _null, PATCH_JUMP);
        // sz
        InjectHook(0x445920, _null, PATCH_JUMP);
        // wg
        InjectHook(0x450300, _null, PATCH_JUMP);
        // shinnok
        InjectHook(0x456BA0, _null, PATCH_JUMP);
        // ns (reiko)
        InjectHook(0x453850, _null, PATCH_JUMP);
        // qc
        InjectHook(0x44C700, _null, PATCH_JUMP);
        // tanya
        InjectHook(0x44F180, _null, PATCH_JUMP);
        // reptile
        InjectHook(0x454A00, _null, PATCH_JUMP);
        // kai
        InjectHook(0x44BAD0, _null, PATCH_JUMP);
        InjectHook(0x44BC92, _null);
        // jarek
        InjectHook(0x447D50, _null, PATCH_JUMP);
        // jax
        InjectHook(0x44A9F0, _null, PATCH_JUMP);
        // cage
        InjectHook(0x449040, _null, PATCH_JUMP);
    }
  
    if (eSettingsManager::bEnableFreeCamera)
    {
        InjectHook(0x407586, camera_hook_one, PATCH_JUMP);
        InjectHook(0x407590, camera_hook_two, PATCH_JUMP);
        InjectHook(0x407599, camera_hook_three, PATCH_JUMP);

        InjectHook(0x4075CC, camera_angle_hook_one, PATCH_JUMP);
        InjectHook(0x4075E4, camera_angle_hook_two, PATCH_JUMP);
        InjectHook(0x4075FD, camera_angle_hook_three, PATCH_JUMP);

        InjectHook(0x4326A4, camera_update_hook_one, PATCH_JUMP);
        InjectHook(0x4326B0, camera_update_hook_two, PATCH_JUMP);
        InjectHook(0x4326BC, camera_update_hook_three, PATCH_JUMP);

        InjectHook(0x4326C8, camera_update_angle_hook_one, PATCH_JUMP);
        InjectHook(0x4326D4, camera_update_angle_hook_two, PATCH_JUMP);
        InjectHook(0x4326E0, camera_update_angle_hook_three, PATCH_JUMP);

        InjectHook(0x48AE73, camera_special_hook_one, PATCH_JUMP);
        InjectHook(0x48AE85, camera_special_hook_two, PATCH_JUMP);
        InjectHook(0x48AE97, camera_special_hook_three, PATCH_JUMP);

        InjectHook(0x4258E0, camera_special_angle_hook_x, PATCH_JUMP);

        InjectHook(0x42AF32, camera_special_angle_hook_one, PATCH_JUMP);
        InjectHook(0x42AF67, camera_special_angle_hook_two, PATCH_JUMP);
        InjectHook(0x42AF9C, camera_special_angle_hook_three, PATCH_JUMP);

        InjectHook(0x42513D, camera_special_angle2_hook_one, PATCH_JUMP);
        InjectHook(0x425147, camera_special_angle2_hook_two, PATCH_JUMP);
        InjectHook(0x425153, camera_special_angle2_hook_three, PATCH_JUMP);

        InjectHook(0x43F200, camera_special_more_hook_one, PATCH_JUMP);
        InjectHook(0x43F193, camera_special_more_hook_two, PATCH_JUMP);
        InjectHook(0x457C7D, camera_special_more_hook_three, PATCH_JUMP);
        InjectHook(0x457BE8, camera_special_more_hook_four, PATCH_JUMP);

        InjectHook(0x43F251, camera_special_more_angle_hook_one, PATCH_JUMP);
        InjectHook(0x42585C, camera_special_more_angle_hook_two, PATCH_JUMP);
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
        Init();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

