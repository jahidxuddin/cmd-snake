#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "world/world.h"
#include "snake/snake.h"
#include "food/food.h"

typedef struct
{
  int score;
  World world;
  SnakeSegment snake;
  Food food;
} GameState;

#endif