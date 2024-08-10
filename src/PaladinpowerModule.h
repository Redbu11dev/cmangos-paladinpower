#ifndef CMANGOS_MODULE_PALADINPOWER_H
#define CMANGOS_MODULE_PALADINPOWER_H

#include "Module.h"
#include "PaladinpowerModuleConfig.h"

#include <unordered_map>
#include <map>

namespace cmangos_module
{
    class PaladinpowerModule : public Module
    {
    public:
        PaladinpowerModule();
        const PaladinpowerModuleConfig* GetConfig() const override;

        // Module Hooks
        void OnInitialize() override;

        // Player hooks
        void OnLoadFromDB(Player* player) override;
        void OnGiveLevel(Player* player, uint32 level) override;

    private:
        std::vector<std::pair<uint32, uint32>> csRanks = {
                {2537, 10},
                {8823, 20},
                {8824, 30},
                {10336, 40},
                {10337, 50}
        };
        std::vector<std::pair<uint32, uint32>> oldHsRanks = {
                {679, 10},
                {678, 20},
                {1866, 30},
                {680, 40},
                {2495, 40},
                {5569, 40},
                {10332, 40},
                {10333, 40}
        };

        void LearnCrusaderStrikeOfAvailableRanks(Player* player);
        void UnlearnAllRanksOfCrusaderStrikeForEveryPlayer();

        void LearnOldHolyStrikeOfAvailableRanks(Player* player);
        void UnlearnAllRanksOfOldHolyStrikeForEveryPlayer();
    };
}
#endif