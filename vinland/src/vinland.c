#include "vinland/vinland.h"
#include "flecs.h"
#include "vinland/internal/ecs.h"
#include "vinland/log.h"

ecs_world_t *V_InitCore() {
  ecs_world_t *world;

  V_LogInfo("VinlandCore v0.1.0");

  world = v_InitEcs();
  return world;
}

void V_Run(ecs_world_t *world) {}

void V_CleanUp() { v_CleanUpEcs(); }
