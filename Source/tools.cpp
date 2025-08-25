#include <stdio.h>
#include <math.h>
#include <cassert>
#include "constants.h"
#include "tools.h"

void ClearInput()
{
    while (getchar() != '\n');
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

int CompareStrings(char* str1, char const* str2)
{
    assert(str1);
    assert(str2);

    int index = 0;

    while (str1[index] != '\0' && str2[index] != '\0')
    {
        if (str1[index] != str2[index])
        {
            return 0;
        }
        index += 1;
    }


    return 1;
}

#define CheckForParam(prm) if (CompareStrings(argv[1+index], "-"#prm)) { p_params.prm = 1; }

ProgramParams ProcessArgs(int argc ,char** argv)
{
    ProgramParams p_params = {};

    int index = 0;
    for (index = 0; index < (argc-1); index += 1)
    {
        CheckForParam(skip_main);
        CheckForParam(test_solver);
        CheckForParam(test_list);
    }

    return p_params;
}
