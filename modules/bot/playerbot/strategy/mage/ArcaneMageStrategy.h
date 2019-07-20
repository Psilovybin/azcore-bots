#pragma once

#include "GenericMageStrategy.h"

namespace BotAI
{
    class ArcaneMageStrategy : public GenericMageStrategy
    {
    public:
        ArcaneMageStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "arcane"; }
        virtual NextAction** getDefaultActions();
    };
	class ArcaneMageAoeStrategy : public CombatStrategy
	{
	public:
		ArcaneMageAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "arcane aoe"; }
	};
}
