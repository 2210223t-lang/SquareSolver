#ifndef TRIAL_USERMODE_H
#define TRIAL_USERMODE_H

#include <stdio.h>

/**
 * @brief Starting common mode for user
 *
 * @param InputStream Is a stream where from function will take data for it's work( coefficients )
 *
 * @details Starting a user mode, where program ask user to input every variable with sentences,
 *          also prints amount of roots and roots themselves
 */
void RunUserMode( char* COTexoptarg );

#endif //TRIAL_USERMODE_H
