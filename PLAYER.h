#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <list>
#include "ZONES.h"

enum class PCLASSES
{
    WARRIOR,
    MAGE,
    ROGUE,
    WARLOCK,
    PRIEST,
};

struct p_stats
{
    int HP;
    int STR;
    int DEX;
    int INT;
    int WIS;
};

enum class W_SKILLS {MORTAL_STRIKE, OVERPOWER, EXECUTE, REND};
enum class M_SKILLS {ICE_BOLT, FIREBLAST, THUNDER, ICE_BLOCK};
enum class R_SKILLS {SLICE_AND_DICE, KICK, SABER_SLASH, POISON_BOMB};
enum class WL_SKILLS {SHADOW_BOLT, BONE_DECAY, RAIN_OF_FIRE, SUMMON_DEMON};
enum class P_SKILLS {HEAL, DIA, HOLY, AERO};

struct Player
{
    bool is_alive = true;
    bool turn_taken;
    bool ice_cubed = false;
    bool non_damage_used = false;
    int level = 1;
    int current_HP;
    std::string input;
    std::string name;
    PCLASSES kind;
    p_stats stats;
    p_stats new_stats;
    std::list<std::string> ability_list;
    std::list<std::string> zone_list = {"Elwynn Forest", "Zoravia", "Greenguard"};
    ZONES current_zone;
    //ability stuff
    W_SKILLS w_ability;
    M_SKILLS m_ability;
    R_SKILLS r_ability;
    WL_SKILLS wl_ability;
    P_SKILLS p_ability;
};

#endif