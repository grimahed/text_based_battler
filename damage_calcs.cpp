#include <iostream>
#include "PLAYER.h"
#include "player_building.cpp"
#include <string>
#include <string.h>
#include <ctype.h>
#include <string_view>
#include <list>
using namespace std;


W_SKILLS get_warrior_skill_used(Player* player)
{
    if (player->kind != PCLASSES::WARRIOR) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_abilities(*player) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_warrior_skill_used(player);
    }
    else if (player->input == "mortal strike")
    {
        player->w_ability = W_SKILLS::MORTAL_STRIKE;
    }
    else if (player->input == "overpower"){
        player->w_ability = W_SKILLS::OVERPOWER;
    }
    else if (player->input == "execute"){
        player->w_ability = W_SKILLS::EXECUTE;
    }
    else if (player->input == "rend"){
        player->w_ability = W_SKILLS::REND;
    } else {
        cout << "not an ability for Warrior" << endl;
        get_warrior_skill_used(player);
    }
    return player->w_ability;
}

M_SKILLS get_mage_skill_used(Player* player)
{
    if (player->kind != PCLASSES::MAGE) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_abilities(*player) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_mage_skill_used(player);
    }
    else if (player->input == "ice bolt")
    {
        player->m_ability = M_SKILLS::ICE_BOLT;
    }
    else if (player->input == "fireblast"){
        player->m_ability = M_SKILLS::FIREBLAST;
    }
    else if (player->input == "thunder"){
        player->m_ability = M_SKILLS::THUNDER;
    }
    else if (player->input == "ice block"){
        player->m_ability = M_SKILLS::ICE_BLOCK;
    } else {
        cout << "not an ability for Mage" << endl;
        get_mage_skill_used(player);
    }
    return player->m_ability;
}

R_SKILLS get_rogue_skill_used(Player* player)
{
    if (player->kind != PCLASSES::ROGUE) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_abilities(*player) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_rogue_skill_used(player);
    }
    else if (player->input == "slice and dice")
    {
        player->r_ability = R_SKILLS::SLICE_AND_DICE;
    }
    else if (player->input == "kick"){
        player->r_ability = R_SKILLS::KICK;
    }
    else if (player->input == "saber slash"){
        player->r_ability = R_SKILLS::SABER_SLASH;
    }
    else if (player->input == "poison bomb"){
        player->r_ability = R_SKILLS::POISON_BOMB;
    } else {
        cout << "not an ability for Warrior" << endl;
        get_rogue_skill_used(player);
    }
    return player->r_ability;
}

WL_SKILLS get_warlock_skill_used(Player* player)
{
    if (player->kind != PCLASSES::WARLOCK) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_abilities(*player) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_warlock_skill_used(player);
    }
    else if (player->input == "shadow bolt")
    {
        player->wl_ability = WL_SKILLS::SHADOW_BOLT;
    }
    else if (player->input == "bone decay"){
        player->wl_ability = WL_SKILLS::BONE_DECAY;
    }
    else if (player->input == "rain of fire"){
        player->wl_ability = WL_SKILLS::RAIN_OF_FIRE;
    }
    else if (player->input == "summon demon"){
        player->wl_ability = WL_SKILLS::SUMMON_DEMON;
    } else {
        cout << "not an ability for Warlock" << endl;
        get_warlock_skill_used(player);
    }
    return player->wl_ability;
}//just using sample values for now - going to replace first values with stat numbers.

P_SKILLS get_priest_skill_used(Player* player)
{
    if (player->kind != PCLASSES::PRIEST) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_abilities(*player) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_priest_skill_used(player);
    }
    else if (player->input == "heal")
    {
        player->p_ability = P_SKILLS::HEAL;
    }
    else if (player->input == "dia"){
        player->p_ability = P_SKILLS::DIA;
    }
    else if (player->input == "holy"){
        player->p_ability = P_SKILLS::HOLY;
    }
    else if (player->input == "aero"){
        player->p_ability = P_SKILLS::AERO;
    } else {
        cout << "not an ability for Priest" << endl;
        get_priest_skill_used(player);
    }
    return player->p_ability;
}


int calc_damage(Player* player)
{
    int damage = 0;
    switch (player->kind)
    {
        case PCLASSES::WARRIOR:
            get_warrior_skill_used(player);
            switch (player->w_ability)
            {
                case W_SKILLS::MORTAL_STRIKE:
                    damage = 15 * 3;
                    break;
                
                case W_SKILLS::OVERPOWER:
                    damage = 10 * 3;
                    break;
                
                case W_SKILLS::EXECUTE:
                    damage = 15 * 5;
                    break;
                
                case W_SKILLS::REND:
                    damage = 10 * 2;
                    break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //WARRIOR CASE BREAK

        case PCLASSES::MAGE:
            get_mage_skill_used(player);
            switch (player->m_ability)
            {
                case M_SKILLS::ICE_BOLT:
                damage = 15 * 3;
                break;

                case M_SKILLS::FIREBLAST:
                damage = 15 * 3;
                break;
                
                case M_SKILLS::THUNDER:
                damage = 15 * 3;
                break;
                //but GRIIIIIM why have separate spells if they deal the same damage?!?
                //WAIT FOR FUTURE COMMITS >:(
                case M_SKILLS::ICE_BLOCK:
                damage = 0;
                break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //MAGE CASE BREAK

            case PCLASSES::ROGUE:
            get_rogue_skill_used(player);
            switch (player->r_ability)
            {
                case R_SKILLS::SLICE_AND_DICE:
                    damage = 15 * 3;
                    break;
                
                case R_SKILLS::KICK:
                    damage = 10 * 3;
                    break;
                
                case R_SKILLS::SABER_SLASH:
                    damage = 15 * 3;
                    break;
                
                case R_SKILLS::POISON_BOMB:
                    damage = 10 * 2;
                    break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //ROGUE CASE BREAK

            case PCLASSES::WARLOCK:
            get_warlock_skill_used(player);
            switch (player->wl_ability)
            {
                case WL_SKILLS::SHADOW_BOLT:
                    damage = 15 * 3;
                    break;
                
                case WL_SKILLS::BONE_DECAY:
                    damage = 15 * 2;
                    break;
                
                case WL_SKILLS::RAIN_OF_FIRE:
                    damage = 15 * 2;
                    break;
                
                case WL_SKILLS::SUMMON_DEMON:
                    damage = 15 * 5;
                    break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //WARLOCK CASE BREAK

            case PCLASSES::PRIEST:
            get_priest_skill_used(player);
            switch (player->p_ability)
            {
                case P_SKILLS::HEAL: //let me heal through violence? :D
                    damage = 0;      //NO
                    break;
                
                case P_SKILLS::DIA:
                    damage = 15 * 3;
                    break;
                
                case P_SKILLS::HOLY:
                    damage = 15 * 2;
                    break;
                
                case P_SKILLS::AERO:
                    damage = 15 * 3;
                    break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //PRIEST CASE BREAK
        default:
        cout << "No valid class was selected or some jank happened that made it fall through. Try ctrl+c and rerunning" << endl;
        break;
    }
    return damage;
}






//int deal_damage(int damage_dealt, int enemy_health);
//int take_damage(int player_health, int damage_taken);