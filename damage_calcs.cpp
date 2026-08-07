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


W_SKILLS get_warrior_skill_used(Player* player, Enemy* enemy)
{
   using enum W_SKILLS;

    //execution rng code
    if (player->kind != PCLASSES::WARRIOR) {
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
    }
    int rand_num = get_rand_num(5);
    if (enemy->ripe_for_execution || rand_num == 3)
    {
        class_abilities(player);
    } else {
       player->ability_list = {"Mortal Strike", "Overpower", "Rend"};
    }

    //ability selection
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "=========================================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    std:string shrinka_da_text = make_lower(player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "=========================================" << endl;
        get_warrior_skill_used(player, enemy);
    }
    else if (player->input == "1" || shrinka_da_text== "mortal strike")
    {
        player->w_ability = MORTAL_STRIKE;
    }
    else if (player->input == "2" || shrinka_da_text == "overpower"){
        player->w_ability = OVERPOWER;
    }
    else if (player->input == "3" || shrinka_da_text == "rend"){
        player->w_ability = REND;
    }
    else if ((enemy->ripe_for_execution || rand_num == 3) && (player->input == "4" || shrinka_da_text == "execute")){
        player->w_ability = EXECUTE;
    } else {
        cout << "not valid input" << endl;
        get_warrior_skill_used(player, enemy);
    }
    return player->w_ability;
}

M_SKILLS get_mage_skill_used(Player* player)
{
    using enum M_SKILLS;

    if (player->kind != PCLASSES::MAGE) {
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
    }
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    std::string shrinka_da_text = make_lower(player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_mage_skill_used(player);
    }
    else if (player->input == "1" || shrinka_da_text == "ice bolt")
    {
        player->m_ability = ICE_BOLT;
    }
    else if (player->input == "2" || shrinka_da_text == "fireblast")
    {
        player->m_ability = FIREBLAST;
    }
    else if (player->input == "3" || shrinka_da_text == "thunder"){
        player->m_ability = THUNDER;
    }
    else if (player->input == "4" || shrinka_da_text == "ice block"){
        player->m_ability = ICE_BLOCK;
    } else {
        cout << "not valid input" << endl;
        get_mage_skill_used(player);
    }
    return player->m_ability;
}

R_SKILLS get_rogue_skill_used(Player* player)
{
    using enum R_SKILLS;
    if (player->kind != PCLASSES::ROGUE) {
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
    }
    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    std::string shrinka_da_text = make_lower(player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_rogue_skill_used(player);
    }
    else if (player->input == "1" || shrinka_da_text == "slice and dice")
    {
        player->r_ability = SLICE_AND_DICE;
    }
    else if (player->input == "2" || shrinka_da_text == "kick"){
        player->r_ability = KICK;
    }
    else if (player->input == "3" || shrinka_da_text == "saber slash"){
        player->r_ability = SABER_SLASH;
    }
    else if (player->input == "4" || shrinka_da_text == "poison bomb"){
        player->r_ability = POISON_BOMB;
    } else {
        cout << "not valid input" << endl;
        get_rogue_skill_used(player);
    }
    return player->r_ability;
}

WL_SKILLS get_warlock_skill_used(Player* player)
{
    using enum WL_SKILLS;

    if (player->kind != PCLASSES::WARLOCK) {
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
    }

    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    std::string shrinka_da_text = make_lower(player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_warlock_skill_used(player);
    }
    else if (player->input == "1" || shrinka_da_text == "shadow bolt")
    {
        player->wl_ability = SHADOW_BOLT;
    }
    else if (player->input == "2" || shrinka_da_text == "bone decay"){
        player->wl_ability = BONE_DECAY;
    }
    else if (player->input == "3" || shrinka_da_text == "rain of fire"){
        player->wl_ability = RAIN_OF_FIRE;
    }
    else if (player->input == "4" || shrinka_da_text == "summon demon"){
        player->wl_ability = SUMMON_DEMON;
    } else {
        cout << "not valid input" << endl;
        get_warlock_skill_used(player);
    }
    return player->wl_ability;
}//just using sample values for now - going to replace first values with stat numbers.

