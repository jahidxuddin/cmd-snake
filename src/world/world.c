#include "world.h"

void spawn_world(GameState *game_state)
{
  for (int y = 0; y < HEIGHT; y++)
  {
    for (int x = 0; x < WIDTH; x++)
    {
      if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
      {
        game_state->world.world[y][x] = '#';
      }
      else
      {
        game_state->world.world[y][x] = ' ';
      }
    }
  }
}
