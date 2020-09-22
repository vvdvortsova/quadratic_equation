/**
* @file         solver_quadratic_equation.c
* @brief        solver of quadratic equation
* @detail       this is a solver of quadratic_equation
* @author       Dvortsova Varvara BSE182 HSE
* @include      string.h, assert.h, math.h, equation.h
*/
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "equation_lib.h"

void outputResFromQuadraticEquation(int roots, double x1, double x2);
double getDoubleFromInput(char message[]);

int main(){

    double a = NAN, b = NAN, c = NAN;

    a = getDoubleFromInput("Enter the first param = ");
    b = getDoubleFromInput("Enter the second param = ");
    c = getDoubleFromInput("Enter the third param = ");

    assert(&a);
    assert(&b);
    assert(&c);

    if(!isfinite(a) || !isfinite(b) || !isfinite(c)){
       printf("Values overflows!, please try again\n");
    }

    assert((&a != &b) && (&a != &c) && (&b != &c));


    printf("\na = %lg b = %lg c = %lg\n", a, b, c);
    double x1 = NAN, x2 = NAN;
    int countOfRoots = findRootsInQuadraticEquation(a, b, c, &x1, &x2);
    outputResFromQuadraticEquation(countOfRoots, x1, x2);

    return 0;
}

/**
* @brief             Output results of quadratic equation
* @param[in]  roots  The count of roots in quadratic equation
* @param[in]  x1     First root
* @param[in]  x2     Second root
*/
void outputResFromQuadraticEquation(int roots, double x1, double x2){
    switch (roots){
        case 0:
            printf("roots = 0 \n");
            break;
        case 1:
            printf("roots = %d x1 = %lg \n", roots, x1);
            break;
        case 2:
            printf("roots = %d x1 = %lg x2 = %lg\n", roots, x1, x2);
            break;
        case -1:
            printf("Infinite number of roots\n");
            break;
        default:
            printf("Discriminant of quadratic equation overflows\n");
            break;
    }
}

/**
* @brief                 Get double values from input stream for quadratic equation
* @param[in]  message[]  The message for user
* @return     number     double value
*/
double getDoubleFromInput(char message[]){
    double number;
    printf("%s", message);
    int correctInput = scanf("%lg", &number);
    while(correctInput != 1){
        while (getchar() != EOF && getchar() != '\n' && getchar() != '\0');
        printf("Wrong input,try again\n%s", message);
        correctInput = scanf("%lg", &number);
    }
    return number;
}
