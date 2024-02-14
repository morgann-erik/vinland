#ifndef V_ACTION_REGISTRY
#define V_ACTION_REGISTRY

#include "vinland/components/core/action.h"
#include "vinland/internal/components/core/action-registry.h"

V_ActionRegistry V_NewActionRegistry();
V_ActionRegistry V_AddAction(V_ActionRegistry reg, V_Action action);
void V_Clear(V_ActionRegistry *reg);
int V_ActionsCount(V_ActionRegistry *reg);
V_Action V_GetAction(V_ActionRegistry *reg, int index);
void Dispose(V_ActionRegistry *reg);

#endif
