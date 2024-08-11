# Paladinpower
Module to give classic paladins more power by allowing to restore (optional, can choose only one):

[Crusader Strike] and [zzOldHoly Strike]

The correct rank spells will be learned for each player automatically upon level up (or upon login if player level is higher than required)

# Available Cores
Classic only

# Playerbot compatibility
Bots will be able to use crusader strike out of the box

I have changes in my own playerbots fork, contact me on discord if you need it

# How to install
1. Follow the instructions in https://github.com/davidonete/cmangos-modules?tab=readme-ov-file#how-to-install
2. Enable the `BUILD_MODULE_PALADINPOWER` flag in cmake and run cmake. The module should be installed in `src/modules/paladinpower`
3. Copy the configuration file from `src/modules/transmog/src/paladinpower.conf.dist.in` and place it where your mangosd executable is. Also rename it to `paladinpower.conf`.
4. Go to `paladinpower.conf` and enable desired config options
5. Done

# How to uninstall
1. Go to `paladinpower.conf` and set `Paladinpower.Enable = 0`
2. Relaunch the server once and let it load, it will remove all the added spells for all players
3. Done