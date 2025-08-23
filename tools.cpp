#include <stdio.h>
#include <math.h>
#include <cassert>
#include "constants.h"

int ClearInput();

int GetInputNumber(double* num);

bool CloseToZero(double);

void PolishOutput(double* in);


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

bool CloseToZero(double num)
{
    assert(isfinite(num));
    return (fabs(num) < EPSILON);
}

void PolishOutput(double* in)
{
    if (CloseToZero(*in))
    {
        *in = 0;
    }
}
