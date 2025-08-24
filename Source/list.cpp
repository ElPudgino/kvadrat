#include <stdlib.h>
#include <cassert>
#include "list.h"
#include <cstring>


void List_Init(list* list_p, size_t element_size)
{
    assert(list_p);
    list_p -> elem_size = element_size;
    list_p -> arr = malloc(list_p -> elem_size * 2);

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

    void* elem_p = list_p -> arr + list_p -> elem_size * list_p -> count;

    memcpy(elem_p, elem, list_p -> elem_size);

    list_p -> count += 1;

    return grew;
}

void List_RemoveElementAt(list* list_p, size_t index)
{
    assert(list_p);
    assert(list_p -> arr);
    assert(index <= (list_p -> count - 1));

    size_t elemsize = list_p -> elem_size;
    size_t cur_ind = 0;

    void* cur_p = NULL;
    void* next_p = NULL;

    for (cur_ind = index; cur_ind < (list_p -> count - 1); cur_ind += 1)
    {
        cur_p = list_p -> arr + cur_ind * elemsize;
        next_p = list_p -> arr + (cur_ind + 1) * elemsize;

        memcpy(cur_p, next_p, elemsize);
    }

    list_p -> count -= 1;

}

void* List_GetElementAt(list* list_p, size_t index)
{
    assert(list_p);
    assert(list_p -> arr);

    void* ptr = list_p -> arr + index * list_p -> elem_size;

    return ptr;
}

void List_Expand(list* list_p)
{
    assert(list_p);
    assert(list_p -> arr);

    list_p -> arr = realloc(list_p -> arr, (list_p -> capacity) * list_p -> elem_size * 2);
    list_p -> capacity *= 2;

    assert(list_p -> arr);
}

void List_Begone(list* list_p)
{
    assert(list_p);
    free(list_p -> arr);
}


