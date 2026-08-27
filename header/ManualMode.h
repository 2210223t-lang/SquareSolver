#ifndef TRIAL_MANUALMODE_H
#define TRIAL_MANUALMODE_H

#include <stdio.h>


/**
 * @brief Starting Manual test mode
 *
 * @param COTexoptarg char* COTexoptart contains name of file, that needs to be open, otherwise NULL
 *
 * @details It's designed from taking variables either from .txt file, either from terminal
 *          Expected order of input: a b c x1 x2 RootAmount
 *
 * @warning This mode displays only mistakes, correct tests it ignores and user can't see their data
 *
 * @return Amount of mistakes in passed tests
 */
void StartManualTest( char* COTexoptarg );

#endif // TRIAL_MANUALMODE_H
