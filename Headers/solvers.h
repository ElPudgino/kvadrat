#ifndef SOLVERS_H
#define SOLVERS_H

/** @brief Solves quadratic equations
*
* @param[in] a Coefficient of x^2
* @param[in] b Coefficient of x
* @param[in] c Constant term
* @param[out] x1 First root
* @param[out] x2 Second root
*
* If a = 0 solves a linear equation
*
* Can have 0, 1, 2 or Inf roots
*
* If equation has no roots or has infinite x1 and x2 are not changed
* If equation has one root x1 = x2
*/
int SolveQuadratic(double a, double b, double c,
                   double* x1, double* x2);

/** @brief Solves linear equation
*
* @param[in] a Coefficient of x
* @param[in] b Constant term
* @param[out] x Root
*
* Has 0, 1 or Inf roots
*
* If equation has no roots or has infinite x is not changed
*/
int SolveLinear(double a, double b, double* x);

enum RootsCount
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};

#endif
