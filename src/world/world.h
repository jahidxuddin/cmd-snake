#ifndef WORLD_H
#define WORLD_H

#include "main.c"

typedef struct
{
  char world[HEIGHT][WIDTH];
} World;

void spawn_world(GameState *game_state);

#endif