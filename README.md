# Paladinpower
Module to give classic paladins more power by allowing to restore [Crusader Strike] and old[Holy Strike]

The correct rank spells will be learned for each player automatically upon level up (or upon login if player level is higher than required)

# Available Cores
Classic only

# How to install
1. Follow the instructions in https://github.com/davidonete/cmangos-modules?tab=readme-ov-file#how-to-install
2. Enable the `BUILD_MODULE_PALADINPOWER` flag in cmake and run cmake. The module should be installed in `src/modules/paladinpower`
3. Copy the configuration file from `src/modules/transmog/src/paladinpower.conf.dist.in` and place it where your mangosd executable is. Also rename it to `paladinpower.conf`.
4. Done

# How to uninstall
Set Paladinpower.Enable = 0 in config and relaunch the server once and let it load, it will remove all the added spells for all players