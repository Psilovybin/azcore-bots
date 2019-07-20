#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LootTriggers.h"

using namespace BotAI;

bool LootAvailableTrigger::IsActive()
{
	return AI_VALUE(bool, "has available loot") && AI_VALUE(uint8, "bag space") < 80 &&
		AI_VALUE(list<uint64>, "possible targets").empty();
}

bool FarFromCurrentLootTrigger::IsActive()
{
    return AI_VALUE2(float, "distance", "loot target") > INTERACTION_DISTANCE;
}

bool CanLootTrigger::IsActive()
{
    return AI_VALUE(bool, "can loot");
}
