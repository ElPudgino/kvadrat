#ifndef CMDS_DEF_H
#define CMDS_DEF_H



command DefSolve();

command DefCoef();

command DefFile();

command DefTest();

command DefScam();

void SolveCommand(list* args);

void CoefCommand(list* args);

void FileCommand(list* args);

void TestCommand(list* args);

void ScamCommand(list* args);

void DebugCommand(list* args);


static command Solve{"--solve", "-s", &SolveCommand, 0};

static command Coef{"--coef", "-c", &CoefCommand, 3};

static command File{"--file", "-f", &FileCommand, 1};

static command Test{"--test", "-t", &TestCommand, 0};

static command Scam{"--scam", "-sc", &ScamCommand, 0};

static command Debug{"--debug", "-d", &DebugCommand, 0};

#endif
