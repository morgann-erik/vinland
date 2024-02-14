#include "vinland/internal/modules/input.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "vinland/components/input/key-layer.h"
#include "vinland/internal/components/input/keyboard-state.h"
#include "vinland/internal/input/key-layer-manager.h"
#include "vinland/internal/input/keyboard-processor.h"
#include "vinland/log.h"

extern ECS_COMPONENT_DECLARE(V_ActionRegistry);
ECS_COMPONENT_DECLARE(v_KeyboardState);
ECS_COMPONENT_DECLARE(V_KeyLayer);

void v_InputModuleImport(ecs_world_t *world) {
  ECS_MODULE(world, V_InputModule);

  ECS_COMPONENT_DEFINE(world, v_KeyboardState);
  ECS_COMPONENT_DEFINE(world, V_KeyLayer);

  ecs_system(world, {.entity = ecs_entity(
                         world, {.name = "Keyboard Processor",
                                 .add = {ecs_dependson(EcsOnUpdate)}}),
                     .query.filter.terms = {{.id = ecs_id(v_KeyboardState),
                                             .src = ecs_id(v_KeyboardState)}},
                     .callback = v_ProcessKeyboardInput});

  ecs_system(world, {.entity = ecs_entity(
                         world, {.name = "Keyboard Layer Manager",
                                 .add = {ecs_dependson(EcsOnUpdate)}}),
                     .query.filter.terms = {{.id = ecs_id(V_KeyLayer)},
                                            {.id = ecs_id(v_KeyboardState),
                                             .src = ecs_id(v_KeyboardState)},
                                            {.id = ecs_id(V_ActionRegistry),
                                             .src = ecs_id(V_ActionRegistry)}},
                     .query.filter.instanced = true,
                     .callback = v_CheckActiveKeyLayers});

  ecs_singleton_set(world, v_KeyboardState, {.Keys = {}});
  V_LogDebug("Input module imported");
}
