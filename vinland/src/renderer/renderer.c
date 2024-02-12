#include "vinland/internal/renderer/renderer.h"
#include "raylib.h"
#include "vinland/components/renderer/position.h"

void Render(ecs_iter_t *it) {
  V_Position *p = ecs_field(it, V_Position, 1);

  BeginDrawing();

  ClearBackground(WHITE);
  for (int i = 0; i < it->count; i++) {
    DrawCircle(p[i].x, p[i].y, 16, RED);
  }

  EndDrawing();
}
