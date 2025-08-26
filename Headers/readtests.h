#include "list.h"

#ifndef READTESTS_H
#define READTESTS_H

/*! @brief Reads tests data from file
*
* @param[in] list_ptr Pointer to list where read data will be stored
* @param[in] test_file Name of the file to read
*
* @return 1 if file was found 0 otherwise
*/
int ReadTestData(list* list_ptr, char* test_file);


#endif
