#pragma once

#include "strategy/actions/InventoryAction.h"

class Player;
class PlayerbotMgr;
class ChatHandler;

using namespace std;
using BotAI::InventoryAction;

class PlayerbotFactory : public InventoryAction
{
public:
    PlayerbotFactory(Player* bot, uint32 level, uint32 itemQuality = 0) :
        bot(bot), level(level), itemQuality(itemQuality), InventoryAction(bot->GetPlayerbotAI(), "factory") {}

    static uint64 GetRandomBot();
    void CleanRandomize();
    void Randomize();
    void Refresh();

private:
    void Randomize(bool incremental);
    void Prepare();
    void InitSecondEquipmentSet();
    void InitEquipment(bool incremental);
    bool CanEquipItem(ItemTemplate const* proto, uint32 desiredQuality);
    bool CanEquipUnseenItem(uint8 slot, uint16 &dest, uint32 item);
    void InitSkills();
    void InitTradeSkills();
    void UpdateTradeSkills();
    void SetRandomSkill(uint16 id);
    void InitSpells();
    void ClearSpells();
    void InitAvailableSpells();
	// EJ init quest spells
	void InitQuestSpells();
    void InitSpecialSpells();
    void InitTalents();
    void InitTalents(uint32 specNo);
    void InitQuests();
    void InitPet();
    void ClearInventory();
    void InitAmmo();
    void InitMounts();
    void InitPotions();
    void InitFood();
    bool CanEquipArmor(ItemTemplate const* proto);
	bool CheckItemStats(uint8 sph, uint8 spd, uint8 apa, uint8 aps, uint8 apr, uint8 tank);
	bool GetPlayerSpecTab(Player * Player);
    bool CanEquipWeapon(ItemTemplate const* proto);
    void EnchantItem(Item* item);
    void AddItemStats(uint32 mod, uint8 &sph, uint8 &spd, uint8 &apa, uint8 &aps, uint8 &apr, uint8 &tank);
    void CancelAuras();
    bool IsDesiredReplacement(Item* item);
    void InitBags();
    void InitInventory();
    void InitInventoryTrade();
    void InitInventoryEquip();
    void InitInventorySkill();
    Item* StoreItem(uint32 itemId, uint32 count);
    void InitGlyphs();
    void InitGuild();

private:
    Player* bot;
    uint32 level;
    uint32 itemQuality;
    static uint32 tradeSkills[];
};
