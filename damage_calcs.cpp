#ifndef DAMAGE_CALCS_CPP
#define DAMAGE_CALCS_CPP

#include <iostream>
#include "PLAYER.h"
#include "ENEMIES.h"
#include "helpers.cpp"
#include "player_building.cpp"
#include "enemy_building.cpp"
#include <optional>
#include <string>
#include <string_view>
#include <list>
using namespace std;


W_SKILLS get_warrior_skill_used(Player* player)
{
    if (player->kind != PCLASSES::WARRIOR) {
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
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
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
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
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
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
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
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
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
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


int calc_enemy_damage(Player* player, Enemy* enemy, Zone* zone)
{
    int damage = 0;
    using enum ENEMIES;
    
    switch (enemy->type)
    {
        case MURLOC:
        {
        int len = list_len(enemy->murloc_abilities);
        int num_get = get_rand_num(len);
        std::string ability = get_item(enemy->murloc_abilities, num_get);
        cout << "" << enemy->name << " attacks with: " << ability << endl;
        damage = 40;
        break;
        }

        case WOLF:
        {
            int len = list_len(enemy->wolf_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->wolf_atks, num_get);
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = 40;
            break;
        }

        case BANDIT:
        {
            int len = list_len(enemy->stnd_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->stnd_atks, num_get);
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = 40;
            break;
        }

        case E_MAGE:
        {
            int len = list_len(enemy->e_mage_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->e_mage_atks, num_get);
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = 40;
            break;
        }

        case W_ELEMENTAL:
        {
            int len = list_len(enemy->w_elemental_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->w_elemental_atks, num_get);
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = 40;
            break;
        }

        case MEGALOCRAB:
        {
            int len = list_len(enemy->crab_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->crab_atks, num_get);
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = 40;
            break; 
        }

        case FROGZARD:
        {
            int len = list_len(enemy->wolf_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->wolf_atks, num_get);
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = 40;
            break; 
        }
        
        case GREENGUARD_DRAGON:
        {
            int len = list_len(enemy->drgn_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->drgn_atks, num_get);
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = 40;
            break; 
        }
        default:
        cout << "unexpected error" << endl;
        break;
    }
    return damage;
}

int deal_damage(Enemy* enemy, int damage_dealt, int enemy_health)
{
    enemy_health -= damage_dealt;
    cout << "You dealt " << damage_dealt << " damage!" << endl;
    return enemy_health;
}
int take_damage(Player* player, int player_health, int damage_taken)
    {
    player_health -= damage_taken;
    cout << "You took " << damage_taken << " damage!" << endl;
    return player_health;
    }
void pre_enc(Player* player, Enemy* enemy, Zone* zone)
{
    get_enemy(player, enemy, zone);
    cout << "You have encountered a " << enemy->name << "!" << endl;
    get_enemy_stats(enemy);
    enemy->current_enemy_hp = enemy->e_stats.HP;
}

void encounter(Player* player, Enemy* enemy, Zone* zone)
{
    while (player->is_alive && enemy->is_alive)
   {    
        player->turn_taken = false;
        enemy->turn_taken = false;
        
        if (player->current_HP > 0 && player->turn_taken == false && enemy->current_enemy_hp > 0)
        {
            int damage_dealt = calc_damage(player);
            enemy->current_enemy_hp = deal_damage(enemy, damage_dealt, enemy->current_enemy_hp);
            if (enemy->current_enemy_hp <= 0) // you killed the enemy to death
            {
                enemy->current_enemy_hp = 0;
                cout << "You defeated the " << enemy->name << "!" << endl;
                enemy->is_alive = false;
                level_up(player);
                break;
            }
            cout << "" << enemy->name << "'s HP: " << enemy->current_enemy_hp << endl;
            player->turn_taken = true;
        }

        if (player->turn_taken == true && enemy->turn_taken == false && enemy->current_enemy_hp > 0)
        {
            int e_damage_dealt = calc_enemy_damage(player, enemy, zone);
            player->current_HP = take_damage(player, player->current_HP, e_damage_dealt);
            if (player->current_HP <= 0) //you died to death
            {
                player->current_HP = 0;
                player->is_alive = false;
                cout << "You died! Game over" << endl;
                break;
            }
            cout << "" << player->name << "'s HP: " << player->current_HP << endl;
            enemy->turn_taken = true;
        }
    }
}
#endif