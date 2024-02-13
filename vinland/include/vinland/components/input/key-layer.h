#ifndef V_KEY_INPUT_LAYER
#define V_KEY_INPUT_LAYER

#include "vinland/components/input/key-binding.h"
typedef struct V_KeyLayer {
  char *Id;

  V_KeyBinding *bindings;
  int BindingCount;
} V_KeyLayer;

#endif
