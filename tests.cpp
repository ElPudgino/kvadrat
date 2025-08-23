#include <stdio.h>
#include "tools.h"
#include "solvers.h"
#include "constants.h"

void TestSingle(double a, double b, double c,
               double x1_res, double x2_res, int nRoots_res, int* res)
{
    double x1 = 0,x2 = 0;
    int nRoots = SolveQuadratic(a, b, c, &x1, &x2);
    if (nRoots != nRoots_res || !((CloseToZero(x2 - x1_res) && CloseToZero(x1 - x2_res)) ||
                                  (CloseToZero(x1 - x1_res) && CloseToZero(x2 - x2_res))))
    {
        printf("Failed: SolveQuadratic(%lf, %lf, %lf) -> %i (%lf, %lf); Expected %i (%lf, %lf)",
                                         a, b, c, nRoots, x1, x2, nRoots_res, x1_res, x2_res);
        *res = *res * 0;
    }
}

int TestQuadraticSolver()
{
    int res = 1;

    TestSingle(0,  0, 0,  0, 0, INF_ROOTS, &res);
    TestSingle(1,  0, 0,  0, 0, ONE_ROOT,  &res);
    TestSingle(0,  1, 1, -1, 0, ONE_ROOT,  &res);
    TestSingle(0,  1, 0,  0, 0, ONE_ROOT,  &res);
    TestSingle(1,  1, 0, -1, 0, TWO_ROOTS, &res);
    TestSingle(1, -5, 6,  2, 3, TWO_ROOTS, &res);

    if (res)
    {
        printf("Solver test: OK\n");
    }

    return res;
}
