#include "task3.h"
#include <iostream>
#include <vector>

template <typename T1, typename T2>

class Pair_task3
{
public:
    T1 key;
    T2 element;

    Pair_task3(T1 key_input, T2 element_input)
    {
        key = key_input;
        element= element_input;
    }
};

template <typename T1, typename T2>

class Reestr
{
    std::vector<Pair_task3<T1, T2>> data;
public:
    void add (T1 key, T2 element)
    {
        data.push_back(Pair_task3(key,element));
    }
    void remove (T1 key_input)
    {
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (it->key == key_input)
            {
                data.erase(it);
                if (data.empty()) break;
            }
        }
    }
    void print ()
    {
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            std::cout << it->key << " : " << it->element << std::endl;
        }
    }
    std::vector<T2> find (T1 key_input)
    {
        std::vector<T2> output;
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (it->key == key_input)
            {
                output.push_back(it->element);
            }
        }
        return output;
    }
};

//template <typename T1, typename T2>
#define  T1 int
#define T2 std::string
void task3()
{
    Reestr<T1, T2> data;
    bool flag = true;
    std::string i;
    while (flag)
    {
        std::cout << "what to do? (add, remove, print, find, exit)" << std::endl;
        std::cin >> i;
        try{
            if (i == "add"){
                std::cout << "Enter key and element" <<std::endl;
                T1 key;
                T2 element;
                std::cin >> key >> element;
                data.add(key,element);
            }
            else if (i == "remove") {
                std::cout << "Enter key for remove" <<std::endl;
                T1 key;
                std::cin >> key ;
                data.remove(key);
            }
            else if (i == "print") {
                data.print();
            }
            else if (i == "find") {
                std::cout << "Enter key for find" <<std::endl;
                T1 key;
                std::cin >> key ;
                std::vector<T2> output;
                output=data.find(key);
                for (auto i : output)
                    std::cout << i << std::endl;
            }
            else if (i == "exit"){
                flag = false;
            } else {
                throw std::invalid_argument("command not found");
            }
        }
        catch (const std::invalid_argument &error) {
            std::cerr << error.what() << ", try again"<<std::endl;
        }
    }
}