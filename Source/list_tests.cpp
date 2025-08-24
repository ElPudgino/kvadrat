#include <stdio.h>
#include "list.h"
#include <cassert>
#include "list_tests.h"


int TestList()
{
    list t_list;
    List_Init(&t_list, sizeof(int));

    int res = 1;

    assert(t_list.count == 0);


    int num1 = 52;

    ListAdd(t_list, num1);

    assert(ListGet(t_list, 0, int) == 52);


    int num2 = 69;

    ListAdd(t_list, num2);

    assert(t_list.count == 2);
    assert(ListGet(t_list, 0, int) == 52);


    ListRemoveAt(t_list, 0);

    assert(ListGet(t_list, 0, int) == 69);


    size_t k = 0;

    for (k = 0; k < 100; k += 1)
    {
        ListAdd(t_list, k);
    }
    assert(t_list.count == k+1);

    for (k = 0; k < t_list.count; k += 2)
    {
        ListRemoveAt(t_list, k);
    }
    assert(ListGet(t_list, 0, int) == 0);
    assert(ListGet(t_list, 1, int) == 1);
    assert(ListGet(t_list, 2, int) == 3);

    ListBegone(t_list);

    if (res)
    {
        printf("List test: OK\n");
    }

    return res;
}
