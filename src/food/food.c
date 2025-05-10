#include "food.h"

void spawn_food(GameState *game_state)
{
  srand(time(NULL));
  Food food;
  food.x = 1 + rand() % (WIDTH - 2);
  food.y = 1 + rand() % (HEIGHT - 2);
  game_state->food = food;
}
