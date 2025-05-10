#ifndef FOOD_H
#define FOOD_H

#include "main.c"

typedef struct
{
  int x;
  int y;
} Food;

void spawn_food(GameState *game_state);

#endif