#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "list.h"
#include "commands.h"
#include "run_app.h"
#include "commands_def.h"
#include "tools.h"
#include "solvers.h"
#include "tests.h"
#include "list_tests.h"
#include "scam.h"
#include "passert.h"


void SolveCommand(list* args)
{
    Run_App();
}

void CoefCommand(list* args)
{
    assert(args);
    assert(args->count == 3);

    double a = 0, b = 0, c = 0;
    char** e1 = NULL;
    a = strtod(ListGet(*args, 0, char*),e1);
    b = strtod(ListGet(*args, 1, char*),e1);
    c = strtod(ListGet(*args, 2, char*),e1);

    double x1 = 0, x2 = 0;
    int nRoots = SolveQuadratic(a, b, c, &x1, &x2);

    OutputRoots(x1, x2, nRoots);
}

void FileCommand(list* args)
{
    assert(args);
    assert(args->count == 1);
    TestQuadraticSolver(ListGet(*args, 0, char*));
}

void TestCommand(list* args)
{
    assert(args);
    TestList();
}

void ScamCommand(list* args)
{
    assert(args);
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int RootCount = 0;

    RequestAnswer(&a, &b, &c);
    RootCount = SolveQuadratic(a, b, c, &x1, &x2);

    printf("CAPTCHA:\nSolve the following equations to prove you are a human\nWrite amount of roots (-1 if infinite) and each root\n");

    long long int count = 5206903228;
    long long int passed = 0;
    int ok = 0;

    while (count > 0)
    {
        ok = CaptchaCheck();

        if (ok)
        {
            count -= 1;
            passed += 1;
            printf("Correct.\n%lld / %lld tests passed.\n", passed, count);
        }
        else
        {
            printf("Incorrect.");
            int* aboba = NULL;
            ok = *aboba;
        }
    }
    printf("Captcha passed successfuly\n");
    OutputRoots(x1, x2, RootCount);
}

void DebugCommand(list* args)
{
    debug = 1;
}
