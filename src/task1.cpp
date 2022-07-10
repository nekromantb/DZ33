#include "task1.h"
#include <iostream>
#include <map>
#include <string>

class Database
{
    std::string name;
    std::map<std::string, int> base;

public:
    Database(std::string name_in): name(name_in)
    {};

    void erase_database ()
    {
        if (!base.empty())
            base.clear();
    }

    void add_to_database (std::string new_pos, int new_pos_value)
    {
        if (new_pos_value <=0)
            throw std::invalid_argument("input value is zero or under zero");
        auto it=base.find(new_pos);
        if ( it == base.end())
            base.insert(std::pair<std::string, int> (new_pos,new_pos_value));
        else
            it->second += new_pos_value;
    }

    void remove_from_database (std::string pos_name, int pos_value)
    {
        if (pos_value <=0)
            throw std::invalid_argument("input value is zero or under zero");
        auto it = base.find(pos_name);
        if ( it == base.end())
            throw std::invalid_argument("no such position in "+name+" database");
        if ( it->second < pos_value)
            throw std::invalid_argument("number of "+it->first+" is less then you want to remove from "+name+" database");
        it->second -= pos_value;
        if (it->second == 0)
            base.erase(it);
    }

    void show_database ()
    {
        std::cout << "Now in " << name << " ingot:" << std::endl;
        for (auto i : base)
            std::cout << "   " << i.first <<": " <<i.second <<";"<<std::endl;
    }

};

void input_check(std::string &input_value, int &value)
{
    for (int i = 0; i < input_value.length();++i) {
        if (input_value[0] == '-' && i == 0) ++i;
        if (input_value[i] < '0' || input_value[i] > '9') throw std::invalid_argument("value is not a number!");
    }
    value = std::stoi(input_value);
}

void load_new_stock(Database &input_base)
{
    std::cout << "New database loading..." << std::endl;
    std::cout << "Enter new products (format:name value):" <<std::endl;
    std::cout << "To exit type \"exit\" in name"<<std::endl;
    std::string input_string, input_value;
    int value;
    input_base.erase_database();
    while (true)
    {
        try {
            std::cin >> input_string;
            if (input_string == "exit") break;
            std::cin >> input_value;
            input_check (input_value,value);
            input_base.add_to_database(input_string, value);
        }
        catch (const std::invalid_argument &error)
        {
            std::cerr << error.what() << "; try again!" << std::endl;
        }
    }
};

void add_to_basket(Database &basket, Database &stock)
{
    std::cout << "Enter product to add in basket (format:name value):";
    std::string input_string, input_value;
    int value;
    bool flag = true;
    while (flag) {
        try {
            flag = false;
            std::cin >> input_string;
            std::cin >> input_value;
            input_check(input_value, value);
            stock.remove_from_database(input_string, value);
            basket.add_to_database(input_string, value);
        }
        catch (const std::invalid_argument &error) {
            std::cerr << error.what() << "; try again!" << std::endl;
            flag = true;
        }
    }
};

void remove_from_basket(Database &basket, Database &stock)
{
    std::cout << "Enter product to remove from basket (format:name value):";
    std::string input_string, input_value;
    int value;
    bool flag = true;
    while (flag) {
        try {
            flag = false;
            std::cin >> input_string;
            std::cin >> input_value;
            input_check(input_value, value);
            basket.remove_from_database(input_string, value);
            stock.add_to_database(input_string, value);
        }
        catch (const std::invalid_argument &error) {
            std::cerr << error.what() << "; try again!" << std::endl;
            flag = true;
        }
    }
};

void task1()
{
    Database stock("Stock");
    Database basket("Basket");
    load_new_stock(stock);
    bool flag = true;
    std::string i;
    int i_int;
    while (flag)
    {
        std::cout << "what to do? ( add = 1, remove = 2, show = 3, exit = 4)" << std::endl;
        std::cin >> i;
        try{
            input_check(i,i_int);
            switch (i_int)
            {
                case 1:
                    add_to_basket(basket,stock);
                    break;
                case 2:
                    remove_from_basket(basket,stock);
                    break;
                case 3:
                    basket.show_database();
                    break;
                case 4:
                    flag = false;
                    break;
                default:
                    throw std::invalid_argument("command not found");
            }
        }
        catch (const std::invalid_argument &error) {
            std::cerr << error.what() << ", try again"<<std::endl;
        }

    }
    stock.show_database();
};