#pragma once
#include "../../sdk/math/math.h"
#include "../../sdk/glob/offsets.h"
#include "../../sdk/glob/struct.h"
#include "../../sdk/glob/config.h"
#include "../../sdk/mem/mem.h"

namespace aim
{
	void Update();
	void AimBot(Entity* target, Entity* localPlayer);
	Entity* GetClosestEnemy();
}

