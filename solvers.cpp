#include <math.h>
#include <cassert>
#include "tools.h"
#include "constants.h"

int SolveLinear(double a, double b,
                double* x)
{
    assert(x);
    assert(isfinite(a));
    assert(isfinite(b));

    if (CloseToZero(a))
    {
        if (CloseToZero(b))
        {
            return INF_ROOTS;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        *x = -b / a;
        return 1;
    }
}

int SolveQuadraticInternal(double a, double b, double c,
                           double* x1, double* x2)
{
    assert(x1 != x2);
    assert(x1);
    assert(x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    double D = b*b - 4*a*c;
    if (D < 0)
    {
        return 0;
    }
    double rtD = sqrt(D);
    *x1 = (-b - rtD) / (2*a);
    *x2 = (-b + rtD) / (2*a);

    if (CloseToZero(D))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int SolveQuadratic(double a, double b, double c,
                   double* x1, double* x2)
{
    if (CloseToZero(a))
    {
        return SolveLinear(b, c, x1);
    }
    else
    {
        return SolveQuadraticInternal(a, b, c, x1, x2);
    }
}
