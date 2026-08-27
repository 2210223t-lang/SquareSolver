#ifndef TRIAL_INITIALIZE_H
#define TRIAL_INITIALIZE_H
#include <stdio.h>
#include "../header/Structures.h"

/**
 * @brief Func which ask user to input Equation's coefficients
 *
 * @param InputStream is a stream, where from it will take values
 *
 * @param Equ is a pointer to a struct Equation, where we will store coefficients
 *
 */
bool UserInput( FILE* InputStream, struct Equation* Equ );

/**
 * @brief Prints answers for an equation
 *
 * @param CompiledRoots is a struct Keys, where from it takes values for output
 */
void Output( struct Keys* CompiledRoots );

#endif //TRIAL_INITIALIZE_H
