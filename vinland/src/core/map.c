#include "vinland/core/map.h"
#include "vinland/core/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

V_Map *V_Map_New() {
  V_Map *map = malloc(sizeof(V_Map));
  map->keys = NULL;
  map->values = NULL;

  return map;
}
void V_Map_Add(V_Map *map, char *key, void *value) {

  if (map->keys == NULL || map->keys->data == NULL) {
    map->keys = V_List_New(key);
    map->values = V_List_New(value);

    return;
  }

  V_List_Add(map->keys, key);
  V_List_Add(map->values, value);
}

void V_Map_Remove(V_Map *map, char *key) {
  int index = v_IndexOf(map, key);

  V_Map_RemoveAt(map, index);
}

void V_Map_RemoveAt(V_Map *map, int index) {
  struct V_Node *keyNode = V_List_GetAt(map->keys, index);
  struct V_Node *valueNode = V_List_GetAt(map->values, index);

  V_List_Remove(map->keys, keyNode);
  V_List_Remove(map->values, valueNode);
}

void *V_Map_Get(V_Map *map, char *key) {
  int index = v_IndexOf(map, key);
  return V_List_GetAt(map->values, index)->data;
}

void *V_Map_GetAt(V_Map *map, int index) {
  return V_List_GetAt(map->values, index);
}

int V_Map_HasKey(V_Map *map, char *key) {
  struct V_Node *current = map->keys;

  while (current != NULL) {
    if (strcmp(key, current->data) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}
int V_Map_Count(V_Map *map) {
  int count = 0;
  struct V_Node *current = map->keys;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

void V_Map_Clear(V_Map *map) {
  V_List_Clear(map->keys);
  V_List_Clear(map->values);
}

// Returns -1 when key is not part of the map
int v_IndexOf(V_Map *map, char *key) {
  int index = 0;
  struct V_Node *current = map->keys;

  while (current != NULL) {
    if (strcmp(key, (char *)current->data) == 0) {
      return index;
    }
    index++;
    current = current->next;
  }

  return -1;
}
