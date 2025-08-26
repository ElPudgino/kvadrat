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


command DefSolve()
{
    command solve = {};
    solve.name = "--solve";
    solve.short_name = "-s";
    solve.f_ptr = &SolveCommand;
    solve.args_count = 0;
    return solve;
}

void SolveCommand(list* args)
{
    Run_App();
}


command DefCoef()
{
    command coef = {};
    coef.name = "--coef";
    coef.short_name = "-c";
    coef.f_ptr = &CoefCommand;
    coef.args_count = 3;
    return coef;
}

void CoefCommand(list* args)
{
    assert(args);
    assert(args->count == 3);

    double a, b, c = 0;
    char** e1 = NULL;
    a = strtod(ListGet(*args, 0, char*),e1);
    b = strtod(ListGet(*args, 1, char*),e1);
    c = strtod(ListGet(*args, 2, char*),e1);

    double x1, x2 = 0;
    int nRoots = SolveQuadratic(a, b, c, &x1, &x2);

    OutputRoots(x1, x2, nRoots);
}


command DefFile()
{
    command file = {};
    file.name = "--file";
    file.short_name = "-f";
    file.f_ptr = &FileCommand;
    file.args_count = 1;
    return file;
}

void FileCommand(list* args)
{
    TestQuadraticSolver(ListGet(*args, 0, char*));
}


command DefTest()
{
    command test = {};
    test.name = "--test";
    test.short_name = "-t";
    test.f_ptr = &TestCommand;
    test.args_count = 0;
    return test;
}

void TestCommand(list* args)
{
    TestList();
}

command DefScam()
{
    command scam = {};
    scam.name = "--scam";
    scam.short_name = "-sc";
    scam.f_ptr = &ScamCommand;
    scam.args_count = 0;
    return scam;
}

void ScamCommand(list* args)
{
    double a, b, c = 0;
    double x1, x2 = 0;
    int RootCount = 0;

    RequestInput(&a, &b, &c);
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


