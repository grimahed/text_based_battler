#ifndef ENEMY_BUILDING_CPP
#define ENEMY_BUILDING_CPP

#include <iostream>
#include "PLAYER.h"
#include "ENEMIES.h"
#include "player_building.cpp"
#include "helpers.cpp"
#include <optional>
#include <string>
#include <string_view>
#include <list>
#include <random>
using namespace std;

ENEMIES get_enemy(Player* player, Enemy* enemy, Zone* zone)
{
    using enum ZONES;
    using enum ENEMIES;
    switch (player->current_zone)
    {
        case ELWYNN_FOREST:
        {
            zone->enemy_list = {"Murloc", "Wolf", "Bandit", "Mean Mage"};
            int rand_num = get_rand_num(4);
            if (rand_num == 1)
            {
                enemy->name = "Murloc";
                enemy->type = MURLOC;
            } 
            else if (rand_num == 2)
            {
                enemy->name = "Wolf";
                enemy->type = WOLF;
            }
            else if (rand_num == 3)
            {
                enemy->name = "Bandit";
                enemy->type = BANDIT;
            }
            else if (rand_num == 4)
            {
                enemy->name = "Mean Mage";
                enemy->type = E_MAGE;
            }
        break; // Elwynn case break
        } 
        case ZORAVIA:
            {
                zone->enemy_list = {"Murloc", "Water Elemental", "Megalocrab", "Mean Mage"};//but water! but don't feel like making another list rn
                int rand_num = get_rand_num(4);
                if (rand_num == 1)
                {
                    enemy->name = "Murloc";
                    enemy->type = MURLOC;
                } 
                else if (rand_num == 2)
                {
                    enemy->name = "Water Elemental";
                    enemy->type = W_ELEMENTAL;
                }
                else if (rand_num == 3)
                {
                    enemy->name = "Megalocrab";
                    enemy->type = MEGALOCRAB;
                }
                else if (rand_num == 4)
                {
                    enemy->name = "Mean Mage";
                    enemy->type = E_MAGE;
                }
            break; // zoravia case break
        } 
        case GREENGUARD:
            {
                zone->enemy_list = {"Frogzard", "Direwolf", "Bandit", "Mean Mage", "Greenguard Dragon"};//but water! but don't feel like making another list rn
                int rand_num = get_rand_num(5);
                if (rand_num == 1)
                {
                    enemy->name = "Murloc";
                    enemy->type = MURLOC;
                } 
                else if (rand_num == 2)
                    {
                        enemy->name = "Water Elemental";
                        enemy->type = W_ELEMENTAL;
                    }
                    else if (rand_num == 3)
                    {
                        enemy->name = "Bandit";
                        enemy->type = BANDIT;
                    }
                    else if (rand_num == 4)
                    {
                        enemy->name = "Mean Mage";
                        enemy->type = E_MAGE;
                    }
                    else if (rand_num == 5)
                    {
                        enemy->name = "Greenguard Dragon";
                        enemy->type = GREENGUARD_DRAGON;
                    }
                    else{
                        cout << "unexpected error" << endl;
                    }
                break; // greenguard case break
                }
            }
    return enemy->type;
}

en_stats get_enemy_stats(Enemy* enemy){
    using enum ENEMIES;
    switch (enemy->type)
    {
        case MURLOC:

            enemy->e_stats.HP = 275;
            enemy->e_stats.STR = 12;
            enemy->e_stats.DEX = 12;
            enemy->e_stats.INT = 14;
            enemy->e_stats.WIS = 12;
            break;
        
        
        case WOLF:
        
            enemy->e_stats.HP = 300;
            enemy->e_stats.STR = 12;
            enemy->e_stats.DEX = 16;
            enemy->e_stats.INT = 10;
            enemy->e_stats.WIS = 10;
            break;
        
        case E_MAGE:

            enemy->e_stats.HP = 300;
            enemy->e_stats.STR = 10;
            enemy->e_stats.DEX = 10;
            enemy->e_stats.INT = 17;
            enemy->e_stats.WIS = 13;
            break;

        case FROGZARD:
            enemy->e_stats.HP = 300;
            enemy->e_stats.STR = 12;
            enemy->e_stats.DEX = 16;
            enemy->e_stats.INT = 10;
            enemy->e_stats.WIS = 10;
            break;

        case GREENGUARD_DRAGON:
            enemy->e_stats.HP = 700;
            enemy->e_stats.STR = 24;
            enemy->e_stats.DEX = 24;
            enemy->e_stats.INT = 20;
            enemy->e_stats.WIS = 26;
            break;

        case W_ELEMENTAL:

            enemy->e_stats.HP = 300;
            enemy->e_stats.STR = 10;
            enemy->e_stats.DEX = 10;
            enemy->e_stats.INT = 17;
            enemy->e_stats.WIS = 18;
            break;

        case BANDIT:

            enemy->e_stats.HP = 500;
            enemy->e_stats.STR = 14;
            enemy->e_stats.DEX = 20;
            enemy->e_stats.INT = 10;
            enemy->e_stats.WIS = 10;
            break;

        case MEGALOCRAB:
            enemy->e_stats.HP = 500;
            enemy->e_stats.STR = 18;
            enemy->e_stats.DEX = 16;
            enemy->e_stats.INT = 10;
            enemy->e_stats.WIS = 10;
            break;
    }
    return enemy->e_stats;
}

