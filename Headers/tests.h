#ifndef TESTS_H
#define TESTS_H

/** Tests quadratic solver using predefined values
*/
int TestQuadraticSolver(void);

typedef struct
{
    double a, b, c;
    double x1_res, x2_res;
    int nRoots_res;
} TestParams;

#endif
