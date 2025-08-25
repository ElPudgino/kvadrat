#ifndef TESTS_H
#define TESTS_H


typedef struct
{
    double a, b, c;
    double x1_res, x2_res;
    int nRoots_res;
} TestParams;

/*! @brief Tests quadratic solver using predefined values
* @return 1 if all tests are OK 0 otherwise
*/
int TestQuadraticSolver();

/*! @brief Runs a single solver test
*
* @param[in] tps Predefined test parameters
* @param[in] res Referenced int is set to 0 if test fails
*/
void TestSolverSingle(TestParams tps, int* res);


#endif
