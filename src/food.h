#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"
#include <thread>

enum FoodPhase {
    fresh,
    rotten
};

class Food : public SDL_Point {
public:
    Food();
    ~Food();

    FoodPhase getCurrentPhase() const;
    void setGameRunning(bool running);

protected:
    std::thread t;

private:
    FoodPhase _currentPhase;
    bool _isGameRunning;
    void cycleThroughPhases();
};

#endif