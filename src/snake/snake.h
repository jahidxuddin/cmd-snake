#ifndef SNAKE_H
#define SNAKE_H

#include "state/game_state.h"

typedef struct SnakeSegment SnakeSegment;

struct SnakeSegment
{
  int x;
  int y;
  SnakeSegment *next;
};

int snake_contains(SnakeSegment *head, int x, int y);
void move_snake(GameState *game_state);
void add_segment(SnakeSegment *head);
void spawn_snake(GameState *game_state);

typedef enum
{
  UP,
  DOWN,
  LEFT,
  RIGHT
} Direction;

Direction current_direction = RIGHT;

#endif