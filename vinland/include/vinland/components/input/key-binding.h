#ifndef V_KEY_BINDING
#define V_KEY_BINDING

#include "vinland/components/input/key.h"
#include "vinland/internal/components/input/keyboard-state.h"

typedef struct V_KeyBinding {
  KeyState Trigger;
  V_Key *Keys;
  int KeyCount;

  char *ActionName;
} V_KeyBinding;

#endif
