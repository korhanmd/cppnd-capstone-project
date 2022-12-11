#include <iostream>
#include <chrono>
#include <future>
#include <algorithm>
#include "food.h"

Food::Food() {
    std::cout << "Food object is created" << std::endl;
    _currentPhase = FoodPhase::fresh;
    _isGameRunning = true;
    std::cout << "Current phase of the food is " << _currentPhase << std::endl;
    threads.emplace_back(std::thread(&Food::cycleThroughPhases, this));
}

Food::~Food() {
    std::cout << "Food object is terminated" << std::endl;
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
}

void Food::cycleThroughPhases() {
    int cycle_duration = 5000;
    auto last_time = std::chrono::high_resolution_clock::now();
    
    while (_isGameRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        auto current_time = std::chrono::high_resolution_clock::now();
        auto time_diff = current_time - last_time;

        if (std::chrono::duration_cast<std::chrono::milliseconds>(time_diff).count() > cycle_duration) {
            if (_currentPhase == FoodPhase::fresh) _currentPhase = FoodPhase::rotten;
            else _currentPhase = FoodPhase::fresh;

            std::cout << "Phase changed " << _currentPhase << std::endl;

            last_time = std::chrono::high_resolution_clock::now();
        }
    }
}

FoodPhase Food::getCurrentPhase() const {
    return _currentPhase;
}

void Food::setGameRunning(bool running) {
    _isGameRunning = running;
}