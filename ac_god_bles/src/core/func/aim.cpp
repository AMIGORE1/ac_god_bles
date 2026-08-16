#include "aim.h"


void aim::Update()
{
    if (!cfg::AimBot)
        return;

    uintptr_t localPlayerPtr = *reinterpret_cast<uintptr_t*>(mem::ac_base + offs::LocalPlayer);
    if (!localPlayerPtr)
        return;

    Entity* localPlayer = reinterpret_cast<Entity*>(localPlayerPtr);

    if (!localPlayer || !localPlayer->IsAlive)
        return;

}

void aim::AimBot(Entity* target, Entity* localPlayer)
{

}

Entity* aim::GetClosestEnemy()
{

}