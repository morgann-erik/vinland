#ifndef V_LIST
#define V_LIST

typedef struct V_Node {
  void *data;
  struct V_Node *next;
} V_List;

V_List *V_List_New(void *data);

void V_List_Insert(V_List *head, void *data);

V_List *V_List_Delete(V_List *head, struct V_Node *node);

int V_List_Count(V_List *head);

struct V_Node *V_List_GetAt(V_List *head, int index);

V_List *V_List_Clear(V_List *head);

#endif
