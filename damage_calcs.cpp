#ifndef DAMAGE_CALCS_CPP
#define DAMAGE_CALCS_CPP

#include <iostream>
#include "PLAYER.h"
#include <string>
#include "helpers.cpp"
#include <string.h>
#include <optional>
#include <ctype.h>
#include <string_view>
#include <list>
using namespace std;


W_SKILLS get_warrior_skill_used(Player* player)
{
    if (player->kind != PCLASSES::WARRIOR) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "=========================================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "=========================================" << endl;
        get_warrior_skill_used(player);
    }
    else if (player->input == "1")
    {
        player->w_ability = W_SKILLS::MORTAL_STRIKE;
    }
    else if (player->input == "2"){
        player->w_ability = W_SKILLS::OVERPOWER;
    }
    else if (player->input == "3"){
        player->w_ability = W_SKILLS::EXECUTE;
    }
    else if (player->input == "4"){
        player->w_ability = W_SKILLS::REND;
    } else {
        cout << "not valid input" << endl;
        get_warrior_skill_used(player);
    }
    return player->w_ability;
}

M_SKILLS get_mage_skill_used(Player* player)
{
    if (player->kind != PCLASSES::MAGE) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_mage_skill_used(player);
    }
    else if (player->input == "1")
    {
        player->m_ability = M_SKILLS::ICE_BOLT;
    }
    else if (player->input == "2"){
        player->m_ability = M_SKILLS::FIREBLAST;
    }
    else if (player->input == "3"){
        player->m_ability = M_SKILLS::THUNDER;
    }
    else if (player->input == "4"){
        player->m_ability = M_SKILLS::ICE_BLOCK;
    } else {
        cout << "not valid input" << endl;
        get_mage_skill_used(player);
    }
    return player->m_ability;
}

R_SKILLS get_rogue_skill_used(Player* player)
{
    if (player->kind != PCLASSES::ROGUE) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_rogue_skill_used(player);
    }
    else if (player->input == "1")
    {
        player->r_ability = R_SKILLS::SLICE_AND_DICE;
    }
    else if (player->input == "2"){
        player->r_ability = R_SKILLS::KICK;
    }
    else if (player->input == "3"){
        player->r_ability = R_SKILLS::SABER_SLASH;
    }
    else if (player->input == "4"){
        player->r_ability = R_SKILLS::POISON_BOMB;
    } else {
        cout << "not valid input" << endl;
        get_rogue_skill_used(player);
    }
    return player->r_ability;
}

WL_SKILLS get_warlock_skill_used(Player* player)
{
    if (player->kind != PCLASSES::WARLOCK) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_warlock_skill_used(player);
    }
    else if (player->input == "1")
    {
        player->wl_ability = WL_SKILLS::SHADOW_BOLT;
    }
    else if (player->input == "2"){
        player->wl_ability = WL_SKILLS::BONE_DECAY;
    }
    else if (player->input == "3"){
        player->wl_ability = WL_SKILLS::RAIN_OF_FIRE;
    }
    else if (player->input == "4"){
        player->wl_ability = WL_SKILLS::SUMMON_DEMON;
    } else {
        cout << "not valid input" << endl;
        get_warlock_skill_used(player);
    }
    return player->wl_ability;
}//just using sample values for now - going to replace first values with stat numbers.

P_SKILLS get_priest_skill_used(Player* player)
{
    if (player->kind != PCLASSES::PRIEST) {
        exit(1);
    }
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_priest_skill_used(player);
    }
    else if (player->input == "1")
    {
        player->p_ability = P_SKILLS::HEAL;
    }
    else if (player->input == "2"){
        player->p_ability = P_SKILLS::DIA;
    }
    else if (player->input == "3"){
        player->p_ability = P_SKILLS::HOLY;
    }
    else if (player->input == "4"){
        player->p_ability = P_SKILLS::AERO;
    } else {
        cout << "not valid input" << endl;
        get_priest_skill_used(player);
    }
    return player->p_ability;
}


