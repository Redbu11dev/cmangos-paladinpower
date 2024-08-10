#include "PaladinpowerModule.h"

#include "Entities/Player.h"
#include "Globals/ObjectMgr.h"
#include "Globals/ObjectAccessor.h"
#include "World/World.h"

#ifdef ENABLE_PLAYERBOTS
#include "playerbot/PlayerbotAI.h"
#endif

namespace cmangos_module
{
    PaladinpowerModule::PaladinpowerModule()
    : Module("Paladinpower", new PaladinpowerModuleConfig())
    {

    }

    void PaladinpowerModule::OnInitialize()
    {
	    if (GetConfig()->enabled)
	    {
            if (!GetConfig()->enableCrusaderStrike)
                UnlearnAllRanksOfCrusaderStrikeForEveryPlayer();

            if (!GetConfig()->enabledOldHolyStrike)
                UnlearnAllRanksOfOldHolyStrikeForEveryPlayer();

#ifdef ENABLE_PLAYERBOTS

#endif
	    }
        else
        {
            UnlearnAllRanksOfCrusaderStrikeForEveryPlayer();
            UnlearnAllRanksOfOldHolyStrikeForEveryPlayer();
        }
    }

    const cmangos_module::PaladinpowerModuleConfig* PaladinpowerModule::GetConfig() const
    {
        return (PaladinpowerModuleConfig*)Module::GetConfig();
    }

    void PaladinpowerModule::OnLoadFromDB(Player* player)
    {
        if (GetConfig()->enabled)
        {
            if (GetConfig()->enableCrusaderStrike)
                LearnCrusaderStrikeOfAvailableRanks(player);

            if (GetConfig()->enabledOldHolyStrike)
                LearnOldHolyStrikeOfAvailableRanks(player);
	    }
    }

    void PaladinpowerModule::OnGiveLevel(Player* player, uint32 level)
    {
	    if (GetConfig()->enabled)
	    {
            if (GetConfig()->enableCrusaderStrike)
                LearnCrusaderStrikeOfAvailableRanks(player);

            if (GetConfig()->enabledOldHolyStrike)
                LearnOldHolyStrikeOfAvailableRanks(player);
	    }
    }

    void PaladinpowerModule::LearnCrusaderStrikeOfAvailableRanks(Player* player)
    {
        if (player->getClass() == CLASS_PALADIN)
        {

            //learn
            for (auto rankLevel : csRanks)
            {
                if (player->GetLevel() >= rankLevel.second)
                {
                    uint32 rankSpellId = rankLevel.first;
                    if (rankSpellId > 0 && !player->HasSpell(rankSpellId))
                    {
                        if (!player->IsInWorld())
                            player->addSpell(rankSpellId, true, true, true, false);
                        else
                            player->learnSpell(rankSpellId, true);
                    }
                }
            }
        }
    }

    void PaladinpowerModule::UnlearnAllRanksOfCrusaderStrikeForEveryPlayer()
    {
        for (auto rankLevel : csRanks)
        {
            uint32 rankSpellId = rankLevel.first;

            //remove spell for all players in db
            auto query = CharacterDatabase.PQuery(
                "DELETE FROM character_spell WHERE spell = '%u'",
                rankSpellId
            );

            //remove spell for all online players
            for (auto guidPlayerPair : sObjectAccessor.GetPlayers())
            {
                Player* player = guidPlayerPair.second;

                if (rankSpellId > 0 && player->HasSpell(rankSpellId))
                {
                    player->removeSpell(rankSpellId);
                }
            }
        }
    }

    void PaladinpowerModule::LearnOldHolyStrikeOfAvailableRanks(Player* player)
    {
        if (player->getClass() == CLASS_PALADIN)
        {

            //learn
            for (auto rankLevel : oldHsRanks)
            {
                if (player->GetLevel() >= rankLevel.second)
                {
                    uint32 rankSpellId = rankLevel.first;
                    if (rankSpellId > 0 && !player->HasSpell(rankSpellId))
                    {
                        if (!player->IsInWorld())
                            player->addSpell(rankSpellId, true, true, true, false);
                        else
                            player->learnSpell(rankSpellId, true);
                    }
                }
            }
        }
    }

    void PaladinpowerModule::UnlearnAllRanksOfOldHolyStrikeForEveryPlayer()
    {
        for (auto rankLevel : oldHsRanks)
        {
            uint32 rankSpellId = rankLevel.first;

            //remove spell for all players in db
            auto query = CharacterDatabase.PQuery(
                "DELETE FROM character_spell WHERE spell = '%u'",
                rankSpellId
            );

            //remove spell for all online players
            for (auto guidPlayerPair : sObjectAccessor.GetPlayers())
            {
                Player* player = guidPlayerPair.second;

                if (rankSpellId > 0 && player->HasSpell(rankSpellId))
                {
                    player->removeSpell(rankSpellId);
                }
            }
        }
    }
}