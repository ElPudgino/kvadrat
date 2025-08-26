#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "passert.h"
#include "constants.h"
#include "tools.h"
#include "list.h"
#include "commands.h"
#include "solvers.h"

void ClearInput()
{
    while (getchar() != '\n');
}

int GetInputNumber(double* num)
{
    h_passert(num);
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
    h_passert(isfinite(num));
    return (fabs(num) < EPSILON);
}

void PolishOutput(double* num)
{
    h_passert(num);
    if (CloseToZero(*num))
    {
        *num = 0;
    }
}

int CompareStrings(char* str1, const char* str2)
{
    h_passert(str1);
    h_passert(str2);

    int index = 0;


    while (str1[index] != '\0' && str2[index] != '\0')
    {
        if (str1[index] != str2[index])
        {
            return 0;
        }
        index += 1;
    }
    if (str1[index] != str2[index])
    {
        return 0;
    }

    return 1;
}

void OutputRoots(double x1, double x2, int nRoots)
{
    PolishOutput(&x1);
    PolishOutput(&x2);

    switch (nRoots)
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
        default:
            printf("Error: Unexpected root count");
        break;
    }
}

int RandomRange(int min, int max)
{
    srand(time(NULL));
    int range = (max - min);
    int add = rand() % range;
    return min + add;
}

int RequestInput(double* a, double* b, double* c)
{
    h_passert(a);
    h_passert(b);
    h_passert(c);
    h_passert(a != b);
    h_passert(b != c);
    h_passert(a != c);

    printf("Enter equation coefficients\n");

    GetInputNumber(a);
    GetInputNumber(b);
    GetInputNumber(c);

    return 1;
}

int RequestAnswer(double* a, double* b, double* c)
{
    h_passert(a);
    h_passert(b);
    h_passert(c);
    h_passert(a != b);
    h_passert(b != c);
    h_passert(a != c);

    printf("Enter root amount, x1, x2\n");

    GetInputNumber(a);
    GetInputNumber(b);
    GetInputNumber(c);

    return 1;
}
