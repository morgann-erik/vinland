#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "raylib.h"
#include "vinland/components/assets/sprite-specs.h"
#include "vinland/components/input/key-binding.h"
#include "vinland/components/input/key-layer.h"
#include "vinland/components/input/key.h"
#include "vinland/vinland.h"
#include <stdio.h>
#include <stdlib.h>

extern ECS_COMPONENT_DECLARE(V_KeyLayer);
extern ECS_COMPONENT_DECLARE(V_SpriteSpecs);

int main(void) {
  ecs_world_t *world;

  world = V_InitCore();

  int bindingsCount = 1;
  int keyCount = 1;
  V_Key *keys = malloc(keyCount * sizeof(int));
  keys[0] = V_KEY_A;
  V_KeyBinding *bindings = malloc(bindingsCount * sizeof(V_KeyBinding));
  V_KeyBinding b = {.KeyCount = keyCount,
                    .ActionName = "Test",
                    .Keys = keys,
                    .Trigger = v_KEY_DOWN};
  bindings[0] = b;
  ecs_entity_t e = ecs_new_entity(world, "Test layer");
  ecs_set(world, e, V_KeyLayer,
          {.Id = "Test", .BindingCount = bindingsCount, .Bindings = bindings});

  ecs_entity_t s = ecs_new_entity(world, "Test Sprite Specs");
  ecs_set(world, s, V_SpriteSpecs,
          {.Handled = 0, .Id = "test", .Path = "assets/sprites/test.png"});
    printf("\nSet test specs\n");

  V_Run(world);

  CloseWindow();
  V_CleanUp();

  return 0;
}
