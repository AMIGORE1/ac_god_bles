#include "hooks.h"


bool hooks::Init()
{
    if (MH_Initialize() != MH_OK)
        return false;
    if (!Init_Hooks())
        return false;


    MH_EnableHook(MH_ALL_HOOKS);
    return true;
}

void hooks::Release()
{
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();
    ReleaseImGui();
}

bool hooks::Init_Hooks()
{
    if(!mem::Init_Modules()) return false;

    uint8_t* wglAddr = mem::gl_base + offs::func::WglSwapBuffer;
    if (MH_CreateHook(wglAddr, &hWglSwapBuffer, reinterpret_cast<LPVOID*>(&oWglSwapBuffer)) != MH_OK) {
        return false;
    }

    return true;
}
