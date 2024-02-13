#include "vinland/internal/ecs.h"
#include "flecs.h"

static ecs_world_t *world;

ecs_world_t *v_InitEcs() {
  /* TODO
   * Pass it the fps cap in parameter
   */
  world = ecs_init();
  ecs_set_target_fps(world, 60);
  return world;
}

void v_CleanUpEcs() {
  ecs_fini(world);
  world = NULL;
}
