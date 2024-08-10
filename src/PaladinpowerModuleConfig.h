#pragma once
#include "ModuleConfig.h"

namespace cmangos_module
{
    class PaladinpowerConfig : public ModuleConfig
    {
    public:
        PaladinpowerModuleConfig();
        bool OnLoad() override;

    public:
        bool enabled;
    };
}