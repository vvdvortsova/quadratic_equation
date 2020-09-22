/**
* @file         equation_lib.c
* @brief        describes methods for solver of quadratic equation
* @author       Dvortsova Varvara BSE182 HSE
* @include      equation_lib.h
*/
#include <spandsp.h>
#include "equation_lib.h"

/**
 * Macros     Define SWAP function
 * @param[in] item1
 * @param[in] item2
 * */
#define SWAP(item1, item2){\
        int temp = *(item1);\
        *item1 = *item2;\
        *item2 = temp;\
}

/**
* @brief      Compare a double variable with zero
* @param[in]  a  double variable
* @return     0 if a == 0 else 1
*/
static bool isZero(double a){
    return fabs(a) < EQUATION_EPS;
}

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
int findRootsInQuadraticEquation(double a, double b, double c, double *x1, double *x2){

    //normalize
    if(!isnan(b/a) && !isnan(c/a) && !isinf(b/a) && !isinf(c/a) ){
        b = b/a;
        c = c/a;
        a = 1;
    }
    if(!isfinite(a) || !isfinite(b) || !isfinite(c)){
        return EQUATION_ERROR;
    }

    if(isZero(a) && isZero(b) && isZero(c)){
        //infinity number of roots
        *x1 = INF_OF_ROOTS; *x2 = INF_OF_ROOTS;
        return -1;
    }

    assert(&x1 != &x2);
    assert(x1);
    assert(x2);

    if(isZero(a)){
        return findRootsInLinerEquation(b, c, x1);
    }

    const double D = (b * b - 4 * a * c);
    if(!isfinite(D)){
        return EQUATION_ERROR;
    }
    if (D > 0){ //D > 0
        *x1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        *x2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if (a < 0)
            SWAP(x1, x2);
        return 2;
    } else if (isZero(D)){ //D == 0
        *x1 = *x2  = -b / (2 * a);
        return 1;
    }
    // D < 0
    *x1 = IS_NO_ROOT;
    *x2 = IS_NO_ROOT;
    return 0;//no roots
}

/**
* @brief       Find roots in liner equation
* @details     Liner equation is a*x + b == 0
* @param[in]   a  The first param in equation
* @param[in]   b  The second param in equation
* @param[out]  x root of this equation
* @return      the number of roots in equation. 0, 1, 2 roots or INF_OF_ROOTS
 */
int findRootsInLinerEquation(double a, double b, double *x){
    assert(isfinite(a));
    assert(isfinite(b));

    if(isZero(a)){
        if(isZero(b)) return INF_OF_ROOTS;
        return 0;
    }

    *x = -b/a;
    if(!isfinite(*x)){
        return EQUATION_ERROR;
    }
    return 1;
}
