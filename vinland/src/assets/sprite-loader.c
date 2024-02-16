#include "vinland/internal/assets/sprite-loader.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "raylib.h"
#include "vinland/components/assets/sprite-specs.h"
#include "vinland/core/map.h"
#include "vinland/internal/components/assets/sprite-registry.h"
#include "vinland/log.h"
#include <stdlib.h>

void LoadSprite(ecs_iter_t *it) {
  V_SpriteSpecs *specs = ecs_field(it, V_SpriteSpecs, 1);
  v_SpriteRegistry *reg = ecs_field(it, v_SpriteRegistry, 2);

  for (int i = 0; i < it->count; i++) {
    if (specs[i].Handled == 1) {
      V_LogDebugf("%s already loaded\n", specs[i].Id);
      return;
    }

    V_LogDebugf("Loading %s\n", specs[i].Id);
    Texture *texture = malloc(sizeof(Texture));
    Texture t = LoadTexture(specs[i].Path);

    texture->id = t.id;
    texture->width = t.width;
    texture->height = t.height;
    texture->format = t.format;
    texture->mipmaps = t.mipmaps;

    specs[i].Handled = 1;
    V_Map_Add(reg->map, specs[i].Id, texture);
  }
}

void CleanSpecs(ecs_iter_t *it) {
  V_SpriteSpecs *specs = ecs_field(it, V_SpriteSpecs, 1);

  for (int i = 0; i < it->count; i++) {
    if (!specs[i].Handled) {
      return;
    }

    ecs_delete(it->world, it->entities[i]);
  }
}
