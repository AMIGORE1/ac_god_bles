#include "move.h"

void move::Update()
{
	uintptr_t localPlayerPtr = *reinterpret_cast<uintptr_t*>(mem::ac_base + offs::LocalPlayer);
	Entity* LocalPlayer = reinterpret_cast<Entity*>(localPlayerPtr);
	if((GetAsyncKeyState(VK_F1) & 1))
		LocalPlayer->NoClip = 4;
	else if ((GetAsyncKeyState(VK_F2) & 1))
		LocalPlayer->NoClip = 0;
	
}
