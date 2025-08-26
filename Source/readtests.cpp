#include <stdio.h>
#include "tests.h"
#include "list.h"
#include "readtests.h"


int ReadTestData(list* list_ptr, char* test_file)
{
    char file_name[100] = {};
    snprintf(file_name, sizeof(file_name), "%s%s", "Tests/", test_file);
    FILE* file = fopen(file_name,"r");
    if (file == NULL)
    {
        printf("No Tests found\n");
        return 0;
    }

    while (true)
    {
        TestParams t_pars;
        int res = fscanf(file, "%lf %lf %lf %lf %lf %i", &t_pars.a, &t_pars.b, &t_pars.c,
                    &t_pars.x1_res, &t_pars.x2_res,
                    &t_pars.nRoots_res);

        if (res == 6)
        {
            ListAdd(*list_ptr, t_pars);
        }
        else
        {
            return 1;
        }
        fgetc(file);
    }
    fclose(file);
    return 1;
}