P_SKILLS get_priest_skill_used(Player* player)
{
    using enum P_SKILLS;

    if (player->kind != PCLASSES::PRIEST) {
        cout << "Unexpected error, reselect the class" << endl;
        get_class(player);
    }

    cout << "Select an ability to use from: " << print_list(player->ability_list) << "\n" << "==========================\n";
    std::cout << "" << std::endl;
    std::getline(cin, player->input);
    std::string shrinka_da_text = make_lower(player->input);
    cout << "=========================================" << endl;
    if (only_whitespace(player->input))
    {
        cout << "Do you *want* to die?\n" << "==========================" << endl;
        get_priest_skill_used(player);
    }
    else if (player->input == "1" || shrinka_da_text == "heal")
    {
        player->p_ability = HEAL;
    }
    else if (player->input == "2" || shrinka_da_text == "dia"){
        player->p_ability = DIA;
    }
    else if (player->input == "3" || shrinka_da_text == "holy"){
        player->p_ability = HOLY;
    }
    else if (player->input == "4" || shrinka_da_text == "aero"){
        player->p_ability = AERO;
    } else {
        cout << "not valid input" << endl;
        get_priest_skill_used(player);
    }
    return player->p_ability;
}

int calc_damage(Player* player, Enemy* enemy)
{
    int damage = 0;
    using enum PCLASSES;
    using enum W_SKILLS;
    using enum M_SKILLS;
    using enum R_SKILLS;
    using enum WL_SKILLS;
    using enum P_SKILLS; 
    switch (player->kind)
    {
        case WARRIOR:
            get_warrior_skill_used(player, enemy);
            switch (player->w_ability)
            {
                case MORTAL_STRIKE:
                    damage = (player->stats.STR + player->stats.DEX) * 3;
                    break;                              
                
                case OVERPOWER:
                {   damage = (player->stats.STR + (player->stats.DEX / 3)) * 3;
                    int rand_numba = get_rand_num(4);
                    if (rand_numba == 1)
                    {enemy->ripe_for_execution = true;}
                    if (enemy->ripe_for_execution)
                    {cout << "overpower procced execute!" << endl;}
                    break;
                }
                case EXECUTE:
                    damage = (player->stats.STR + player->stats.DEX) * 7;
                    break;
                //Now with code to fulfill your murder hobo dopamine hits!
                case REND:
                    damage = (player->stats.STR + (player->stats.DEX * .8)) * 2;
                    enemy->dot_dmg = (int)(player->stats.STR + (player->stats.DEX / 2) * 1.5);
                    enemy->has_dot = true;
                    enemy->dot_count = 2;
                    break;

                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //WARRIOR CASE BREAK

        case MAGE:
            get_mage_skill_used(player);
            switch (player->m_ability)
            {
                case ICE_BOLT:
                damage = (player->stats.INT + player->stats.WIS) * 2;
                cout << "" << enemy->name << " is weaker to fire damage temporarily!" << endl;
                enemy->is_cubed = true;
                enemy->cubed_counter = 2;
                break;

                case FIREBLAST:
                damage = (player->stats.INT + (player->stats.WIS * .6)) * 3;
                if (enemy->is_cubed) {damage *= 2;}
                break;
                
                case THUNDER:
                damage = (player->stats.INT + (player->stats.WIS * .8)) * 2;
                enemy->dot_dmg = (int)(player->stats.INT + (player->stats.WIS / 2) * 1.5);
                enemy->has_dot = true;
                enemy->dot_count = 3;
                break;

                case ICE_BLOCK:
                damage = 0;
                player->ice_cubed = true;
                player->non_damage_used = true;
                break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //MAGE CASE BREAK

            case ROGUE:
            get_rogue_skill_used(player);
            switch (player->r_ability)
            {
                case SLICE_AND_DICE:
                    damage = (player->stats.DEX + (player->stats.STR * .2)) * 4;
                    break; //trying to emulate multiple slashes with one calc. Might try to make it ACTUALLY multiple later.
                           //yeah the idea got scrapped lol. Feel free to do it yourself though. Simple for loop should do it.
                case KICK:
                    damage = (player->stats.DEX + (player->stats.STR * .2)) * 2;
                    cout << "" << enemy->name << " is stunned temporarily!" << endl;
                    enemy->is_stunned = true;
                    enemy->stun_count = 1;
                    break; //yes this will be a stun. Again, IFYKYK.
                
                case SABER_SLASH:
                    damage = (player->stats.DEX + player->stats.STR) * 3;
                    break;
                
                case POISON_BOMB:
                    damage = (player->stats.DEX + (player->stats.STR * .8)) * 2;
                    enemy->dot_dmg = (int)(player->stats.DEX + (player->stats.STR / 2) * 1.5);
                    enemy->has_dot = true;
                    enemy->dot_count = 4;
                    break; //anotha one
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //ROGUE CASE BREAK

            case WARLOCK:
            get_warlock_skill_used(player);
            switch (player->wl_ability)
            {
                case SHADOW_BOLT:
                    damage = (player->stats.INT + (player->stats.WIS)) * 2;
                    player->s_bolt_cnt++;

                    if (player->s_bolt_cnt == 2) 
                    {
                        player->sd_buff_rdy = true;
                        cout << "Your next summon demon now does double damage!" << endl;
                    }
                    break;
                
                case BONE_DECAY:
                    damage = (player->stats.INT + (player->stats.WIS * .8)) * 3;
                    enemy->dot_dmg = (int)(player->stats.INT + player->stats.WIS) * 1.5;
                    enemy->has_dot = true;
                    enemy->dot_count = 4;
                    break;
                
                case RAIN_OF_FIRE:
                    damage = (player->stats.INT + player->stats.WIS) * 3;
                    enemy->has_burns = true;
                    enemy->burn_dmg = (int)(player->stats.INT + (player->stats.WIS) * 1.5);
                    enemy->brn_count = 3;
                    break;
                
                case SUMMON_DEMON:
                    cout << "You summon a powerful demon!" << endl; //but it's the blueberry from WoW, they've been hitting the gym.
                    damage = (player->stats.INT + (player->stats.WIS)) * 5;
                    if (player->sd_buff_rdy) 
                    {
                        damage *= 2; 
                        player->sd_buff_rdy = false; 
                        player->s_bolt_cnt = 0;
                    }
                    break;
                default:
                    cout << "unexpected error. oopsie~" << endl;
                    break;
            }
            break; //WARLOCK CASE BREAK

            case PRIEST:
            get_priest_skill_used(player);
            switch (player->p_ability)
            {
                case HEAL: //let me heal through violence? :D
                {   damage = 0;      //NO
                    int amount_healed = player->stats.HP * .8;
                    player->current_HP += amount_healed;
                    if (player->current_HP > player->stats.HP)
                    {
                        player->current_HP = player->stats.HP;
                    }
                    cout << "You healed yourself for " << amount_healed << "!" << endl;
                    break;
                }
                
                case DIA:
                    damage = (player->stats.WIS + (player->stats.INT * .8)) * 2;
                    enemy->dot_dmg = (int)(player->stats.WIS + (player->stats.INT / 2) * 1.5);
                    enemy->has_dot = true;
                    enemy->dot_count = 3;
                    break; //DoT
                
                case HOLY: // I was going to make multi mob encounters possible, and this aoe. Maybe down the road.
                    damage = (player->stats.WIS + (player->stats.INT * .4)) * 2; //but to lower the scope, not for now.
                    cout << "" << enemy->name << " is stunned temporarily!" << endl;
                    enemy->is_stunned = true;
                    enemy->stun_count = 1;
                    break; //feel free to add them yourself though! Till then this is single target.
                
                case AERO:
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
        
        if (num_get == 1) //attack
        {
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = (enemy->e_stats.STR + (enemy->e_stats.DEX * .8)) * 2;

        } else if (num_get == 2) //Water
        {
            cout << "" << enemy->name << " attacks with: " << ability << endl;
            damage = (enemy->e_stats.INT + (enemy->e_stats.WIS * .6)) * 3;
        } else if (num_get == 3) //Heal case
        {
            cout << "" << enemy->name << " Heals with: " << ability << endl;
            enemy->non_damage_s_used = true;
            enemy->current_enemy_hp += enemy->e_stats.HP * .4;
            if (enemy->current_enemy_hp > enemy->e_stats.HP) //HP regulation
            {enemy->current_enemy_hp = enemy->e_stats.HP;}
            cout << "The " << enemy->name << "'s HP is now " << enemy->current_enemy_hp << endl;
            cout << "-------------------------------------------" << endl;

        } else {cout << "Unexpected error" << endl;}
        break;
        }

        case WOLF:
        {
            int len = list_len(enemy->wolf_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->wolf_atks, num_get);
            //attack
            if (num_get == 1) {damage = (enemy->e_stats.STR + (enemy->e_stats.DEX * .8)) * 2;} 
            //bite
            else if (num_get == 2) {damage = (enemy->e_stats.STR + (enemy->e_stats.DEX * .4)) * 2;} 
            //deadlier bite
            else if (num_get == 3) {damage = (enemy->e_stats.STR + enemy->e_stats.DEX) * 3;}
            //slash
            else if (num_get == 4){damage = (enemy->e_stats.STR + (enemy->e_stats.DEX + 2)) * 3;} 
            else {cout << "unexpected error" << endl;}

            cout << "" << enemy->name << " attacks with: " << ability << endl;
            break;
        }

        case BANDIT:
        {
            int len = list_len(enemy->bandit_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->bandit_atks, num_get);
            
            //bonque
            if (num_get == 1) {damage = (enemy->e_stats.STR + (enemy->e_stats.DEX * .6)) * 2;}
            //Eviscerate
            else if (num_get == 2) {damage = (enemy->e_stats.STR + enemy->e_stats.DEX) * 3;}
            //Stab
            else if (num_get == 3) {damage = (enemy->e_stats.STR + (enemy->e_stats.DEX * .4)) * 2.5;} 
            //Not so casted punch
            else if (num_get == 4) {damage = (enemy->e_stats.STR + enemy->e_stats.DEX) * 3;} 
            else {cout << "Unexpected error";}

            cout << "" << enemy->name << " attacks with: " << ability << endl;
            break;
        }

        case E_MAGE:
        {
            int len = list_len(enemy->e_mage_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->e_mage_atks, num_get);
            //bonk
            if (num_get == 1) {damage = (enemy->e_stats.INT + (enemy->e_stats.WIS * .6)) * 2;} 
            //fire
            else if (num_get == 2) {damage = (enemy->e_stats.INT + (enemy->e_stats.WIS * .4)) * 3;} 
            //water
            else if (num_get == 3) {damage = (enemy->e_stats.INT + enemy->e_stats.WIS * .2) * 3;}
            //gust
            else if (num_get == 4){damage = (enemy->e_stats.INT + enemy->e_stats.WIS) * 3;} 
            else {cout << "unexpected error" << endl;}

            cout << "" << enemy->name << " attacks with: " << ability << endl;
            break;
        }

        case W_ELEMENTAL:
        {
            int len = list_len(enemy->w_elemental_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->w_elemental_atks, num_get);
            
            //standard attack
            if (num_get == 1) {damage = enemy->e_stats.INT + (enemy->e_stats.WIS * .6) * 2;}
            //Dowse
            else if (num_get == 2){damage = enemy->e_stats.INT + (enemy->e_stats.WIS * .6) * 3;}
            //Torrent case
            else if (num_get == 3){damage = (enemy->e_stats.INT + enemy->e_stats.WIS) * 3;} 
            else {cout << "unexpected error" << endl;}

            cout << "" << enemy->name << " attacks with: " << ability << endl;
            break;
            }

        case MEGALOCRAB:
        {
            int len = list_len(enemy->crab_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->crab_atks, num_get);

            //Pincer
            if (num_get == 1){damage = enemy->e_stats.STR + (enemy->e_stats.DEX * .8) * 2;}
            //Pound and Toss
            else if (num_get == 2){damage = enemy->e_stats.STR + (enemy->e_stats.DEX * .6) * 3;} 
            //Water Torrent
            else if (num_get == 3){damage = (enemy->e_stats.INT + enemy->e_stats.WIS) * 3;}
            else {cout << "unexpected error" << endl;}

            cout << "" << enemy->name << " attacks with: " << ability << endl;
            break; 
        }

        case FROGZARD:
        {
            int len = list_len(enemy->frogzard_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->frogzard_atks, num_get);
            
            //attack
            if (num_get == 1) {damage = (enemy->e_stats.STR + (enemy->e_stats.DEX *.8)) * 2;} 
            //deadlier bite
            else if (num_get == 2) {damage = (enemy->e_stats.STR + enemy->e_stats.DEX) * 2;} 
            //gouge
            else if (num_get == 3) {damage = (enemy->e_stats.STR + enemy->e_stats.DEX) * 3;}
            //shred
            else if (num_get == 4){damage = (enemy->e_stats.STR + (enemy->e_stats.DEX + 2)) * 3;} 
            else {cout << "unexpected error" << endl;}

            cout << "" << enemy->name << " attacks with: " << ability << endl;
            break;
            }
        
        case GREENGUARD_DRAGON:
        {
            int len = list_len(enemy->drgn_atks);
            int num_get = get_rand_num(len);
            std::string ability = get_item(enemy->drgn_atks, num_get);

            //standard attack
            if (num_get == 1)
            {damage = (enemy->e_stats.STR + (enemy->e_stats.DEX * .8)) * 2;} 
            //breathe fire
            else if (num_get == 2){damage = (enemy->e_stats.INT + (enemy->e_stats.WIS * .4)) * 2;}
            //Icy Breathe
            else if (num_get == 3){damage = (enemy->e_stats.INT + enemy->e_stats.WIS) * 3;}
            //Fly and Swipe
            else if (num_get == 4){damage = (enemy->e_stats.STR + (enemy->e_stats.DEX + 2)) * 3;} 
            //Chomp
            else if (num_get == 5){damage = (enemy->e_stats.STR + (enemy->e_stats.DEX)) * 3;}
            else {cout << "unexpected error" << endl;}

            cout << "" << enemy->name << " attacks with: " << ability << endl;
            break;
        }
        default:
        cout << "unexpected error" << endl;
        break;
        }
    return (int)damage;
}

int deal_damage(Player* player, Enemy* enemy, int damage_dealt, int enemy_health)
{
    if (player->non_damage_used == true)
        {
            return enemy_health;
        } else
    {
    enemy_health -= damage_dealt;
    cout << "You dealt " << damage_dealt << " damage!" << endl;
    cout << "-------------------------------------------" << endl;
    }
    return enemy_health;
}

int place_dot(Player* player, Enemy* enemy, int dot_dmg, int brn_dmg, int enemy_health)
{
    if (enemy->has_dot && enemy->dot_count > 0)
    {
        enemy_health -= dot_dmg;
        cout << "Your DoT dealt: " << dot_dmg << " damage!" << endl;
        cout << "-------------------------------------------" << endl;
    }

    if (enemy->has_burns && enemy->brn_count > 0)
    {
        enemy_health -= brn_dmg;
        cout << "Enemy's burns dealt: " << brn_dmg << " damage!" << endl;
        cout << "-------------------------------------------" << endl;
    }
    return enemy_health;
}

void print_total_dmg(int dot_dmg, int brn_dmg, int damage_dealt, Enemy* enemy)
{
    cout << "Total damage to " << enemy->name << ": " << damage_dealt + dot_dmg + brn_dmg << endl;
    cout << "-------------------------------------------" << endl;
}

int take_damage(Player* player, Enemy* enemy, int player_health, int damage_taken)
    {
    if (enemy->non_damage_s_used == false)
        {if (player->kind == PCLASSES::MAGE && player->ice_cubed) 
        {
            damage_taken = 0;
            player_health += player->stats.HP;
            if (player_health > player->stats.HP)
            {player_health = player->stats.HP;}
            cout << "You nullified the attack and healed yourself to full!\n" << 
            "-------------------------------------------" << endl;
        } else {
        player_health -= damage_taken;
        cout << "You took " << damage_taken << " damage!" << endl;}
        cout << "-------------------------------------------" << endl;
    }
    return player_health;
}
#endif