#include "vinland/internal/modules/input.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "vinland/internal/components/input/keyboard-state.h"
#include "vinland/internal/input/keyboard-processor.h"
#include "vinland/log.h"

ECS_COMPONENT_DECLARE(v_KeyboardState);

void v_InputModuleImport(ecs_world_t *world) {
  ECS_MODULE(world, V_InputModule);

  ECS_COMPONENT_DEFINE(world, v_KeyboardState);
  ecs_system(world, {.entity = ecs_entity(
                         world, {.name = "Keyboard Processor",
                                 .add = {ecs_dependson(EcsOnUpdate)}}),
                     .query.filter.terms = {{.id = ecs_id(v_KeyboardState),
                                             .src = ecs_id(v_KeyboardState)}},
                     .callback = v_ProcessKeyboardInput});

  ecs_singleton_set(world, v_KeyboardState, {.Keys = {}});
  V_LogDebug("Input module imported");
}
