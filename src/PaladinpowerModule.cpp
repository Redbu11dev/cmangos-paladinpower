#include "PaladinpowerModule.h"

#include "Entities/Player.h"
#include "Globals/ObjectMgr.h"

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
            //do not do anything yet
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
            LearnAvailableSkills(player);
	    }
    }

    void PaladinpowerModule::OnGiveLevel(Player* player, uint32 level)
    {
	    if (GetConfig()->enabled)
	    {
            LearnAvailableSkills(player);
	    }
    }

    void PaladinpowerModule::LearnAvailableSkills(Player* player)
    {
        if (player->getClass() == CLASS_PALADIN)
        {

            //learn Crusader strike
            std::vector<std::pair<uint32, uint32>> csRanks = {
                {2537, 10},
                {8823, 20},
                {8824, 30},
                {10336, 40},
                {10337, 50}
            };

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
}