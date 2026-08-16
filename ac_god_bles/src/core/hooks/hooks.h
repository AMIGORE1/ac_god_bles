#pragma once
#include "../../sdk/mem/mem.h"
#include "../../../ext/minhook/include/MinHook.h"
#include "../hooks/wgl/wgl.h"
#include "../../sdk/glob/offsets.h"

namespace hooks
{
	bool Init();
	void Release();

	bool Init_Hooks();

}