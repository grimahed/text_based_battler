#ifndef ENEMIES_H
#define ENEMIES_H
#include "ZONES.h"
#include <iostream>
#include <string>
#include <list>

enum class WOLVES {WOLF, DIREWOLF};


enum class PHYS_ENEMY_ATKS {ATTACK, BIGGER_BONK, BITE, DEADLIER_BITE};
enum class MAG_ENEMY_ATKS {BONK, FIRE, THUNDER, WATER, GUST};

struct e_stats
{
    int HP;
    int STR;
    int DEX;
    int INT;
    int WIS;
};

//struct wolves {WOLF_TYPES arg; WOLF_TYPES get_wolf(WOLF_TYPES arg) {};};

struct Enemy
{
    bool is_alive;
    void* type;
    ZONES zone;
    std::string name;
    //Enemy() : val() {};
    int count;
};


#endif