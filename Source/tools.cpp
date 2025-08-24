#include <stdio.h>
#include <math.h>
#include <cassert>
#include "constants.h"
#include "tools.h"

int ClearInput()
{
    while (getchar() != '\n');
    return 0;
}

int GetInputNumber(double* num)
{
    assert(num);
    int res = 0;
    while (true)
    {
        res = scanf("%lf", num);
        if (res == 1 && isfinite(*num))
        {
            break;
        }
        printf("Invalid input. Enter a finite number\n");
        ClearInput();
    }

    return 0;
}

int CloseToZero(double num)
{
    assert(isfinite(num));
    return (fabs(num) < EPSILON);
}

void PolishOutput(double* num)
{
    if (CloseToZero(*num))
    {
        *num = 0;
    }
}

void ProcessArgs()
{

}
