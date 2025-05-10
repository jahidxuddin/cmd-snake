#ifndef WORLD_H
#define WORLD_H

#include "state/game_state.h"

typedef struct
{
  char world[20][30];
} World;

void spawn_world(GameState *game_state);

#endif