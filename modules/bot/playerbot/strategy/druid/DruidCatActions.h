#pragma once

namespace BotAI {
	class CastFeralChargeCatAction : public CastReachTargetSpellAction
	{
	public:
		CastFeralChargeCatAction(PlayerbotAI* ai) : CastReachTargetSpellAction(ai, "feral charge - cat", 1.5f) {}
	};

	class CastCowerAction : public CastBuffSpellAction
	{
	public:
		CastCowerAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "cower") {}
	};


	class CastEnrageAction : public CastBuffSpellAction
	{
	public:
		CastEnrageAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "enrage") {}
	};

	class CastTigersFuryAction : public CastBuffSpellAction
	{
	public:
		CastTigersFuryAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "tiger's fury") {}
	};

	class CastRakeAction : public CastDebuffSpellAction
	{
	public:
		CastRakeAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "rake") {}
	};

	class CastClawAction : public CastMeleeSpellAction {
	public:
		CastClawAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "claw") {}
	};

	class CastMangleCatAction : public CastMeleeSpellAction {
	public:
		CastMangleCatAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "mangle (cat)") {}
	};

	class CastSwipeCatAction : public CastMeleeSpellAction {
	public:
		CastSwipeCatAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "swipe (cat)") {}
	};

	class CastFerociousBiteAction : public CastMeleeSpellAction {
	public:
		CastFerociousBiteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "ferocious bite") {}
	};


	class CastRipAction : public CastMeleeSpellAction {
	public:
		CastRipAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "rip") {}
	};



}
