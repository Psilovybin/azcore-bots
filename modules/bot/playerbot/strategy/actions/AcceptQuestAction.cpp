#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "AcceptQuestAction.h"

using namespace BotAI;

void AcceptAllQuestsAction::ProcessQuest(Quest const* quest, WorldObject* questGiver)
{
    AcceptQuest(quest, questGiver->GetGUID());
}

bool AcceptQuestAction::Execute(Event event)
{
    Player* master = GetMaster();

    if (!master)
        return false;

    Player *bot = ai->GetBot();
    uint64 guid;
    uint32 quest;

    string text = event.getParam();
    PlayerbotChatHandler ch(master);
    quest = ch.extractQuestId(text);
    if (quest)
    {
        Unit* npc = master->GetSelectedUnit();
        if (!npc)
        {
            bot->Say("Please select quest giver NPC", LANG_UNIVERSAL);
            return false;
        }
    }
    else if (!event.getPacket().empty())
    {
        WorldPacket& p = event.getPacket();
        p.rpos(0);
        p >> guid >> quest;
    }
    else if (text == "*")
    {
        return QuestAction::Execute(event);
    }
    else
        return false;

    Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest);
    if (!qInfo)
        return false;

    return AcceptQuest(qInfo, guid);
}

bool AcceptQuestShareAction::Execute(Event event)
{
    Player* master = GetMaster();
    Player *bot = ai->GetBot();

    WorldPacket& p = event.getPacket();
    p.rpos(0);
    uint32 quest;
    p >> quest;
    Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest);

    if (!qInfo || !bot->GetDivider())
        return false;

    quest = qInfo->GetQuestId();
    if( !bot->CanTakeQuest( qInfo, false ) )
    {
        // can't take quest
        bot->SetDivider( 0 );
        bot->Say("I can't take this quest", LANG_UNIVERSAL);

        return false;
    }

    // send msg to quest giving player
    master->SendPushToPartyResponse( bot, QUEST_PARTY_MSG_ACCEPT_QUEST );
    bot->SetDivider( 0 );

    if( bot->CanAddQuest( qInfo, false ) )
    {
        bot->AddQuest( qInfo, master );

        if( bot->CanCompleteQuest( quest ) )
            bot->CompleteQuest( quest );

        // Runsttren: did not add typeid switch from WorldSession::HandleQuestgiverAcceptQuestOpcode!
        // I think it's not needed, cause typeid should be TYPEID_PLAYER - and this one is not handled
        // there and there is no default case also.

        if( qInfo->GetSrcSpell() > 0 )
            bot->CastSpell( bot, qInfo->GetSrcSpell(), true );

        bot->Say("Quest accepted", LANG_UNIVERSAL);
        return true;
    }

    return false;
}
