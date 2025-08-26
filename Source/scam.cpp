#include <stdio.h>
#include "tools.h"
#include "solvers.h"
#include "scam.h"

int CaptchaCheck()
{
    int a, b, c = 0;
    int roots_i = 0;
    double x1_i, x2_i = 0;
    double x1, x2 = 0;

    int roots = 0;

    a = RandomRange(-1e3, 1e3);
    b = RandomRange(-1e4, 1e4);
    c = RandomRange(-1e5, 1e5);

    char sign1, sign2, sign3 = ' ';

    if (a > 0)
    {
        sign1 = '+';
    }
    if (b > 0)
    {
        sign2 = '+';
    }
    if (c > 0)
    {
        sign3 = '+';
    }

    printf("Solve %c%dx^2%c%dx%c%d = 0\n", sign1, a, sign2, b, sign3, c);

    double roots_i_d = 0;

    RequestInput(&roots_i_d, &x1_i, &x2_i);
    roots_i = (int)roots_i_d;

    roots = SolveQuadratic(a, b, c, &x1, &x2);

    if (roots == roots_i && ((CloseToZero(x2 - x1_i) && CloseToZero(x1 - x2_i)) ||
                                  (CloseToZero(x1 - x1_i) && CloseToZero(x2 - x2_i))))
    {
        return 1;
    }
    return 0;
}
