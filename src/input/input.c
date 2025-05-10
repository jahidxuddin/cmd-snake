#include "input.h"

void handle_input()
{
#ifdef _WIN32
  if (_kbhit())
  {
    char c = _getch();
#else
  if (kbhit())
  {
    char c = getch();
#endif
    switch (c)
    {
    case 'w':
      if (current_direction != DOWN)
        current_direction = UP;
      break;
    case 's':
      if (current_direction != UP)
        current_direction = DOWN;
      break;
    case 'a':
      if (current_direction != RIGHT)
        current_direction = LEFT;
      break;
    case 'd':
      if (current_direction != LEFT)
        current_direction = RIGHT;
      break;
    case 27:
      exit(0); // ESC
    }
  }
}
