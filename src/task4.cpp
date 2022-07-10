#include "task4.h"
#include <iostream>

template < typename T >
void input(T* array)
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

template < typename T >
T average (T* input)
{
    T sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += input[i];
    }
    return sum / 8;
}

void task4()
{
    double array[8];
    input(array);
    std::cout << average(array)<< std::endl;
};