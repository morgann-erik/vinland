#ifndef _V_ACTION_REGISTRY
#define _V_ACTION_REGISTRY

#include "vinland/components/core/action.h"

typedef struct V_ActionRegistry {
    int Count;
    int Size;

    V_Action *Actions;
} V_ActionRegistry;

#endif
