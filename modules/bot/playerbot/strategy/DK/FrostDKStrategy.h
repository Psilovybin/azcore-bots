#pragma once

#include "GenericDKStrategy.h"
#include "../generic/CombatStrategy.h"

namespace BotAI
{
    class FrostDKStrategy : public GenericDKStrategy
    {
    public:
        FrostDKStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "frost"; }
        virtual NextAction** getDefaultActions();
    };

    class FrostDKAoeStrategy : public CombatStrategy
    {
    public:
        FrostDKAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "frost aoe"; }
    };
}
