#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"
#include <vector>
#include <thread>

enum FoodPhase {
    fresh,
    rotten
};

class Food : public SDL_Point {
public:
    Food();
    ~Food();

protected:
    std::vector<std::thread> threads;

private:
    FoodPhase _currentPhase;    
};

#endif