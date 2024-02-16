#include "vinland/internal/components/assets/sprite-registry.h"
#include "vinland/core/map.h"

v_SpriteRegistry v_NewSpriteRegistry() {
    v_SpriteRegistry reg = {.map = V_Map_New()};

    return reg;
}
