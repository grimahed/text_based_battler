#include <iostream>
#include "PLAYER.h"
#include <string>
using namespace std;


void get_player_name()
{
player_t player;
std::string input;
std::string text_error = "Where's my valid TEXT";
std::cout << "Enter the name for your character: ";
std::getline(cin, player.input);
    if (player.input.empty()){
    cout << "The default name is Grimahed, is that okay (y/n)?" << std::endl;
    std::cout << "" << endl;
    std::getline(cin, player.input);
        if (player.input == "y" || player.input == "Y" || player.input == "yes") {
            player.name = "Grimahed";
            cout << "Your name is: " << player.name << std::endl;
        } else if (player.input == "n" || player.input == "N" || player.input == "no"){
            get_player_name();
        }
    } else {
        player.name = input;
        cout << "Your name is: " << player.name << std::endl;
    }
    }
    
void class_abilities()
{
Class<std::string> w_skills{"Mortal Strike", "Overpower", "Execute", "Rend"};
std::cout << w_skills.Warrior[0];
Class<std::string> m_skills{"Ice bolt", "Fireball", "Thunder", "Quake"};
Class<std::string> r_skills{"Slice and Dice", "Kick", "Gash", "Poison Strike"};
Class<std::string> wm_skills{"Aero", "Cure", "Holy", "Dia"};
}

std::string get_ability_used(std::string arg)
{
player_t player;
std::string input = arg;
player.input = input;

return player.input;
}