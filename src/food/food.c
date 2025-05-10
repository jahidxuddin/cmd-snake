#include "food.h"

void spawn_food(GameState *game_state)
{
  srand(time(NULL));
  Food food;
  food.x = 1 + rand() % (30 - 2);
  food.y = 1 + rand() % (20 - 2);
  game_state->food = food;
}
