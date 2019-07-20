#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DKMultipliers.h"
#include "FrostDKStrategy.h"

using namespace BotAI;

class FrostDKStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
	FrostDKStrategyActionNodeFactory()
	{
		creators["icy touch"] = &icy_touch;
		creators["obliterate"] = &obliterate;
		creators["howling blast"] = &howling_blast;
		creators["frost strike"] = &frost_strike;
		//creators["chains of ice"] = &chains_of_ice;
		creators["rune strike"] = &rune_strike;
		//creators["icy clutch"] = &icy_clutch;
		//creators["horn of winter"] = &horn_of_winter;
		//creators["killing machine"] = &killing_machine;
		//creators["frost presence"] = &frost_presence;
		//creators["deathchill"] = &deathchill;
		//creators["icebound fortitude"] = &icebound_fortitude;
		//creators["mind freeze"] = &mind_freeze;
		//creators["empower weapon"] = &empower_weapon;
		//creators["hungering cold"] = &hungering_cold;
		//creators["unbreakable armor"] = &unbreakable_armor;
		//creators["improved icy talons"] = &improved_icy_talons;
	}

	private:
		static ActionNode* icy_touch(PlayerbotAI* ai)
		{
			return new ActionNode("icy touch",
				/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
				/*A*/ NextAction::array(0, new NextAction("howling blast"), NULL),
				/*C*/ NULL);
		}
		static ActionNode* obliterate(PlayerbotAI* ai)
		{
		return new ActionNode("obliterate",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("frost strike"), NULL),
			/*C*/ NULL);
		}
		static ActionNode* rune_strike(PlayerbotAI* ai)
		{
		return new ActionNode("rune strike",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("melee"), NULL),
			/*C*/ NULL);
		}
		static ActionNode* frost_strike(PlayerbotAI* ai)
		{
		return new ActionNode("frost strike",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
		}
		static ActionNode* howling_blast(PlayerbotAI* ai)
		{
		return new ActionNode("howling blast",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("icy touch"), NULL),
			/*C*/ NULL);	
		}
};

	FrostDKStrategy::FrostDKStrategy(PlayerbotAI* ai) : GenericDKStrategy(ai)
	{
	actionNodeFactories.Add(new FrostDKStrategyActionNodeFactory());
	}


	NextAction** FrostDKStrategy::getDefaultActions()
	{
    return NextAction::array(0, new NextAction("frost strike", 7.0f), NULL);
	}

void FrostDKStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDKStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "empower weapon",
        NextAction::array(0, new NextAction("empower weapon", 50.0f), NULL)));
}

void FrostDKAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"light aoe",
		NextAction::array(0, new NextAction("howling blast", 40.0f), NULL)));
}