void print_enemy_info(Enemy* enemy)
{
    using enum ENEMIES;
    switch (enemy->type)
    {
        case MURLOC:
            cout << "Enemy: Murloc" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case WOLF:
            cout << "Enemy: Wolf" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case E_MAGE:
            cout << "Enemy: Mean Mage" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case BANDIT:
            cout << "Enemy: Bandit" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case FROGZARD:
            cout << "Enemy: Frogzard" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;

        case W_ELEMENTAL:
            cout << "Enemy: Water Elemental" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;

        case MEGALOCRAB:
            cout << "Enemy: Megalocrab" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;

        case GREENGUARD_DRAGON:
            cout << "Enemy: Greenguard Dragon" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << enemy->e_stats.HP << "\n";
            cout << "STR: " << enemy->e_stats.STR << "\n";
            cout << "DEX: " << enemy->e_stats.DEX << "\n";
            cout << "INT: " << enemy->e_stats.INT << "\n";
            cout << "WIS: " << enemy->e_stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        default:
            break;
    }
}
en_stats level_enemy(Player* player, Enemy* enemy)
{
    using enum ENEMIES;

    switch (enemy->type)
    {
                case MURLOC:
                {
                    for (int i = 1; i <= player->level; i++)
                    {
                        enemy->e_stats.HP += 75;
                        enemy->e_stats.STR += get_rand_num(2);
                        enemy->e_stats.DEX += get_rand_num(2);
                        enemy->e_stats.INT += get_rand_num(2);
                        enemy->e_stats.WIS += get_rand_num(2);
                        enemy->e_level = i;
                    }
                    break;
                }
                case WOLF:
                {
                    for (int i = 1; i != player->level; i++)
                    {
                        enemy->e_stats.HP += 125;
                        enemy->e_stats.STR += get_rand_num(2);
                        enemy->e_stats.DEX += get_rand_num(3);
                        enemy->e_level = i;
                    }
                    break;
                }
                case E_MAGE:
                {
                    for (int i = 1; i != player->level; i++)
                    {
                        enemy->e_stats.HP += 125;
                        enemy->e_stats.INT += get_rand_num(2);
                        enemy->e_stats.WIS += get_rand_num(2);
                        enemy->e_level = i;
                    }
                    break;
                }

                case FROGZARD:
                {
                for (int i = 1; i != player->level; i++)
                    {
                        enemy->e_stats.HP += 150;
                        enemy->e_stats.STR += get_rand_num(3);
                        enemy->e_stats.DEX += get_rand_num(3);
                        enemy->e_level = i;
                    }
                    break;
                }
                case GREENGUARD_DRAGON:
                {                    
                    for (int i = 1; i != player->level; i++)
                    {
                        enemy->e_stats.HP += 100;
                        enemy->e_stats.STR += get_rand_num(2);
                        enemy->e_stats.DEX += get_rand_num(2);
                        enemy->e_stats.INT += get_rand_num(2);
                        enemy->e_stats.WIS += get_rand_num(2);
                        enemy->e_level = i;
                    }
                    break;
                }

                case W_ELEMENTAL:
                {
                   for (int i = 1; i != player->level; i++)
                    {
                        enemy->e_stats.HP += 100;
                        enemy->e_stats.INT += get_rand_num(3);
                        enemy->e_stats.WIS += get_rand_num(2);
                        enemy->e_level = i;
                    }
                    break;
                }

                case BANDIT:
                {
                    for (int i = 1; i != player->level; i++)
                    {
                        enemy->e_stats.HP += 100;
                        enemy->e_stats.STR += get_rand_num(2);
                        enemy->e_stats.DEX += get_rand_num(2);
                        enemy->e_level = i;
                    }
                    break;
                }

                case MEGALOCRAB:
                {
                    for (int i = 1; i != player->level; i++)
                    {
                        enemy->e_stats.HP += 75;
                        enemy->e_stats.STR += get_rand_num(3);
                        enemy->e_stats.DEX += get_rand_num(3);
                        enemy->e_stats.INT += get_rand_num(2);
                        enemy->e_stats.WIS += get_rand_num(2);
                        enemy->e_level = i;
                    }
                    break;
                }
    return enemy->e_stats;
}

    cout << "Enemy stats: \n" << "=========================================" << endl;
    print_enemy_info(enemy);

    return enemy->e_stats;
}

#endif