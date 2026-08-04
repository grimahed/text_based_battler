#ifndef PLAYER_BUILDING_CPP
#define PLAYER_BUILDING_CPP
#include <iostream>
#include "PLAYER.h"
#include "helpers.cpp"
#include <string>
#include <string_view>
#include <list>
#include <stdexcept>
#include <optional>
using namespace std;


std::string get_player_name()
{
    std::string input;
    std::string text_error = "Where's my valid TEXT";
    cout << "The default name is Grimahed, is that okay (y/n)?" << std::endl;
    std::getline(cin, input);
        if (input == "y" || input == "Y" || input == "yes") {
            input = "Grimahed";
            cout << "Your name is: " << input << std::endl;
        } else if (input == "n" || input == "N" || input == "no")
        {
        std::cout << "Enter the name for your character: ";
        std::getline(cin, input);
        size_t name_length = input.size();
            if (only_whitespace(input))
            {
                cout << "" << text_error << endl;
                get_player_name();
            } else {
                cout << "Your name is: " << input << "\n" << "----------------------------------" << "\n";
            }
        } else {
            cout << "invalid input." << "\n================================\n";
            get_player_name();
        }
    return input;
}

PCLASSES get_class(Player* player)
{
    using enum PCLASSES;

    std::string user_input;
    cout << "Select from the following classes:" << "\n";
    cout << "Warrior, Mage, Rogue, Warlock, Priest" << "\n" << "=========================================" << "\n";
    std::cout << "" << std::endl;
    std::getline(cin, user_input);

    std::string shrunk_text = make_lower(user_input);
    if (shrunk_text == "warrior") {
        player->kind = WARRIOR;
    }
    else if (shrunk_text == "mage") {
        player->kind = MAGE;
    }
    else if (shrunk_text == "rogue") {
        player->kind = ROGUE;
    }
    else if (shrunk_text == "warlock") {
        player->kind = WARLOCK;
    }
    else if (shrunk_text == "priest") {
        player->kind = PRIEST;
    } else {
        cout << "invalid input. Read my man, try again." << "\n" << "=========================================" << "\n";
        get_class(player);
    }
    cout << "=========================================" << endl;
    return player->kind;
}

p_stats get_stats(Player* player)
{
    using enum PCLASSES;

    switch (player->kind)
    {
        case WARRIOR:
            player->stats.HP = 400;
            player->stats.STR = 15;
            player->stats.DEX = 10; //but don't anyone you leveled it
            player->stats.INT = 8;
            player->stats.WIS = 8;
            break;

        case MAGE:
            player->stats.HP = 275;
            player->stats.STR = 9;
            player->stats.DEX = 9;
            player->stats.INT = 15;
            player->stats.WIS = 12;
            break;
        
        case ROGUE:
            player->stats.HP = 325;
            player->stats.STR = 10;
            player->stats.DEX = 15;
            player->stats.INT = 11; //what's the point of giving classes stats they don't use?
            player->stats.WIS = 8;  //lol, lmao.
            break;

        case WARLOCK:
            player->stats.HP = 275;
            player->stats.STR= 8;
            player->stats.DEX = 10;
            player->stats.INT = 17;
            player->stats.WIS = 10;
            break;

        case PRIEST:
            player->stats.HP = 250;
            player->stats.STR = 8;
            player->stats.DEX = 10;
            player->stats.INT = 10;
            player->stats.WIS = 17;
            break;
        
        default:
        break;
    }
    return player->stats;
}

void print_class_info(Player* player)
{
    using enum PCLASSES;
    switch (player->kind)
    {
        case WARRIOR:
            cout << "Class: Warrior" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case MAGE:
            cout << "Class: Mage" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case ROGUE:
            cout << "Class: Rogue" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case WARLOCK:
            cout << "Class: Warlock" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case PRIEST:
            cout << "Class: Priest" << "\n\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        default:
            break;
    }
}

p_stats level_up(Player* player)
{
    using enum PCLASSES;

    player->level++;
    cout << "You are now level " << player->level << "!" << endl;
    
    cout << "Prior Stats: \n" << "=========================================" << endl;
    print_class_info(player);

    switch (player->kind)
    {
        case WARRIOR:
            player->stats.HP += 100;
            player->stats.STR += get_rand_num(3);
            player->stats.DEX += get_rand_num(2);
            break;
        
        case MAGE:
            player->stats.HP += 75;
            player->stats.INT += get_rand_num(3);
            player->stats.WIS += get_rand_num(2);
            break;
        
        case ROGUE:
            player->stats.HP += 75;
            player->stats.STR += get_rand_num(2);
            player->stats.DEX += get_rand_num(3);
            break;
        
        case WARLOCK:
            player->stats.HP += 75;
            player->stats.INT += get_rand_num(3);
            player->stats.WIS += get_rand_num(2);
            break;
        case PRIEST:
            player->stats.HP += 75;
            player->stats.INT += get_rand_num(2);
            player->stats.WIS += get_rand_num(3);
            break;
        }

    cout << "New stats: \n" << "=========================================" << endl;
    print_class_info(player);

    return player->stats;
}
std::list<std::string> class_abilities(Player* player)
{

    using enum PCLASSES;

    switch (player->kind) {

    case WARRIOR:
        player->ability_list = {"Mortal Strike", "Overpower", "Rend", "Execute"};
        break;
    
    case MAGE:
        player->ability_list = {"Ice bolt", "Fireblast", "Thunder", "Ice Block"};
        break;
    
    case ROGUE:
        player->ability_list = {"Slice and Dice", "Kick", "Saber Slash", "Poison Bomb"};
        break;
    
    case WARLOCK:
        player->ability_list = {"Shadow Bolt", "Bone Decay", "Rain of Fire", "Summon Demon"};
        break;
    
    case PRIEST:
        player->ability_list = {"Heal", "Dia", "Holy", "Aero"};
        break;
    }
    return player->ability_list;
    }

ZONES get_zone(Player* player)
{
    std::string input;
    cout << "Choose a zone from: " << print_list(player->zone_list) << endl; //this will stay numeric
    std::cout << "" << std::endl;;                                                     
    std::getline(cin, input);
    int num_imput = 0;                                         
    if (input == "1"){
        player->current_zone = ZONES::ELWYNN_FOREST;
        cout << "=========================================" << endl;
        cout << "Current Zone: " << get_item(player->zone_list, 0) << "\n" << endl;
        return player->current_zone;
    } else if (input == "2") {
        player->current_zone = ZONES::ZORAVIA;
        int num_input = std::stoi(input);
    } else if (input == "3") {
        player->current_zone = ZONES::GREENGUARD;
        int num_input = std::stoi(input);
    } 
    else {
        cout << "Need valid input mans" << endl << "=========================================" << endl;
        get_zone(player);
    }
    int num_input = std::stoi(input);
    cout << "=========================================" << endl;
    cout << "Current Zone: " << get_item(player->zone_list, num_input) << "\n" << endl;
    return player->current_zone;
}
#endif