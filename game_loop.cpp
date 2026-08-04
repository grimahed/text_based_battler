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

void game_loop(Player* player, Enemy* enemy, Zone* zone)
{
    //I mean, the game just started, there's no way for you to be dead yet.
    //No I'm not counting modifying the code yourself as an exception to that logic.
    pre_enc(player, enemy, zone);
    encounter(player, enemy, zone);
    while (player->is_alive)
    {
        cout << "Current HP: " << player->current_HP << "\n-------------------------------------------" << endl;
        cout << "Choose an option between:\n (1) Continue | (2) Be healed by a Priest and continue | (3) exit the game"
                << "\n=========================================\n" << endl;
        std::cout << "" << endl;
        std::getline(cin, player->input);
        if (only_whitespace(player->input))
        {
            cout << "choose an option dude\n" << "=========================================" << endl;
        } else if (player->input == "1")
        {
            delete enemy;
            Enemy* enemy = new Enemy();
            system("clear");
            game_loop(player, enemy, zone);
        } else if (player->input == "2")
        {
            system("clear");
            player->current_HP += player->stats.HP / .8;
            if (player->current_HP > player->stats.HP)
            {
                player->current_HP = player->stats.HP;}
                cout << "A priest heals you, you now have " << player->current_HP << "HP\n"
                << "=========================================\n" 
                << "The next encounter will now start!" << endl;
                delete enemy;
                Enemy* enemy = new Enemy();
                player->ice_cubed = false;
                game_loop(player, enemy, zone);
            }
                else if (player->input == "3"){exit(1);
            } else {cout << "invalid input" << endl;}
        }
    }