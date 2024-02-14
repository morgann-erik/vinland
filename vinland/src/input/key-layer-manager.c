#include "vinland/internal/input/key-layer-manager.h"
#include "flecs/addons/flecs_c.h"
#include "vinland/components/core/action-registry.h"
#include "vinland/components/core/action.h"
#include "vinland/components/input/key-binding.h"
#include "vinland/components/input/key-layer.h"
#include "vinland/internal/components/core/action-registry.h"
#include "vinland/internal/components/input/keyboard-state.h"
#include "vinland/log.h"
#include <stdbool.h>

#define BINDING_TRIGGERED_MSG "Binding triggered: Action "

extern ECS_COMPONENT_DECLARE(V_KeyLayer);

void v_CheckActiveKeyLayers(ecs_iter_t *it) {
  V_KeyLayer *layers = ecs_field(it, V_KeyLayer, 1);
  v_KeyboardState *state = ecs_field(it, v_KeyboardState, 2);
  V_ActionRegistry *reg = ecs_field(it, V_ActionRegistry, 3);

  V_KeyLayer l;
  for (int i = 0; i < it->count; i++) {
    l = layers[i];

    for (int j = 0; j < l.BindingCount; j++) {
      V_KeyBinding b = l.Bindings[j];

      bool ok = true;
      for (int m = 0; m < b.KeyCount; m++) {
        if (state->Keys[b.Keys[m]] != b.Trigger) {
          ok = false;
          break;
        }
      }

      if (ok) {
        V_LogDebug(BINDING_TRIGGERED_MSG);
        V_Action action = {.Name = "Test"};
        reg[0] = V_AddAction(reg[0], action);
      }
    }
  }
}
