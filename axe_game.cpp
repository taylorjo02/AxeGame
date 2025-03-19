#include "raylib.h"
int main()
{
  // window dimensions
  int width{800};
  int height{450};

  InitWindow(width, height, "Axe Game");

  // circle coordinates
  int circle_x{200};
  int circle_y{200};
  float circle_radius{25.0};

  // circle edges

  float l_circle_x{circle_x - circle_radius};
  float r_circle_x{circle_x + circle_radius};
  float u_circle_y{circle_y - circle_radius};
  float b_circle_y{circle_y + circle_radius};

  // axe coords

  int axe_x{300};
  int axe_y{0};
  int axe_width{50};
  int axe_height{50};
  int direction{10};

  // axe edges

  int l_axe_x{axe_x};
  int r_axe_x{axe_x + axe_width};
  int u_axe_y{axe_y};
  int b_axe_y{axe_y + axe_height};

  bool collision_with_axe = 
                          (b_axe_y >= u_circle_y) && 
                          (u_axe_y <= b_circle_y) && 
                          (l_axe_x <= r_circle_x) && 
                          (r_axe_x >= l_circle_x);
  
  SetTargetFPS(60);

  // WindowShouldClose will return true if X icon or Escape Key are pressed
  while (WindowShouldClose() == false)
  {
    // handles the setup of the window to the screen
    BeginDrawing();
    // makes the canvas stay the same color and avoid flickering as new frames are buffered
    ClearBackground(WHITE);

    if (collision_with_axe)
    {
      DrawText("Game Over!", 350, 200, 20, RED);
    }
    else
    {

      // Game logic begins

      // updates the edges

      l_circle_x = circle_x - circle_radius;
      r_circle_x = circle_x + circle_radius;
      u_circle_y = circle_y - circle_radius;
      b_circle_y = circle_y + circle_radius;

      l_axe_x = axe_x;
      r_axe_x = axe_x + axe_width;
      u_axe_y = axe_y;
      b_axe_y = axe_y + axe_height;

      // update collision with axe

      collision_with_axe = 
                          (b_axe_y >= u_circle_y) && 
                          (u_axe_y <= b_circle_y) && 
                          (l_axe_x <= r_circle_x) && 
                          (r_axe_x >= l_circle_x);

      DrawCircle(circle_x, circle_y, circle_radius, BLUE);
      DrawRectangle(axe_x, axe_y, axe_width, axe_height, RED);

      // move the axe up and down

      axe_y += direction;

      if (axe_y > height - 50 || axe_y < 0)
      {
        direction = -direction;
      }

      if (IsKeyDown(KEY_D) && circle_x < width - 0)
      {
        circle_x += 10;
      }

      if (IsKeyDown(KEY_A) && circle_x > 0)
      {
        circle_x -= 10;
      }
    }
    // Game logic ends
    EndDrawing();
  }
}