#ifndef TRIAL_MODEUTILITY_H
#define TRIAL_MODEUTILITY_H

#include <stdio.h>

#include "../header/Colours.h"


/**
 * @brief Getting equation's coefficients
 *
 * @param Equation pointer to a struture where coefficients will be stored
 *
 * @param InputStream stream where from we take coefficients for initializing
 *
 * @warning This function is a part of the testing module and we count on correctness of input data, there are no checkings on input format
 * @return EOF if function read all available coefficients and 0 if it didn't
 */
int GetEquation( struct Equation* Equation, FILE* InputStream );

/**
 * @brief Getting correct answers for Equation preset
 *
 * @param Ans is a pointer to a structure where the answers will be stored
 *
 * @param InputStream is a stream where from we take answers to initialize
 *
 * @warning This function is a part of the testing module and we count on correctness of input data, there are no checkings on input format
 *
 * @return EOF if it reached the end of the input data and 0 if it didn't
 */
int GetKeys( struct Keys* Ans, FILE* InputStream );

/**
 * @brief Checking correct answers with the results of working SquareSolve function
 *
 * @param Test is a Equation structure with Equation coefficients
 *
 * @param Answers is a Keys structure with correct answers for Test Equation
 *
 * @details if it finds a mistakes in root's from SquareSolver function,
 *          it prints message with all parameters of this example.
 *          Return parameter is later used to calculate mistakes amount
 *
 * @return 1 if something went wrong and 0 if not
 */
int CheckAnswer ( struct Equation* Test, struct Keys* Answers );

#endif //TRIAL_MODEUTILITY_H
