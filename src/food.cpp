#include <iostream>
#include "food.h"

Food::Food() {
    std::cout << "Food object is created" << std::endl;
}

Food::~Food() {
    std::cout << "Food object is terminated" << std::endl;
}