#ifndef TRIAL_COTEXIO_H
#define TRIAL_COTEXIO_H

/**
 * @brief Starts variables' input in AI mode
 *
 * @param[ out ] Equ struct Equation* Equ pointer to a variable ,where coefficients will be stored
 */
void COTexInput( struct Equation* Equ);

/**
 * @brief Prints roots that programm calculated
 *
 * @param[ out ] CompiledRoots struct Keys CompiledRoots structure with answers
 */
void COTexOutput( struct Keys CompiledRoots );

/**
 * @brief Starts calculating roots wit AI assistant
 *
 * @return 0 if user answered incorrect on ask for continuation of work and 1 if code exited successfully
 */
void COTexEquation( void );

#endif // TRIAL_COTEXIO_H
