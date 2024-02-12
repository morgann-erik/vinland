#include "vinland/internal/modules/renderer.h"
#include "flecs.h"
#include "vinland/components/renderer/position.h"
#include "vinland/internal/renderer/renderer.h"
#include "vinland/log.h"

ECS_COMPONENT_DECLARE(V_Position);

void v_RendererModuleImport(ecs_world_t *world) {
  ECS_MODULE(world, V_RendererModule);

  ECS_COMPONENT_DEFINE(world, V_Position);

  ECS_SYSTEM(world, Render, EcsOnUpdate, V_Position);

  V_LogDebug("Renderer Module imported");
}
