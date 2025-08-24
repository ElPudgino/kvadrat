#ifndef LIST_H
#define LIST_H

typedef struct
{
    void** arr;
    size_t capacity;
    size_t count;
} list;



void List_Init(list* list_p);

int List_AddElement(list* list_p, void* elem);

void List_RemoveElementAt(list* list_p, size_t index);

void* List_GetElementAt(list* list_p, size_t index);

void List_Expand(list* list_p);

void List_Begone(list* list_p);


#define ListAdd(lst,elm) List_AddElement(&lst, &elm)

#define ListGet(lst,idx,type) *(type*)List_GetElementAt(&lst, idx)

#endif
