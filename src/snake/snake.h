#ifndef SNAKE_H
#define SNAKE_H

#include "main.c"

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

#endif