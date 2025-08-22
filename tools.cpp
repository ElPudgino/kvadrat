#include <stdio.h>
#include <math.h>
#include "constants.h"

int ClearInput()
{
    while (getchar() != '\n');
    return 0;
}

int GetInputNumber(double* num)
{
    if (scanf("%lf", num) < 1)
    {
        printf("Invalid input. Enter a number\n");
        ClearInput();
        GetInputNumber(num);
    }
    else if (!isfinite(*num))
    {
        printf("Invalid input. Enter a finite number\n");
        ClearInput();
        GetInputNumber(num);
    }

    return 0;
}

bool CloseToZero(double num)
{
    return fabs(num) < ALMOST_ZERO;
}
