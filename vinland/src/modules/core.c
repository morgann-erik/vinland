#include "vinland/internal/modules/core.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "vinland/internal/components/core/app-specs.h"
#include "vinland/internal/core/startup-raylib.h"
#include "vinland/log.h"

ECS_COMPONENT_DECLARE(v_ApplicationSpecs);

void v_CoreModuleImport(ecs_world_t *world) {
  ECS_MODULE(world, V_CoreModule);

  ECS_COMPONENT_DEFINE(world, v_ApplicationSpecs);

  ECS_SYSTEM(world, v_StartupRaylib, EcsOnStart, v_ApplicationSpecs);

  V_LogDebug("Core module imported");
}
