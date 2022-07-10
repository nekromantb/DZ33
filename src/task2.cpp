#include "task2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

enum Field {
    NONE = 0,
    SHOE = 1,
    FISH = 2
};

class WinGameException:public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "You win the game! Congratulations!";
    }
};

class LoseGameException:public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "You lose the game! You'll be lucky next time =)";
    }
};

void input_check_task2(std::string &input_value, int &value) {
    if (input_value[0] < '1' || input_value[0] > '9') throw std::invalid_argument("value is not from 1 to 9!");
    value = (input_value[0]-'0');
}

void new_game_field(Field* field)
{
    int i =std::rand() % 9;
    field[i] = FISH;
    int j = 0;
    while (1)
    {
        i =std::rand() % 9;
        if (field[i] == NONE)
        {
            ++j;
            field[i] = SHOE;
        }
        if (j == 2)
            break;
    }

}

void task2()
{
    std::srand(std::time(nullptr));
    std::cout << "Welcome to the game =)" << std::endl;
    Field field[9]{};
    new_game_field(field);
    std::string choose;
    int choose_int, moves = 0;
    try {
        while (true) {
            std::cout << "Enter number: " << std::endl;
            std::cin >> choose;
            ++moves;
            input_check_task2(choose, choose_int);
            if (field[choose_int] == SHOE)
                throw LoseGameException();
            if (field[choose_int] == FISH) {
                throw WinGameException();
            }
        }
    }
    catch (const WinGameException &x)    {
        std::cerr << x.what() << "Moves: " << moves << std::endl;
    }
    catch (const LoseGameException &x){
        std::cerr << x.what()  << std::endl;
    }


};