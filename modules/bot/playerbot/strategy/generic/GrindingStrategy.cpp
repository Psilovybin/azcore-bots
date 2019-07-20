#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GrindingStrategy.h"

using namespace BotAI;


NextAction** GrindingStrategy::getDefaultActions()
{
    return NULL;
}

void GrindingStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "no target",
        NextAction::array(0,
        new NextAction("attack anything", 5.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"in battleground without flag",
		NextAction::array(0,
		new NextAction("attack anything", 5.0f), NULL)));		
}