int calc_damage(Player* player)
{
    int damage = 0;
    switch (player->kind)
    {

        //WHY use dex or stats that won't be used later?
        //wait for later commits >:( They will be used while leveling if I implement it.
        case PCLASSES::WARRIOR:
            get_stats(player);
            get_warrior_skill_used(player);
            switch (player->w_ability)
            {
                case W_SKILLS::MORTAL_STRIKE:
                    damage = (player->stats.STR + player->stats.DEX) * 3;
                    break;                              
                
                case W_SKILLS::OVERPOWER:
                    damage = (player->stats.STR + (player->stats.DEX / 3)) * 3;
                    break;
                
                case W_SKILLS::EXECUTE:
                    damage = (player->stats.STR + player->stats.DEX) * 5;
                    break;
                //What's the point of the others then? Wait for future commit (mob implementation). IFYKYK.
                case W_SKILLS::REND:
                    damage = (player->stats.STR + (player->stats.DEX * .8)) * 2;
                    break; //Will be a DoT. another IFYKYK.
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //WARRIOR CASE BREAK

        case PCLASSES::MAGE:
            get_stats(player);
            get_mage_skill_used(player);
            switch (player->m_ability)
            {
                case M_SKILLS::ICE_BOLT:
                damage = (player->stats.INT + player->stats.WIS) * 2;
                break;

                case M_SKILLS::FIREBLAST:
                damage = (player->stats.INT + (player->stats.WIS * .6)) * 3;
                break;
                
                case M_SKILLS::THUNDER:
                damage = (player->stats.INT + (player->stats.WIS * .8)) * 2;
                break;
                //I got to this a lot faster than I expected, here's that commit(tm) you requested
                case M_SKILLS::ICE_BLOCK:
                damage = 0;
                break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //MAGE CASE BREAK

            case PCLASSES::ROGUE:
            get_stats(player);
            get_rogue_skill_used(player);
            switch (player->r_ability)
            {
                case R_SKILLS::SLICE_AND_DICE:
                    damage = (player->stats.DEX + (player->stats.STR * .2)) * 4;
                    break; //trying to emulate multiple slashes with one calc. Might try to make it ACTUALLY multiple later.
                
                case R_SKILLS::KICK:
                    damage = (player->stats.DEX + (player->stats.STR * .2)) * 2;
                    break; //yes this will be a stun. Again, IFYKYK.
                
                case R_SKILLS::SABER_SLASH:
                    damage = (player->stats.DEX + player->stats.STR) * 3;
                    break;
                
                case R_SKILLS::POISON_BOMB:
                    damage = (player->stats.DEX + (player->stats.STR * .8)) * 2;
                    break; //anotha DoT
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //ROGUE CASE BREAK

            case PCLASSES::WARLOCK:
            get_stats(player);
            get_warlock_skill_used(player);
            switch (player->wl_ability)
            {
                case WL_SKILLS::SHADOW_BOLT:
                    damage = (player->stats.INT + (player->stats.WIS / 2)) * 3;
                    break;
                
                case WL_SKILLS::BONE_DECAY:
                    damage = (player->stats.INT + (player->stats.WIS * .8)) * 2;
                    break; //DoT
                
                case WL_SKILLS::RAIN_OF_FIRE:
                    damage = (player->stats.INT + player->stats.WIS) * 2;
                    break;
                
                case WL_SKILLS::SUMMON_DEMON:
                    damage = (player->stats.INT + (player->stats.WIS)) * 5;
                    break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //WARLOCK CASE BREAK

            case PCLASSES::PRIEST:
            get_stats(player);
            get_priest_skill_used(player);
            switch (player->p_ability)
            {
                case P_SKILLS::HEAL: //let me heal through violence? :D
                    damage = 0;      //NO
                    break;
                
                case P_SKILLS::DIA:
                    damage = (player->stats.WIS + (player->stats.INT * .8)) * 2;
                    break; //DoT
                
                case P_SKILLS::HOLY:
                    damage = (player->stats.WIS + (player->stats.INT * .4)) * 2;
                    break;
                
                case P_SKILLS::AERO:
                    damage = (player->stats.WIS + (player->stats.INT / 2)) * 3;
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
    return (int)damage;
}



#endif


//int deal_damage(int damage_dealt, int enemy_health);
//int take_damage(int player_health, int damage_taken);