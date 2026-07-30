#ifndef HELPERS_CPP
#define HELPERS_CPP

#include <iostream> //I'll organize later.
#include "PLAYER.h"
#include <string>
#include <optional>
#include <ctype.h>
#include <string_view>
#include <list>
using namespace std;

//helpers I might move to their own cpp file. We'll see
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

std::string print_list(std::list<std::string> list) { //probably gonna homebrew a dynamic helper for this just for the hell of it
    std::string message = "";                         //"But you'll just essentially be copy pasting!...Yeah and? if it works it works."
    int count = 1;
    for (auto i = list.begin(); i != list.end(); i++)
    {
        if (i != list.begin()) {
            std::string PITA_numcat = "";
            std::string string_num = std::to_string(count);
            PITA_numcat = "(" + string_num + ")";
            message += ", " + PITA_numcat + " " + *i;
            count++;
        } else if (i == list.begin()) {
        std::string PITA_numcat = "";
        std::string string_num = std::to_string(count);
        PITA_numcat = "(" + string_num + ")";
        message += PITA_numcat + " " + *i;
        count++;
        }
    }
    return message;
}

//attempting to make a list access helper
std::string get_item(std::list<std::string> list, int i)
{
    if (list.empty())
    {
        cout << "Can't get data from an empty or nothingburger list" << endl;
    }
    std::list<std::string>::iterator in = list.begin();
    for (int j = 0; j + 1 < i; j++)
    {
        ++in;
    };
    return *in;
}



#endif