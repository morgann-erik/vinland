#include "vinland/vinland.h"
#include "flecs.h"
#include "raylib.h"
#include "vinland/components/renderer/position.h"
#include "vinland/internal/components/core/app-specs.h"
#include "vinland/internal/ecs.h"
#include "vinland/internal/modules/core.h"
#include "vinland/internal/modules/renderer.h"
#include "vinland/internal/modules/input.h"
#include "vinland/internal/modules/assets.h"
#include "vinland/log.h"

extern ECS_COMPONENT_DECLARE(v_ApplicationSpecs);
extern ECS_COMPONENT_DECLARE(V_Position);

ecs_world_t *V_InitCore() {
  ecs_world_t *world;

  V_LogInfo("VinlandCore v0.1.0");

  world = v_InitEcs();

  ECS_IMPORT(world, v_CoreModule);
  ECS_IMPORT(world, v_AssetsModule);
  ECS_IMPORT(world, v_InputModule);
  ECS_IMPORT(world, v_RendererModule);

  ecs_entity_t e = ecs_new_entity(world, "AppSpecs");
  ecs_set(world, e, v_ApplicationSpecs,
          {.WindowTitle = "Test", .WindowWidth = 640, .WindowHeight = 480});

  ecs_entity_t t = ecs_new_entity(world, "t");
  ecs_set(world, t, V_Position, {.x = 0, .y = 0});

  V_LogInfo("Vinland Core initialsed\n");

  return world;
}

void V_Run(ecs_world_t *world) {
    ecs_progress(world, 60);
  do {
    ecs_progress(world, GetTime());
  } while (!WindowShouldClose());
}

void V_CleanUp() { v_CleanUpEcs(); }
