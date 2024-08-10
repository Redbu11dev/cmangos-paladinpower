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
                {8823, 22},
                {8824, 34},
                {10336, 46},
                {10337, 58}
        };
        std::vector<std::pair<uint32, uint32>> oldHsRanks = {
                {679, 1},
                {678, 8},
                {1866, 16},
                {680, 24},
                {2495, 32},
                {5569, 40},
                {10332, 48},
                {10333, 56}
        };

        void LearnCrusaderStrikeOfAvailableRanks(Player* player);
        void UnlearnAllRanksOfCrusaderStrikeForEveryPlayer();

        void LearnOldHolyStrikeOfAvailableRanks(Player* player);
        void UnlearnAllRanksOfOldHolyStrikeForEveryPlayer();
    };
}
#endif