#include <stdio.h>
#include "list.h"
#include <cassert>
#include "list_tests.h"


int TestList()
{
    list t_list;
    List_Init(&t_list);

    int res = 1;

    assert(t_list.count == 0);


    int num1 = 52;

    ListAdd(t_list, num1);

    assert(ListGet(t_list, 0, int) == 52);


    int num2 = 69;

    ListAdd(t_list, num2);

    assert(t_list.count == 2);
    assert(ListGet(t_list, 0, int) == 52);


    List_RemoveElementAt(&t_list, 0);

    assert(ListGet(t_list, 0, int) == 69);

    if (res)
    {
        printf("List test: OK");
    }

    return res;
}
