#include <iostream>
#include "PLAYER.h"
#include "helpers.cpp"
#include "player_building.cpp"
#include "enemy_building.cpp"
#include "damage_calcs.cpp"
#include <optional>
#include <string>
#include <string_view>
#include <list>

void pre_enc(Player* player, Enemy* enemy, Zone* zone)
{
    get_enemy(player, enemy, zone);
    cout << "You have encountered a " << enemy->name << "!" << endl;
    cout << "-------------------------------------------" << endl;
    get_enemy_stats(enemy);
    level_enemy(player, enemy);
    enemy->current_enemy_hp = enemy->e_stats.HP;
    
}

void encounter(Player* player, Enemy* enemy, Zone* zone)
{
    player->s_bolt_cnt = 0; //resetting buff count to zero
    enemy->ripe_for_execution = false; //making sure this doesn't linger
    while (player->is_alive && enemy->is_alive)
   {    
        if (player->kind == PCLASSES::WARRIOR && enemy->current_enemy_hp <= (int)enemy->e_stats.HP * .35)
        {
            enemy->ripe_for_execution = true;
            cout << "Enemy is ripe for execution!\n" << "=========================================\n" << endl;
        }

        //condition checks
        if (player->ice_cubed) {player->ice_cubed = false;}

        if (enemy->dot_count > 0) {enemy->dot_count--;}
        else if (enemy->dot_count == 0) {enemy->has_dot = false; enemy->dot_dmg = 0;}

        if (enemy->brn_count > 0) {enemy->brn_count--;}
        else if (enemy->brn_count == 0) {enemy->has_burns = false; enemy->burn_dmg = 0;}

        if (enemy->stun_count > 0) {enemy->stun_count--;}
        else if (enemy->stun_count <= 0) {enemy->is_stunned = false;}

        if (enemy->cubed_counter > 0) {enemy->cubed_counter--;}
        else if (enemy->cubed_counter <= 0) {enemy->is_cubed = false;}

        //bool resets
        player->non_damage_used = false;
        enemy->non_damage_s_used = false;
        player->turn_taken = false;
        enemy->turn_taken = false;
        //===========================

        if (player->current_HP > 0 && player->turn_taken == false && enemy->current_enemy_hp > 0)
        {
            int damage_dealt = calc_damage(player, enemy);

            enemy->current_enemy_hp = deal_damage(player, enemy, damage_dealt, enemy->current_enemy_hp);
            enemy->current_enemy_hp = place_dot(player, enemy, enemy->dot_dmg, enemy->burn_dmg, enemy->current_enemy_hp);
            print_total_dmg(enemy->dot_dmg, enemy->burn_dmg, damage_dealt, enemy);
            
            // you killed the enemy to death
            if (enemy->current_enemy_hp <= 0)
            {
                enemy->current_enemy_hp = 0;
                std::cout << "\033[2J\033[1;1H";
                cout << "You defeated the " << enemy->name << "!" << endl;
                cout << "-------------------------------------------" << endl;
                enemy->is_alive = false;
                level_up(player);
                break;
            }
            cout << "" << enemy->name << "'s HP: " << enemy->current_enemy_hp << endl;
            cout << "-------------------------------------------" << endl;
            player->turn_taken = true;
        }

        if (player->turn_taken == true && enemy->is_stunned == false && enemy->turn_taken == false && enemy->current_enemy_hp > 0)
        {
            int e_damage_dealt = calc_enemy_damage(player, enemy, zone);
            player->current_HP = take_damage(player, enemy, player->current_HP, e_damage_dealt);

            //you died to death
            if (player->current_HP <= 0)
            {
                player->current_HP = 0;
                player->is_alive = false;
                std::cout << "\033[2J\033[1;1H";
                cout << "You took " << e_damage_dealt << " damage!\n";
                cout << "" << enemy->name << "'s HP: " << enemy->current_enemy_hp << endl;
                cout << "" << player->name << "'s HP: " << player->current_HP << endl;
                cout << "You died! Game over." << endl;
                delete player;
                player = nullptr;
                exit(1);
            }
            cout << "" << enemy->name << "'s HP: " << enemy->current_enemy_hp << endl;
            cout << "" << player->name << "'s HP: " << player->current_HP << endl;
            enemy->turn_taken = true;
        }
    }
}

void game_loop(Player* player, Enemy* enemy, Zone* zone)
{
    //I mean, the game just started, there's no way for you to be dead yet.
    //No I'm not counting modifying the code yourself as an exception to that logic.
    pre_enc(player, enemy, zone);
    encounter(player, enemy, zone);
    while (player->is_alive)
    {
        //back to business
        cout << "Current HP: " << player->current_HP << "\n-------------------------------------------" << endl;
        if (player->level == 10) 
    {
        player->GG_unlocked = true;
        cout << "You have unlocked the Greenguard zone!\n\n" << "Beware the dragon...\n" << "=========================================" << endl;
    
    }
    
        cout << "Choose an option between:\n (1) Continue | (2) Be healed by a Priest and continue | (3) Be healed and swap Zones | (4) exit the game"
                << "\n=========================================\n" << endl;
        std::cout << "" << endl;
        std::getline(cin, player->input);
        if (only_whitespace(player->input))
        {
            cout << "choose an option dude\n" << "=========================================" << endl;
        } else if (player->input == "1")
        {
            delete enemy;
            enemy = nullptr;
            Enemy* enemy = new Enemy();
            std::cout << "\033[2J\033[1;1H";;
            game_loop(player, enemy, zone);
        } else if (player->input == "2")
        {
            std::cout << "\033[2J\033[1;1H";;
            player->current_HP += player->stats.HP / .8;
            if (player->current_HP > player->stats.HP)
            {
                player->current_HP = player->stats.HP;}
                cout << "A priest heals you, you now have " << player->current_HP << "HP\n"
                << "=========================================\n" << endl;
                delete enemy;
                enemy = nullptr;
                Enemy* enemy = new Enemy();
                player->ice_cubed = false;
                game_loop(player, enemy, zone);
            } else if  (player->input == "3")
            {
                get_zone(player);
                std::cout << "\033[2J\033[1;1H";;
                player->current_HP += player->stats.HP / .8;
                if (player->current_HP > player->stats.HP)
                {
                    player->current_HP = player->stats.HP;}
                    cout << "A priest heals you, you now have " << player->current_HP << "HP\n"
                    << "=========================================\n" << endl;
                    delete enemy;
                    enemy = nullptr;
                    Enemy* enemy = new Enemy();
                    player->ice_cubed = false;
                    game_loop(player, enemy, zone);
            }
                else if (player->input == "4"){exit(1);
            } else {cout << "invalid input" << endl;}
        }
    }