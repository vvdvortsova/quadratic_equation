/**
* @file         test_lib.h
* @brief        Describes methods for testing of equation_lib.h
* @author       Dvortsova Varvara BSE182 HSE
* @include      equation_lib.h, stdio.h
*/

#ifndef QUADRATIC_EQUATION_TEST_LIB_H
#define QUADRATIC_EQUATION_TEST_LIB_H

#include "../src/equation_lib.h"
#include <stdio.h>


/**
 * Macros define custom assert function for unit testing
 * @param nameOfMethod Describe the name Of method where assertTestINT was called
 * @param code Actual value
 * @param expected Expected value
 * */
#define assertTestINT( nameOfMethod,code, expected )\
    if((code) == (expected)){\
        printf("[TEST] [ %s ] [PASSED] (%s:%d)\n",
                nameOfMethod, __FILE__, __LINE__);\
    }else{\
        fprintf(stderr, "[TEST] [ %s ] [FAILED] (%s:%d) \n",
                nameOfMethod,__FILE__, __LINE__);\
        fprintf(stderr, "[TEST] expected = %d code = %d \n",
                expected, code);\
    }
/**
 * Macros define custom assert function for unit testing with double params
 * @param nameOfMethod Describe the name Of method where assertTestINT was called
 * @param code Actual value
 * @param expected Expected value
 * */
#define assertTestDouble( nameOfMethod, code, expected)\
    if(fabs(code - expected) < EQUATION_EPS){\
        printf("[TEST] [ %s ] [PASSED] (%s:%d)\n",
                nameOfMethod, __FILE__, __LINE__);\
    }else{\
        fprintf(stderr, "[TEST] [ %s ] [FAILED] (%s:%d) \n",
                nameOfMethod,__FILE__, __LINE__);\
        fprintf(stderr, "[TEST] expected = %lg code = %lg \n",
                expected, code);\
    }


void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void test11();
void test12();


void test1(){
    double a = 1, b = 1, c = 1;
    double x1 = 0, x2 = 0;
    assertTestINT("test1", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 0)
}
void test2(){
    double a = 1, b = -2, c = -3;
    double x1 = 0, x2 = 0;
    int roots = findRootsInQuadraticEquation(a, b, c, &x1, &x2);
    assertTestINT("test2", roots, 2)
    assertTestDouble("test2", x1, 3.0)
    assertTestDouble("test2", x2, -1.0)
}

void test3(){
    double a = -1, b = -2, c = 15;
    double x1 = 0, x2 = 0;
    assertTestINT("test3", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 2)
    assertTestDouble("test3", x1, 3.0)
    assertTestDouble("test3", x2, -5.0)
}

void test4(){
    double a = 1, b = 12, c = 36;
    double x1 = 0, x2 = 0;
    assertTestINT("test4", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 1)
    assertTestDouble("test4", x1, -6.0)
    assertTestDouble("test4", x2, -6.0)
}

void test5(){
    double a = 1, b = -7, c = 0;
    double x1 = 0, x2 = 0;
    assertTestINT("test5", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 2)
    assertTestDouble("test5", x1, 7.0)
    assertTestDouble("test5", x2, 0.0)
}

void test6(){
    double a = 5, b = 0, c = 30;
    double x1 = 0, x2 = 0;
    assertTestINT("test6", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 0)
}

void test7(){
    double a = 4, b = 0, c = -9;
    double x1 = 0, x2 = 0;
    assertTestINT("test7", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 2);
    assertTestDouble("test7", x1, 1.5);
    assertTestDouble("test7", x2, -1.5);
}

void test8(){
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    assertTestINT("test8", findRootsInQuadraticEquation(a, b, c, &x1, &x2), -1);
    assertTestDouble("test8", x1, INF_OF_ROOTS);
    assertTestDouble("test8", x2, INF_OF_ROOTS);
}

void test9(){
    //test with overflow
    double a = 1.79769e+308, b = 1.79769e+308, c = 1.79769e+308;
    double x1 = 0, x2 = 0;
    assertTestINT("test9", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 0);
    assertTestDouble("test9", x1, IS_NO_ROOT);
    assertTestDouble("test9", x2, IS_NO_ROOT);
}
//check liner
void test10(){
    double a = 0, b = 3, c = 15;
    double x1 = 0, x2 = 0;
    assertTestINT("test10", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 1);
    assertTestDouble("test10", x1, -5.0);
}
//check liner
void test11(){
    double a = 0, b = 1, c = 0;
    double x1 = 0, x2 = 0;
    assertTestINT("test11", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 1);
    assertTestDouble("test11", x1, 0);
}
//check liner
void test12(){
    double a = 0, b = 3, c = -9;
    double x1 = 0, x2 = 0;
    assertTestINT("test12", findRootsInQuadraticEquation(a, b, c, &x1, &x2), 1);
    assertTestDouble("test12", x1, 3);
}
#endif //QUADRATIC_EQUATION_TEST_LIB_H

