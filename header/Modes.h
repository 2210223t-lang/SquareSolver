#ifndef TRIAL_SQUARECALC_H
#define TRIAL_SQUARECALC_H
#include <stdio.h>

/**
 * @brief Starting common mode for user
 *
 * @param InputStream Is a stream where from function will take data for it's work( coefficients )
 *
 * @details Starting a user mode, where program ask user to input every variable with sentences,
 *          also prints amount of roots and roots themselves
 */
int UserCalc( FILE* InputStream );

/**
 * @brief Enables mode, which test program with presaved in code tests
 *
 * @return Amount of mistakes in passed tests and their parameters
 */
int AutoTest( void );

/**
 * @brief Starting Manual test mode
 *
 * @param InputStream Is a stream where from it will take keys and coefficients for tests
 *
 * @details It's designed from taking variables either from .txt file, either from terminal
 *          Expected order of input: a b c x1 x2 RootAmount
 *
 * @warning This mode displays only mistakes, correct tests it ignores and user can't see their data
 *
 * @return Amount of mistakes in passed tests
 */
int ManualTest( FILE* InputStream);

#endif //TRIAL_SQUARECALC_H
