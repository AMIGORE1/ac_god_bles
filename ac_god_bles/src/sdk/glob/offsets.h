#pragma once
#include <cstdio>

namespace offs
{
	const uintptr_t LocalPlayer = 0x17E0A8;
	const uintptr_t EntityList = 0x18AC04;
	const uintptr_t NumOfPlayers = 0x18AC0C;
	const uintptr_t ViewMatrix = 0x57DFD0;

	namespace func
	{
		const uintptr_t WglSwapBuffer = 0x407D0;
		const uintptr_t RayShot = 0xC9510;
	}
}