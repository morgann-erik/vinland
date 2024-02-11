#include "flecs.h"
#include "raylib.h"
#include "vinland/vinland.h"

int main(void) {
  ecs_world_t *world;

  world = V_InitCore();
  V_Run(world);
  V_CleanUp();

  InitWindow(640, 480, "TEST");

  while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        DrawText("TEST", 10, 10, 20, LIGHTGRAY);

        EndDrawing();
  }

  CloseWindow();

  return 0;
}
