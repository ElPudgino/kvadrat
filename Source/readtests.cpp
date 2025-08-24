#include <stdio.h>
#include "tests.h"
#include "list.h"
#include "readtests.h"


void ReadTestData(list* list_ptr)
{
    FILE* file = fopen("Tests/SolverTests","r");
    if (file == NULL)
    {
        printf("No SolverTests found");
        return;
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
            return;
        }
        fgetc(file);
    }
    fclose(file);
}


