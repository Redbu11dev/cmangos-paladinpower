#include "PaladinpowerModuleConfig.h"
#include "Globals/ObjectMgr.h"
#include "Log/Log.h"

namespace cmangos_module
{
    PaladinpowerModuleConfig::PaladinpowerModuleConfig()
    : ModuleConfig("paladinpower.conf")
    , enabled(false)
    {

    }

    bool PaladinpowerModuleConfig::OnLoad()
    {
        enabled = config.GetBoolDefault("Paladinpower.Enable", false);

        enableCrusaderStrike = config.GetBoolDefault("Paladinpower.EnableCrusaderStrike", true);
        enabledOldHolyStrike = config.GetBoolDefault("Paladinpower.EnableOldHolyStrike", false);

#ifndef EXPANSION=0
        enabled = false;
#endif

        return true;
    }
}