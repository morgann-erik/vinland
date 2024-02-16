#include "vinland/internal/renderer/renderer.h"
#include "raylib.h"
#include "vinland/components/renderer/position.h"
#include "vinland/core/map.h"
#include "vinland/internal/components/assets/sprite-registry.h"

void Render(ecs_iter_t *it) {
  V_Position *p = ecs_field(it, V_Position, 1);
  v_SpriteRegistry *reg = ecs_field(it, v_SpriteRegistry, 2);

  BeginDrawing();

  ClearBackground(WHITE);

  for (int i = 0; i < it->count; i++) {
    DrawCircle(p[i].x, p[i].y, 16, RED);
  }
    if (V_Map_HasKey(reg->map, "test")){
        Vector2 position = {.x = 32,.y = 32};
        DrawTextureEx(*(Texture*)V_Map_Get(reg->map, "test"), position, 0, 0.5, WHITE);
    }

  EndDrawing();
}
