#ifndef _V_SPRITE_REGISTRY
#define _V_SPRITE_REGISTRY

#include "vinland/core/map.h"

typedef struct v_SpriteRegistry {
    V_Map *map;
} v_SpriteRegistry;

v_SpriteRegistry v_NewSpriteRegistry();

#endif
