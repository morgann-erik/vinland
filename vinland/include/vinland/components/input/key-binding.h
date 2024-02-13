#ifndef V_KEY_BINDING
#define V_KEY_BINDING

typedef struct V_KeyBinding {
  enum V_Key *Keys;
  int KeyCount;

  char *ActionName;
} V_KeyBinding;

#endif
