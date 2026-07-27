#ifndef PLAYER_BUILDING_CPP
#define PLAYER_BUILDING_CPP
#include <iostream>
#include "PLAYER.h"
#include <string>
#include <string.h>
#include <ctype.h>
#include <string_view>
#include <list>
using namespace std;

bool only_whitespace(std::string_view str)
{
    size_t length = str.size();
    std::string str_char_dump = "";
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == ' '){
            str_char_dump += str[i];
        }
    }
    if (str_char_dump.size() == length){
        return true;
    } 
    return false;
}
//=============================================================


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
    std::string user_input;
    cout << "Select from the following classes:" << "\n";
    cout << "Warrior, Mage, Rogue, Warlock, Priest" << "\n" << "=========================================" << "\n";
    std::cout << "" << std::endl;
    std::getline(cin, user_input);

    if (user_input == "Warrior" || user_input == "warrior") {
        player->kind = PCLASSES::WARRIOR;
    }
    else if (user_input == "Mage" || user_input == "mage") {
        player->kind = PCLASSES::MAGE;
    }
    else if (user_input == "Rogue" || user_input == "rogue") {
        player->kind = PCLASSES::ROGUE;
    }
    else if (user_input == "Warlock" || user_input == "warlock") {
        player->kind = PCLASSES::WARLOCK;
    }
    else if (user_input == "Priest" || user_input == "priest") {
        player->kind = PCLASSES::PRIEST;
    } else {
        cout << "invalid input. Read my man, try again." << "\n" << "=========================================" << "\n";
        get_class(player);
    }
    return player->kind;
}

p_stats get_stats(Player* player)
{
    switch (player->kind)
    {
        case PCLASSES::WARRIOR:
            player->stats.HP = 400;
            player->stats.STR = 15;
            player->stats.DEX = 10; //but don't anyone you leveled it
            player->stats.INT = 8;
            player->stats.WIS = 8;
            break;

        case PCLASSES::MAGE:
            player->stats.HP = 275;
            player->stats.STR = 9;
            player->stats.DEX = 9;
            player->stats.INT = 15;
            player->stats.WIS = 12;
            break;
        
        case PCLASSES::ROGUE:
            player->stats.HP = 325;
            player->stats.STR = 10;
            player->stats.DEX = 15;
            player->stats.INT = 11; //what's the point of giving classes stats they don't use?
            player->stats.WIS = 8;  //lol, lmao.
            break;

        case PCLASSES::WARLOCK:
            player->stats.HP = 275;
            player->stats.STR= 8;
            player->stats.DEX = 10;
            player->stats.INT = 17;
            player->stats.WIS = 10;
            break;

        case PCLASSES::PRIEST:
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
std::list<std::string> class_abilities(Player* player)
{

    switch (player->kind) {

    case PCLASSES::WARRIOR:
        player->ability_list = {"Mortal Strike", "Overpower", "Execute", "Rend"};
        break;
    
    case PCLASSES::MAGE:
        player->ability_list = {"Ice bolt", "Fireblast", "Thunder", "Ice Block"};
        break;
    
    case PCLASSES::ROGUE:
        player->ability_list = {"Slice and Dice", "Kick", "Saber Slash", "Poison Bomb"};
        break;
    
    case PCLASSES::WARLOCK:
        player->ability_list = {"Shadow Bolt", "Bone Decay", "Rain of Fire", "Summon Demon"};
        break;
    
    case PCLASSES::PRIEST:
        player->ability_list = {"Heal", "Dia", "Holy", "Aero"};
        break;
    }
    return player->ability_list;
    }

void print_class_info(Player* player)
{
    switch (player->kind)
    {
        case PCLASSES::WARRIOR:
            get_stats(player);
            cout << "You have chosen Warrior" << "\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case PCLASSES::MAGE:
            get_stats(player);
            cout << "You have chosen Mage" << "\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case PCLASSES::ROGUE:
            get_stats(player);
            cout << "You have chosen Rogue" << "\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case PCLASSES::WARLOCK:
            get_stats(player);
            cout << "You have chosen Warlock" << "\n";
            cout << "Stats:" << "\n";
            cout << "HP: " << player->stats.HP << "\n";
            cout << "STR: " << player->stats.STR << "\n";
            cout << "DEX: " << player->stats.DEX << "\n";
            cout << "INT: " << player->stats.INT << "\n";
            cout << "WIS: " << player->stats.WIS << "\n";
            cout << "=========================================" << endl;
            break;
        
        case PCLASSES::PRIEST:
            get_stats(player);
            cout << "You have chosen Priest" << "\n";
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
std::string print_abilities(Player player) {
    std::string message = "";
    for (auto i = player.ability_list.begin(); i != player.ability_list.end(); i++)
    {
        if (i != player.ability_list.begin()) {
            message += ", ";
        }
        message += *i;
    }
    return message;
}

#endif