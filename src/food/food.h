#ifndef FOOD_H
#define FOOD_H

#include <cstddef>

#include "state/game_state.h"

typedef struct
{
  int x;
  int y;
} Food;

void spawn_food(GameState *game_state);

#endif