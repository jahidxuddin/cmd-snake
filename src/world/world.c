#include "world.h"

void spawn_world(GameState *game_state)
{
  for (int y = 0; y < 20; y++)
  {
    for (int x = 0; x < 30; x++)
    {
      if (x == 0 || x == 30 - 1 || y == 0 || y == 20 - 1)
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
