#include <iostream>
#include <string>
#include <string_view>
#include "PLAYER.h"
#include "player_building.cpp"
#include "damage_calcs.cpp"
#include <stdlib.h>


int main() {
    Player* player = new Player();
    std::string name;
    std::string class_name;
    std::string input;
    player->name = get_player_name(); //starting the instance of the player object. Of course, starts with the name.
    player->kind = get_class(player);
    player->ability_list = class_abilities(player);
    //player->w_ability = get_warrior_skill_used(player);
    int damage_dealt = calc_damage(player);
    cout << "You dealt " << damage_dealt << " damage to the murloc" << endl;
    return 0;
}