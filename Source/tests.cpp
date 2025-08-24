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
/*
    TestSolverSingle(0,  0,  0,  0, 0, INF_ROOTS, &res);
    TestSolverSingle(1,  0,  0,  0, 0, ONE_ROOT,  &res);
    TestSolverSingle(0,  1,  1, -1, 0, ONE_ROOT,  &res);
    TestSolverSingle(0, -4, 68, 17, 0, ONE_ROOT,  &res);
    TestSolverSingle(0,  1,  0,  0, 0, ONE_ROOT,  &res);
    TestSolverSingle(1,  1,  0, -1, 0, TWO_ROOTS, &res);
    TestSolverSingle(1, -5,  6,  2, 3, TWO_ROOTS, &res);

    TestSolverSingle(0,     68,    -4,  0.058823529411764, 0                , ONE_ROOT,  &res);
    TestSolverSingle(1e5,  1e4, -2500, -0.215831239517770, 0.115831239517770, TWO_ROOTS, &res);
    TestSolverSingle(1e5, -1e4, -1e6 , -3.11267292017369 , 3.21267292017369 , TWO_ROOTS, &res);

*/
    list t_list;
    ListInit(t_list, sizeof(TestParams));

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


    return res;
}
