#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "world/world.h"
#include "snake/snake.h"
#include "food/food.h"
#include "render/render.h"
#include "input/input.h"

#define WIDTH 30
#define HEIGHT 20

typedef struct
{
  int score;
  World world;
  SnakeSegment snake;
  Food food;
} GameState;

typedef enum
{
  UP,
  DOWN,
  LEFT,
  RIGHT
} Direction;

Direction current_direction = RIGHT;

void sleep(int ms)
{
#ifdef _WIN32
  Sleep(ms);
#else
  usleep(ms * 1000);
#endif
}

void init_game(GameState *game_state)
{
  game_state->score = 0;
  spawn_world(game_state);
  spawn_snake(game_state);
  spawn_food(game_state);
}

void game_loop(GameState *game_state)
{
  uint32_t last_move_time = get_time_ms();
  while (1)
  {
    handle_input();

    uint32_t current_time = get_time_ms();
    if (current_time - last_move_time >= 200)
    {
      move_snake(game_state);
      render_game(game_state);
      last_move_time = current_time;
    }

    sleep(10);
  }
}

int main()
{
  GameState game_state;
  init_game(&game_state);
  game_loop(&game_state);
  return 0;
}
