#ifndef _V_KEYBOARD_STATE
#define _V_KEYBOARD_STATE

typedef enum {
  v_KEY_RELEASED = 0,
  v_KEY_DOWN = 1,
  v_KEY_PRESSED = 2,
  v_KEY_UP = 4
} KeyState;

#define v_KEYMAP_SIZE 336

typedef struct v_KeyboardState {
  KeyState Keys[v_KEYMAP_SIZE];
} v_KeyboardState;

#endif
