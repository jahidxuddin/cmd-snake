#include "snake.h"

void spawn_snake(GameState *game_state)
{
  SnakeSegment *head = &game_state->snake;
  head->x = WIDTH / 2;
  head->y = HEIGHT / 2;
  head->next = NULL;
}

int snake_contains(SnakeSegment *head, int x, int y)
{
  SnakeSegment *current = head;
  while (current != NULL)
  {
    if (current->x == x && current->y == y)
    {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void move_snake(GameState *game_state)
{
  SnakeSegment *head = &game_state->snake;
  int prev_x = head->x;
  int prev_y = head->y;
  int new_x = head->x;
  int new_y = head->y;

  switch (current_direction)
  {
  case UP:
    new_y--;
    break;
  case DOWN:
    new_y++;
    break;
  case LEFT:
    new_x--;
    break;
  case RIGHT:
    new_x++;
    break;
  }

  // Kollision mit Wand
  if (new_x <= 0 || new_x >= WIDTH - 1 || new_y <= 0 || new_y >= HEIGHT - 1)
  {
    printf("Game Over!\n");
    exit(0);
  }
  // Kollision mit Snake
  if (snake_contains(head, new_x, new_y))
  {
    printf("Game Over!\n");
    exit(0);
  }
  // Kollision mit Food
  if (new_x == game_state->food.x && new_y == game_state->food.y)
  {
    game_state->score++;
    spawn_food(game_state);
    add_segment(head);
  }

  SnakeSegment *current = head->next;
  while (current != NULL)
  {
    // Alte Positionen merken
    int temp_x = current->x;
    int temp_y = current->y;

    // Aktuelles Segment übernimmt Position des Vorgängers
    current->x = prev_x;
    current->y = prev_y;

    // Update für nächstes Segment
    prev_x = temp_x;
    prev_y = temp_y;

    current = current->next;
  }

  head->x = new_x;
  head->y = new_y;
}

void add_segment(SnakeSegment *head)
{
  SnakeSegment *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }

  SnakeSegment *new_segment = malloc(sizeof(SnakeSegment));
  if (new_segment == NULL)
  {
    exit(1);
  }

  if (current_direction == UP)
  {
    new_segment->x = current->x;
    new_segment->y = current->y + 1;
  }
  else if (current_direction == DOWN)
  {
    new_segment->x = current->x;
    new_segment->y = current->y - 1;
  }
  else if (current_direction == LEFT)
  {
    new_segment->x = current->x + 1;
    new_segment->y = current->y;
  }
  else
  {
    new_segment->x = current->x - 1;
    new_segment->y = current->y;
  }
  new_segment->next = NULL;

  current->next = new_segment;
}