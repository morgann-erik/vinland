#include "vinland/core/list.h"
#include "vinland/log.h"
#include <stdio.h>
#include <stdlib.h>

V_List *V_List_New(void *data) {
  struct V_Node *node = NULL;
  node = (struct V_Node *)malloc(sizeof(struct V_Node));
  node->next = NULL;
  node->data = data;

  return node;
}

void V_List_Insert(V_List *head, void *data) {
  struct V_Node *newNode = (struct V_Node *)malloc(sizeof(struct V_Node));
  if (!newNode) {
    V_LogFatal("Out of memory");
    exit(-1);
  }

  newNode->data = data;
  newNode->next = NULL;

  if (!head->next) {
    head->next = newNode;
    return;
  }

  struct V_Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
}

V_List *V_List_Delete(V_List *head, struct V_Node *node) {
  if (head == NULL || node == NULL) {
    V_LogError("Attempting to delete list element that doesn't exist");
    return head;
  }

  if (head == node) {
    V_LogDebugf("Removing first element %d new head %d", *(int *)head->data,
                *(int *)node->next->data);
    head = node->next;

    free(node);
    return head;
  }

  struct V_Node *current = head;
  while (current != NULL) {
    if (current->next == node) {
      current->next = node->next;
      free(node);
      return head;
    }

    current = current->next;
  }

  V_LogErrorf("Delete failed: Can't find %d in the list", *(int *)node->data);
  return head;
}

int V_List_Count(V_List *head) {
  if (head == NULL) {
    return 0;
  }

  struct V_Node *current = head;
  int count = 1;
  while (current->next != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

/*
 * Reutrns null when index out of bounds
 */
struct V_Node *V_List_GetAt(V_List *head, int index) {
  int count = V_List_Count(head);
  if (index == 0) {
    return head;
  }

  V_LogDebugf("%d >= %d", count, index);
  if (count <= index) {
    V_LogFatal("Index out of bounds");
    return NULL;
  }

  struct V_Node *current = head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }

  return current;
}

V_List *V_List_Clear(V_List *head) {
  struct V_Node *current = head->next;
  struct V_Node *next;
  while (current != NULL) {
    next = current->next;

    current->next = NULL;
    current->data = NULL;
    free(current);

    current = next;
  }

  return NULL;
}
