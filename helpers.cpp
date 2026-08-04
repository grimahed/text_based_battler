#ifndef HELPERS_CPP
#define HELPERS_CPP

#include <iostream> 
#include <optional>
#include <string>
#include <string_view>
#include <list>
#include <algorithm>
#include <cctype>
#include <random>
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

int get_rand_num(int num)
{
    std::random_device rd; //seed source for engine
    std::mt19937 gen(rd()); //engine being seeded with rd
    std::uniform_int_distribution<> distrib(1, num);

    //getting it
    return distrib(gen);
}
std::string print_list(std::list<std::string> list) 
{
    std::string message = "";                         
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

int list_len(std::list<std::string> list) 
{                        
    int count = 0;
    for (auto i = list.begin(); i != list.end(); i++)
    {
    count++;
    }
    return count;
}

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

std::string make_lower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), 
    [](unsigned char c) {return std::tolower(c);});
    return str;
}

#endif