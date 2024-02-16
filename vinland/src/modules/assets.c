#include "vinland/internal/modules/assets.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "vinland/components/assets/sprite-specs.h"
#include "vinland/internal/assets/sprite-loader.h"
#include "vinland/internal/components/assets/sprite-registry.h"
#include "vinland/log.h"

ECS_COMPONENT_DECLARE(V_SpriteSpecs);
ECS_COMPONENT_DECLARE(v_SpriteRegistry);

void v_AssetsModuleImport(ecs_world_t *world) {
  ECS_MODULE(world, V_AssetsModule);

  ECS_COMPONENT_DEFINE(world, V_SpriteSpecs);
  ECS_COMPONENT_DEFINE(world, v_SpriteRegistry);

  v_SpriteRegistry reg = v_NewSpriteRegistry();
  ecs_singleton_set(world, v_SpriteRegistry, {.map = reg.map});

  /*
   * Turn into an observer
   */
  ecs_system(world, {.entity = ecs_entity(
                         world, {.name = "Sprite Loader",
                                 .add = {ecs_dependson(EcsOnUpdate)}}),
                     .query.filter.terms = {{.id = ecs_id(V_SpriteSpecs)},
                                            {.id = ecs_id(v_SpriteRegistry),
                                             .src = ecs_id(v_SpriteRegistry)}},
                     .query.filter.instanced = 1,
                     .callback = LoadSprite});

  ECS_SYSTEM(world, CleanSpecs, EcsOnUpdate, V_SpriteSpecs);

  V_LogDebug("Assets module initialised");
}
