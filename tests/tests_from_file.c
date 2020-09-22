/**
* @file         tests_from_file.c
* @brief        Launch all tests from file_tests.txt
* @author       Dvortsova Varvara BSE182 HSE
* @include     test_lib.h stdlib.h stdio.h string.h
*/
#include <stdio.h>
#include <stdlib.h>
#include "test_lib.h"
#include <string.h>


void doTest(char* nameOftest, double aTest, double bTest, double cTest, double rootsTest, double x1Test, double x2Test);
const int SIZE = 20;/**< Define size of char array */


int main(){

    FILE * file;
    char * line = "";
    size_t len = 0;

    // line of file: aTest bTest cTest rootsTest x1Test x2Test
    file = fopen("../tests/file_tests.txt", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);

    double aTest = 0, bTest = 0, cTest = 0, rootsTest = 0, x1Test = 0, x2Test =0;
    unsigned int countOfLinesInFile = 0;
    char nameOftest[SIZE];

    while (getline(&line, &len, file) != -1){
        //fool check
        if(sscanf(line, "%lg %lg %lg %lg %lg %lg", &aTest, &bTest, &cTest, &rootsTest, &x1Test,&x2Test) != 6){
            printf("\nSorry, the file cannot be read");
            break;
        };//read from line of file
        
        printf("%lg %lg %lg %lg %lg %lg\n", aTest, bTest, cTest, rootsTest, x1Test,x2Test);
        sprintf(nameOftest, "%s%d", nameOftest, countOfLinesInFile);//writes number of line in nameOftest

        doTest(nameOftest, aTest, bTest, cTest, rootsTest, x1Test, x2Test);

        countOfLinesInFile += 1;
        memset(nameOftest, 0, sizeof nameOftest);// makes string empty
    }

    fclose(file);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

/**
* @brief           Run test
* @details         Quadratic equation is a*x^2 + b*x + c = 0
* @param aTest     The first param in equation
* @param bTest     The second param in equation
* @param cTest     The third param in equation
* @param rootsTest The count of roots in quadratic equation
* @param x1Test    First root
* @param x2Test    Second root
*/
void doTest(char* nameOftest, double aTest, double bTest, double cTest, double rootsTest, double x1Test, double x2Test) {

    double a = aTest, b = bTest, c = cTest;
    double x1 = 0, x2 = 0;
    int roots = findRootsInQuadraticEquation(a, b, c, &x1, &x2);
    findRootsInQuadraticEquation(a, b, c, &x1, &x2);

    assertTestINT(nameOftest, roots, rootsTest)
    if(roots != -1){// if roots != DBL_MAX
        assertTestDouble(nameOftest, x1, x1Test)
        assertTestDouble(nameOftest, x2, x2Test)
    }
}

