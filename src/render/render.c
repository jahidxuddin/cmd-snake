#include "render.h"

void render_world(GameState *game_state)
{
  for (int y = 0; y < HEIGHT; y++)
  {
    for (int x = 0; x < WIDTH; x++)
    {
      if (snake_contains(&game_state->snake, x, y))
      {
        putchar('O');
      }
      else if (game_state->food.x == x && game_state->food.y == y)
      {
        putchar('*');
      }
      else
      {
        putchar(game_state->world.world[y][x]);
      }
    }
    putchar('\n');
  }
}

void render_game(GameState *game_state)
{
  printf("\033[H");  // Clear screen
  printf("\e[?25l"); // Hide cursor
  printf("Score: %d\n", game_state->score);
  render_world(game_state);
  printf("Use WASD to move, ESC to exit.\n");
  fflush(stdout);
}