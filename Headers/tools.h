#ifndef TOOLS_H
#define TOOLS_H

typedef struct
{
    int test_list;
    int test_solver;
    int run_main;
} ProgramParams;

/*! Clears input buffer
*/
int ClearInput(void);

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
* returns true if absolute value of num is smaller then EPSILON
*/
int CloseToZero(double);

/*! @brief Process double for printing
*
* @param[in] num Pointer to the processed double
*
* Round num to zero if it is negligibly small
*/
void PolishOutput(double*);

#endif
