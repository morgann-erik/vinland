#ifndef V_KEY_BINDING
#define V_KEY_BINDING

#include "vinland/components/input/key.h"

typedef struct V_KeyBinding {
  V_Key *Keys;
  int KeyCount;

  char *ActionName;
} V_KeyBinding;

#endif
