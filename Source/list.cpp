#include <stdlib.h>
#include <cassert>
#include "list.h"


void List_Init(list* list_p)
{
    assert(list_p);

    list_p -> arr = (void**)malloc(sizeof(void*) * 2);

    assert(list_p -> arr);

    list_p -> capacity = 1;
    list_p -> count = 0;
}

int List_AddElement(list* list_p, void* elem)
{
    assert(list_p);
    assert(list_p -> arr);
    assert(elem);
    assert(elem != list_p);

    int grew = 0;
    size_t capacity = list_p -> capacity;

    if (list_p -> count == capacity)
    {
        List_Expand(list_p);
        grew = 1;
    }

    void** elem_p = list_p -> arr;
    elem_p[list_p -> count] = elem;

    list_p -> count += 1;

    return grew;
}

void List_RemoveElementAt(list* list_p, size_t index)
{
    assert(list_p);
    assert(list_p -> arr);
    assert(index <= (list_p -> count - 1));

    size_t curind = 0;

    void** cur_p = list_p -> arr;

    for (curind = index; curind < (list_p -> count - 1); curind += 1)
    {
        cur_p[curind] = cur_p[curind + 1];

    }

    list_p -> count -= 1;

}

void* List_GetElementAt(list* list_p, size_t index)
{
    assert(list_p);
    assert(list_p -> arr);

    void** ptr = list_p -> arr;

    return ptr[index];
}

void List_Expand(list* list_p)
{
    assert(list_p);
    assert(list_p -> arr);

    list_p -> arr = (void**)realloc(list_p -> arr, (list_p -> capacity) * sizeof(void*) * 2);
    list_p -> capacity *= 2;

    assert(list_p -> arr);
}

void List_Begone(list* list_p)
{
    assert(list_p);
    free(list_p);
}
