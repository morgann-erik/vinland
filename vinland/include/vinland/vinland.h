#ifndef V_VINLAND
#define V_VINLAND

#include "flecs.h"

ecs_world_t *V_InitCore();
void V_Run(ecs_world_t *world);
void V_CleanUp();

#endif
