#include <iostream> //I'll organize later.
#include "PLAYER.h"
#include <string>
#include "helpers.cpp"
#include <string.h>
#include <optional>
#include <ctype.h>
#include <string_view>
#include <list>
#include "player_building.cpp"
#include "enemy_building.cpp"
#include "damage_calcs.cpp"

int main() {
    Player* player = new Player(); 
    cout << "=========================================" << endl;
    cout << "While playing you will use numbers for input, besides writing your name and class selection." << "\n\n"
            << "Keep in mind nothing else will be valid while you play." << endl; // I might make both usable later, though, just for variety.
    cout << "=========================================" << endl;
    std::string name;
    std::string class_name;
    std::string input;
    player->name = get_player_name(); //starting the instance of the player object. Of course, starts with the name.
    cout << "=========================================" << endl;
    player->kind = get_class(player);
    player->ability_list = class_abilities(player);
    print_class_info(player);
    get_zone(player);
    int damage_dealt = calc_damage(player);
    cout << "You dealt " << damage_dealt << " damage to the murloc" << endl;
    return 0;
}