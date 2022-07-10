#include <iostream>
#include <cassert>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

int main() {
    std::cout << "Choose task (1, 2, 3, 4):"<< std::endl;
    int i;
    std::cin >>i;
    assert(i >= 1 && i <=4);
    switch (i)
    {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
    }
    return 0;
}
