#include "raylib.h"
int main()
{
  // window dimensions
  int width{350};
  int height{200};

  InitWindow(width, height, "Axe Game");

  // circle coordinates
  int circle_x{175};
  int circle_y{100};
  float circle_radius{25.0};

  SetTargetFPS(60);

  // WindowShouldClose will return true if X icon or Escape Key are pressed
  while (WindowShouldClose() == false)
  {
    // handles the setup of the window to the screen
    BeginDrawing();
    // makes the canvas stay the same color and avoid flickering as new frames are buffered
    ClearBackground(WHITE);

    // Game logic begins

    DrawCircle(circle_x, circle_y, circle_radius, BLUE);

    if (IsKeyDown(KEY_D) && circle_x < 350)
    {
      circle_x = circle_x + 10;
    }

    if (IsKeyDown(KEY_A) && circle_x > 0)
    {
      circle_x = circle_x - 10;
    }

    // Game logic ends
    EndDrawing();
  }
}