/**
* @file         equation_lib.h
* @brief        methods for solver of quadratic equation
* @author       Dvortsova Varvara BSE182 HSE
* @include      assert.h, math.h
*/

#ifndef QUADRATIC_EQUATION_EQUATION_LIB_H
#define QUADRATIC_EQUATION_EQUATION_LIB_H

#include <assert.h>
#include <math.h>
#include <float.h>

#define INF_OF_ROOTS DBL_MAX/**< const for the definition of the endless set of roots*/
#define EQUATION_EPS 1e-9/**< constant for comparing a double number with zero*/
#define IS_NO_ROOT -1/**< const for the definition of the lack of root in equation */
#define EQUATION_ERROR -42/**< const for the definition of the overflow */



/**
* @brief       Find roots in liner equation
* @details     Liner equation is a*x + b == 0
* @param[in]   a  The first param in equation
* @param[in]   b  The second param in equation
* @param[out]  x root of this equation
* @return      the number of roots in equation. 0, 1, 2 roots or INF_OF_ROOTS
 */
int findRootsInLinerEquation(double a, double b, double *x);

/**
* @brief        Find roots in quadratic equation
* @details      Quadratic equation is a*x^2 + b*x + c = 0
* @param[in]    a  The first param in equation
* @param[in]    b  The second param in equation
* @param[in]    c  The third param in equation
* @param[out]   x1 The first root
* @param[out]   x2 The second root
* @return       the number of roots in equation. 0, 1, 2 roots or INF_OF_ROOTS
 */
int findRootsInQuadraticEquation(double a, double d, double c, double *x1, double *x2);

#endif //QUADRATIC_EQUATION_EQUATION_LIB_H
