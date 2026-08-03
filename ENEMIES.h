#ifndef ENEMIES_H
#define ENEMIES_H
#include "ZONES.h"
#include <iostream>
#include <string>
#include <list>

//enum class WOLVES {WOLF, DIREWOLF};
//enum class E_MAGE {ZORAVIAN_MAGE, ELWYNN_MAGE};

struct en_stats
{
    int HP;
    int STR;
    int DEX;
    int INT;
    int WIS;
};

enum class ENEMIES
{
    MURLOC,
    WOLF,
    E_MAGE,
    FROGZARD,
    GREENGUARD_DRAGON,
    W_ELEMENTAL,
    BANDIT,
    MEGALOCRAB, //good heavens would you look at the time
};

struct Enemy
{
    bool is_alive = true;
    bool turn_taken;
    en_stats e_stats;
    int current_enemy_hp;
    ENEMIES type;
    std::string name;
    std::list<std::string> ability_list;
    int e_level = 1;


    //now it's not eye bleed material
    std::list<std::string> wolf_atks = {"Attack", "Bite", "Deadlier Bite", "Slash"};
    std::list<std::string> big_wolf_atks = {"Attack", "Deadlier Bite", "Gouge", "Shred"};
    std::list<std::string> e_mage_atks = {"Bonk", "Fire", "Water", "Gust"};
    std::list<std::string> w_elemental_atks = {"Water", "Dowse", "Torrent"};
    std::list<std::string> murloc_abilities = {"Attack", "Water", "Cure"}; //Gonna be a possible menace just like in classic!
    std::list<std::string> crab_atks = {"Pincer", "Pound and Toss", "Water Torrent"};
    std::list<std::string> bandit_atks = {"Bonk", "Eviscerate", "Stab", "Casted Punch"}; //it is my legal obligation to include a casted punch
    std::list<std::string> drgn_atks = {"Attack", "Breathe Fire", "Icy Breath", "Fly and Swipe", "Chomp"};
};                                                                                      


#endif