#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NonCombatStrategy.h"

using namespace BotAI;

void NonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "timer",
        NextAction::array(0, new NextAction("check mount state", 1.0f), NULL)));
}


void LfgStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "no possible targets",
        NextAction::array(0, new NextAction("lfg join", 1.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "lfg proposal",
        NextAction::array(0, new NextAction("lfg accept", 1.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "lfg proposal active",
        NextAction::array(0, new NextAction("lfg accept", 1.0f), NULL)));
}

void BGStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"no possible targets",
		NextAction::array(0, new NextAction("bg join", 1.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"bg status",
		NextAction::array(0, new NextAction("bg status", 1.0f), NULL)));

}

void WarsongStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"no possible targets",
		NextAction::array(0, new NextAction("bg tactics ws", 1.0f), NULL)));
}
