#include <stdio.h>
#include <math.h>
#include <cassert>
#include "solvers.h"
#include "tools.h"
#include "constants.h"
#include "tests.h"

int RequestInput(double* a, double* b, double* c)
{
    assert(a);
    assert(b);
    assert(c);
    assert(a != b);
    assert(b != c);
    assert(a != c);

    printf("Quadratic equation solver\n----------------\n");
    printf("Enter equation coefficients\n");

    GetInputNumber(a);
    GetInputNumber(b);
    GetInputNumber(c);

    return 1;
}

int main()
{
    double a, b, c = 0;
    double x1, x2 = 0;
    int RootCount = 0;

    TestQuadraticSolver();

    RequestInput(&a, &b, &c);

    RootCount = SolveQuadratic(a, b, c, &x1, &x2);

    switch (RootCount)
    {
        case NO_ROOTS:
            printf("No roots\n");
        break;
        case ONE_ROOT:
            printf("One root: %lf \n", x1);
        break;
        case TWO_ROOTS:
            printf("Two roots: %lf, %lf \n", x1, x2);
        break;
        case INF_ROOTS:
            printf("Infinite roots\n");
        break;

    }

    return 0;
}


