#include "vinland/internal/modules/renderer.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "vinland/internal/assets/sprite-loader.h"
#include "vinland/internal/components/assets/sprite-registry.h"
#include "vinland/internal/renderer/renderer.h"
#include "vinland/log.h"

extern ECS_COMPONENT_DECLARE(V_Position);
extern ECS_COMPONENT_DECLARE(v_SpriteRegistry);

void v_RendererModuleImport(ecs_world_t *world) {
  ECS_MODULE(world, V_RendererModule);

  ecs_system(world, {.entity = ecs_entity(
                         world, {.name = "Renderer",
                                 .add = {ecs_dependson(EcsOnUpdate)}}),
                     .query.filter.terms = {{.id = ecs_id(V_Position)},
                                            {.id = ecs_id(v_SpriteRegistry),
                                             .src = ecs_id(v_SpriteRegistry)}},
                     .query.filter.instanced = 1,
                     .callback = Render});

  V_LogDebug("Renderer module imported");
}
