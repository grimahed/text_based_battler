#include <iostream>
#include <string>
#include <string_view>
#include "PLAYER.h"
#include "HELPERS.cpp"
#include <stdlib.h>


int main() {
    Player* player = new Player();
    std::string name;
    std::string class_name;
    std::string input;
    player->name = get_player_name(); //starting the instance of the player object. Of course, starts with the name.
    player->kind = get_class(player);
    player->ability_list = class_abilities(player);
    print_abilities(*player);

    return 0;
}