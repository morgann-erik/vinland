#include "vinland/internal/core/startup-raylib.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include "raylib.h"
#include "vinland/internal/components/core/app-specs.h"
#include "vinland/log.h"
#include <stdlib.h>

void v_StartupRaylib(ecs_iter_t *it) {
  v_ApplicationSpecs *specs = ecs_field(it, v_ApplicationSpecs, 1);

  if (it->count == 0) {
    V_LogFatal("Can't startup raylib: ApplicationSpecs not found");
    exit(-1);
  }

  if (it->count > 1) {
    V_LogFatal("Can't startup raylib: Multiple ApplicationSpecs found");
    exit(-1);
  }

  v_ApplicationSpecs s = specs[0];

  SetTargetFPS(60);
  InitWindow(s.WindowWidth, s.WindowHeight, s.WindowTitle);

  V_LogDebug("Raylib startup: COMPLETED");
}
