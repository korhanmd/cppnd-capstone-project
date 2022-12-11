#include <iostream>
#include "food.h"

Food::Food() {
    std::cout << "Food object is created" << std::endl;
    _currentPhase = FoodPhase::fresh;
    std::cout << "Current phase of the food is " << _currentPhase << std::endl;
}

Food::~Food() {
    std::cout << "Food object is terminated" << std::endl;
}