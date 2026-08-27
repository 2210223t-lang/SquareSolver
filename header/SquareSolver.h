#ifndef TRIAL_EQUATIONS_H
#define TRIAL_EQUATIONS_H

/**
 * @brief Solves square equation
 *
 * @param Equ is a struct Equation with equation's coefficients
 *
 * @param CompiledRoots is a pointer to a struct Keys where we will store roots and RootAmount,
 *                      which func will find
 *
 * @return if   0 roots =  0
 *         if   1 root  =  1
 *         if   2 roots =  2
 *         if INF roots = -1
 */
int SquareSolve( struct Equation* Equ, struct Keys* CompiledRoots );

/**
 * @brief Solves linear equation
 *
 * @param b is a linear koefficent
 *
 * @param c is a constant term
 *
 * @param x1 is a pointer to a root variable, where root will be stored
 *
 * @details Initializes *x1 with NAN if there is 0 or INF roots
 *
 * @return if 1 root = 1
 *         if 0 roots = 0
 *         if INF roots = -1
 */
int LinearSolve( double b, double c, double* x1 );

#endif //TRIAL_EQUATIONS_H
