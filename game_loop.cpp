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
    while (player->is_alive)
    {
        pre_enc(player, enemy, zone);
        encounter(player, enemy, zone);
        cout << "Choose an option between:\n (1) Continue | (2) Be healed by a Priest | (3) exit the game"
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
            game_loop(player, enemy, zone);
        } else if (player->input == "2")
        {
            player->current_HP += player->stats.HP / .8;
            if (player->current_HP > player->stats.HP)
            {
                player->current_HP = player->stats.HP;}
                cout << "A priest heals you, you now have " << player->current_HP << "HP\n"
                << "=========================================\n" 
                << "The next encounter will now start!" << endl;
                delete enemy;
                Enemy* enemy = new Enemy();
                game_loop(player, enemy, zone);
            }
                else if (player->input == "3"){exit(1);}
        }
    }