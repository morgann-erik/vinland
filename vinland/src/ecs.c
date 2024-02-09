#include "vinland/internal/ecs.h"
#include "flecs.h"

static ecs_world_t *world;

ecs_world_t *v_InitEcs() {
    world = ecs_init();
    return world;
}

void v_CleanUpEcs() {
    ecs_fini(world);
    world = NULL;
}
