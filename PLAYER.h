#ifndef PLAYER_H
#define PLAYER_H
#include <string>

typedef struct Player
{
    std::string name;
    std::string input;

} player_t;

template <typename C>
struct Class {
    //Warrior
    C Warrior{};
    C mage{};
    C rogue{};
    C white_mage{};
};

#endif