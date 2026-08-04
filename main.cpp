#include <iostream>
#include "PLAYER.h"
#include "helpers.cpp"
#include "player_building.cpp"
#include "enemy_building.cpp"
#include "damage_calcs.cpp"
#include "game_loop.cpp"
#include <optional>
#include <string>
#include <string_view>
#include <list>

int main() {

    Player* player = new Player(); 
    Enemy* enemy = new Enemy();
    Zone* zone = new Zone();
    std::string input;
    cout << "=========================================" << endl;
    cout << "While playing you can use alphanumeric values for input in their respective cases.\n"
    << "Though bear in mind you can only use numeric for zone selection and the post encounter menu" << endl;
    cout << "=========================================" << endl;
   
    //all player stuff
    player->name = get_player_name(); //starting the instance of the player object. Of course, starts with the name.
    cout << "=========================================" << endl;
    get_class(player);
    get_stats(player);
    class_abilities(player);
    print_class_info(player);
    player->current_HP = player->stats.HP;
    player->current_zone = get_zone(player);
    //=======================================

    //game loop
    game_loop(player, enemy, zone);
    return 0;
}