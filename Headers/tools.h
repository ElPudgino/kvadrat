#ifndef TOOLS_H
#define TOOLS_H

/*! @brief Holds info about starting args
*/
typedef struct
{
    int test_list;
    int test_solver;
    int skip_main;
} ProgramParams;

/*! @brief Clears input buffer
*/
void ClearInput(void);

/*! @brief Scans input for a finite double
*
* @param[in] num Pointer to where the scanned double will be written
*
* Scans until a valid double is found
*/
int GetInputNumber(double*);

/*! @brief Checks if double can be considered an inaccuracy
*
* @param[in] num Double to be checked
*
* @return 1 if absolute value of num is smaller then EPSILON 0 otherwise
*/
int CloseToZero(double);

/*! @brief Process double for printing
*
* @param[in] num Pointer to the processed double
*
* Round num to zero if it is negligibly small
*/
void PolishOutput(double*);

/*! @brief Checks if two strings are equal
*
* @param[in] str1 First string
* @param[in] str2 Second constant string
*
* Both strings MUST end with a null terminator
* Checks each chars one by one
*
* @return 1 if equal 0 otherwise
*/
int CompareStrings(char* str1, const char* str2);

/*! @brief Parses program arguments
*
* @param[in] argc Argument count
* @param[in] argv Array of pointers to arguments
*
* @return Struct with field set to 1 or 0 depending on args
*/
ProgramParams ProcessArgs(int argc ,char** argv);


/*! @brief Outputs solver result
*
* @param[in] x1 First roots
* @param[in] x2 Second root
* @param[in] nRoots Amount of roots
*/
void OutputRoots(double x1, double x2, int nRoots);

/*! @brief Generate pseudo-random int
*
* @param[in] min Min value (inclusive)
* @param[in] max Max value (exclusive)
*
* @return Random int from min inclusive to max exclusive
*/
int RandomRange(int min, int max);

/*! @brief Request user to enter 3 valid coefficients
*
* @param[in] a First read value
* @param[in] b Second read value
* @param[in] c Third read value
*
* @return 1
*/
int RequestInput(double* a, double* b, double* c);

/*! @brief Request user to enter roots of the equation
*
* @param[in] a Roots amount entered
* @param[in] b First root entered
* @param[in] c Second root entered
*
* @return 1
*/
int RequestAnswer(double* a, double* b, double* c);

#endif
