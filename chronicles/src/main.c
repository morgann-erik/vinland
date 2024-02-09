#include "flecs.h"
#include "vinland/vinland.h"

int main(void) {
    ecs_world_t *world;

    world = V_InitCore();
    V_Run(world);
    V_CleanUp();

  return 0;
}
