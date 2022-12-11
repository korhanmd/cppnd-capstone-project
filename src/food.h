#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"
#include <vector>
#include <thread>

class Food : public SDL_Point {
 public:
  Food();

 protected:
  std::vector<std::thread> threads;

 private:
};

#endif