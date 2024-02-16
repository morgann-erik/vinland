#ifndef V_MAP
#define V_MAP

#include "vinland/core/list.h"
typedef struct V_MapNode {
  V_List *keys;
  V_List *values;
} V_Map;

V_Map *V_Map_New();
void V_Map_Add(V_Map *map, char *key, void *value);
void V_Map_Remove(V_Map *map, char *key);
void V_Map_RemoveAt(V_Map *map, int index);
void *V_Map_Get(V_Map *map, char *key);
void *V_Map_GetAt(V_Map *map, int index);
int V_Map_HasKey(V_Map *map, char *key);
int V_Map_Count(V_Map *map);
void V_Map_Clear(V_Map *map);

int v_IndexOf(V_Map *map, char *key);
#endif
