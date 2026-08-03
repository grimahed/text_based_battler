#ifndef ZONES_H
#define ZONES_H
#include <iostream>
#include "PLAYER.h"
#include "helpers.cpp"
#include <optional>
#include <string>
#include <string_view>
#include <list>
using namespace std;

enum class ZONES
{
    ELWYNN_FOREST,
    ZORAVIA,
    GREENGUARD,
};

struct Zone
{
    std::list<std::string> enemy_list;
};

#endif