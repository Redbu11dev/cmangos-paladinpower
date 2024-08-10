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
        void LearnAvailableSkills(Player* player);
    };
}
#endif