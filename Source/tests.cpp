#include <stdio.h>
#include "tools.h"
#include "solvers.h"
#include "constants.h"
#include "readtests.h"
#include "list.h"
#include "tests.h"


void TestSolverSingle(TestParams tps, int* res)
{
    double x1 = 0,x2 = 0;

    int nRoots = SolveQuadratic(tps.a, tps.b, tps.c, &x1, &x2);
    if (nRoots != tps.nRoots_res || !((CloseToZero(x2 - tps.x1_res) && CloseToZero(x1 - tps.x2_res)) ||
                                  (CloseToZero(x1 - tps.x1_res) && CloseToZero(x2 - tps.x2_res))))
    {
        printf("Failed: SolveQuadratic(%lf, %lf, %lf) -> %i (%lf, %lf); Expected %i (%lf, %lf)\n",
                                         tps.a, tps.b, tps.c, nRoots, x1, x2, tps.nRoots_res, tps.x1_res, tps.x2_res);
        *res = 0;
    }
}

int TestQuadraticSolver()
{
    int res = 1;
    list t_list;

    ListInit(t_list, TestParams);

    ReadTestData(&t_list);

    size_t test_ind = 0;

    for (test_ind = 0; test_ind < t_list.count; test_ind += 1)
    {
        TestSolverSingle(ListGet(t_list, test_ind, TestParams), &res);
    }

    if (res)
    {
        printf("Solver test: OK\n");
    }

    ListBegone(t_list);

    return res;
}
