#ifndef SOLVERS_H
#define SOLVERS_H

int SolveQuadratic(double, double, double,
                   double*, double*);

int SolveLinear(double, double, double*);

enum RootsCount
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};

#endif
