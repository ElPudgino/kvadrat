#ifndef CMDS_DEF_H
#define CMDS_DEF_H

command DefSolve();

command DefCoef();

command DefFile();

command DefTest();

void SolveCommand(list* args);

void CoefCommand(list* args);

void FileCommand(list* args);

void TestCommand(list* args);


#endif
