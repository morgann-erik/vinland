#include "vinland/internal/input/keyboard-processor.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "raylib.h"
#include "vinland/internal/components/input/keyboard-state.h"
#include <stdio.h>

extern ECS_COMPONENT_DECLARE(v_KeyboardState);

void v_ProcessKeyboardInput(ecs_iter_t *it) {
  v_KeyboardState *state = ecs_field(it, v_KeyboardState, 1);

  KeyState keyState;
  for (int i = 0; i < v_KEYMAP_SIZE; i++) {
    keyState = state->Keys[i];

    if (state->Keys[i] == v_KEY_UP) {
      state->Keys[i] = v_KEY_RELEASED;
      continue;
    }
    if (IsKeyDown(i) && state->Keys[i] == v_KEY_DOWN) {
      state->Keys[i] = v_KEY_PRESSED;
      continue;
    }
    if (IsKeyDown(i) && state->Keys[i] == v_KEY_RELEASED) {
      state->Keys[i] = v_KEY_DOWN;
      continue;
    }
    if (IsKeyUp(i) && state->Keys[i] != v_KEY_RELEASED) {
      state->Keys[i] = v_KEY_UP;
      continue;
    }
  }
  return;

  for (int i = 0; i < v_KEYMAP_SIZE; i++) {
    keyState = state->Keys[i];
    if (keyState == v_KEY_UP) {
      printf("KeyIdle %d\n", i);
      state->Keys[i] = v_KEY_RELEASED;
      continue;
    }
    if (keyState == v_KEY_DOWN) {
      printf("KeyUp %d\n", i);
      state->Keys[i] = v_KEY_UP;
    }
  }

  int keyId = GetKeyPressed();
  if (keyId == 0)
    return;

  while (keyId != 0) {
    if (state->Keys[keyId] == v_KEY_RELEASED) {
      printf("KeyDown %d\n", keyId);
      state->Keys[keyId] = v_KEY_DOWN;
      break;
    }
    keyId = GetKeyPressed();
  }
}
