#define MAIN_FILE

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
#include "passert.h"


int RequestInput(double* a, double* b, double* c);



int main(int argc, char** argv)
{
    printf("\"miay\" - c. Poltorashka\n");
    list cmds = SetupCommands();

    ProcessArgs(&cmds, argc,  argv);

    ListBegone(cmds);

    printf("\nxXx_COMMIT GITHUB_xXx\n");
    return 0;
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



