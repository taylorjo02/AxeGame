#include "raylib.h"
int main()
{
  int width;
  int height;

  width = 350;
  height = 200;

  InitWindow(width, height, "Axe Game");


  // WindowShouldClose will return true if X icon or Escape Key are pressed
  while (WindowShouldClose() == false)
  {
    // handles the setup of the window to the screen
    BeginDrawing();
    // makes the canvas stay the same color and avoid flickering as new frames are buffered
    ClearBackground(RED);
    // handles the teardown of the window
    EndDrawing();
  }
}