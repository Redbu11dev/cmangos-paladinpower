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
                {8823, 18},
                {8824, 26},
                {10336, 34},
                {10337, 42}
        };
        std::vector<std::pair<uint32, uint32>> oldHsRanks = {
                {679, 10},
                {678, 18},
                {1866, 26},
                {680, 34},
                {2495, 42},
                {5569, 48},
                {10332, 54},
                {10333, 60}
        };

        void LearnCrusaderStrikeOfAvailableRanks(Player* player);
        void UnlearnAllRanksOfCrusaderStrikeForEveryPlayer();

        void LearnOldHolyStrikeOfAvailableRanks(Player* player);
        void UnlearnAllRanksOfOldHolyStrikeForEveryPlayer();
    };
}
#endif