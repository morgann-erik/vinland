#include "flecs.h"
#include "raylib.h"
#include "vinland/vinland.h"

int main(void) {
  ecs_world_t *world;

  world = V_InitCore();
  V_Run(world);

  CloseWindow();
  V_CleanUp();

  return 0;
}
