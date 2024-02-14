#include "vinland/components/core/action-registry.h"
#include "vinland/components/core/action.h"
#include "vinland/internal/components/core/action-registry.h"
#include "vinland/log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 16

V_ActionRegistry V_NewActionRegistry() {
  V_LogDebug("Creating new actions registry");
  V_ActionRegistry reg;
  reg.Actions = malloc(sizeof(V_Action) * CHUNK_SIZE);
  if (!reg.Actions) {
    V_LogFatal("Failed to create action registry: Out of memory");
    exit(-1);
  }

  return reg;
}
V_ActionRegistry V_AddAction(V_ActionRegistry reg, V_Action action) {

  if (reg.Count == reg.Size) {
    V_LogDebug("Extending registry size");

    reg.Actions =
        realloc(reg.Actions, sizeof(V_Action) * (reg.Size + CHUNK_SIZE));
    if (!reg.Actions) {
      V_LogFatal("Failed to extend action registry: Out of memory");
      exit(-1);
    }
    reg.Size += CHUNK_SIZE;
  }

  reg.Actions[reg.Count] = action;
  reg.Count++;
  return reg;
}

void V_Clear(V_ActionRegistry *reg) { reg->Count = 0; }

int V_Count(V_ActionRegistry *reg) { return reg->Count; }

V_Action V_GetAction(V_ActionRegistry *reg, int index) {
  return reg->Actions[index];
}

void Dispose(V_ActionRegistry *reg) {
  V_LogDebug("Disposing of actions registry");
  free(reg);
  reg = NULL;
}
