#include <stdio.h>
#include <math.h>
#include <cassert>
#include "solvers.h"
#include "tools.h"
#include "constants.h"
#include "tests.h"
#include "list_tests.h"
#include "commands.h"
#include "run_app.h"

int RequestInput(double* a, double* b, double* c);



int main(int argc, char** argv)
{
    printf("\"\" - ");
    list cmds = SetupCommands();

    ProcessArgs(&cmds, argc,  argv);

    ListBegone(cmds);


    printf("\nxXx_COMMIT GITHUB_xXx\n");
    return 0;
}


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

void Run_App()
{
    double a, b, c = 0;
    double x1, x2 = 0;
    int RootCount = 0;

    RequestInput(&a, &b, &c);

    RootCount = SolveQuadratic(a, b, c, &x1, &x2);

    OutputRoots(x1, x2, RootCount);
}



