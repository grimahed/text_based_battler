#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <list>

enum class PCLASSES;

struct Player
{
    std::string name;
    std::list<std::string> ability_list;
    PCLASSES kind;
};

enum class PCLASSES
{
    WARRIOR,
    MAGE,
    ROGUE,
    WARLOCK,
    PRIEST,
};


/*union class_skills {
    std::list<std::string> w_skills;
    std::list<std::string> m_skills;
    std::string r_skills;
    std::string wl_skills;
    std::string wm_skills;
};*/

#endif