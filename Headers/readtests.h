#include "list.h"

#ifndef READTESTS_H
#define READTESTS_H

size_t CountTests(FILE* file);

void ReadTestSingle(FILE* file, list* list_ptr);

void ReadTestData(list* list_ptr);


#endif
