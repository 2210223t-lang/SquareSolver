#ifndef TRIAL_TOOLS_H
#define TRIAL_TOOLS_H

/**
 * @brief Different modes' flags
 */
enum Modes
{
    TERMINAL_INPUT_ERROR = -1, ///< Terminal error flag
    AUTO_TEST = 0,             ///< Auto test flag
    MANUAL_TEST = 1,           ///< Manual test mode
    USER_MODE = 2,             ///< User mode
    AI_MODE = 3                ///< AI mode
};

/**
 * @brief Root amount flags
 */
enum RootAmount
{
    INFINITY_ROOTS = -1, ///< INF roots
    NO_ROOTS = 0,        ///<   0 roots
    ONE_ROOT = 1,        ///<   1 root
    TWO_ROOTS = 2        ///<   2 roots
};

/**
 * @brief Checks either a == b or not, not finite doubles can be compared too
 *
 * @return True if a == b and False if a != b
 */
bool EqualsDouble( double a, double b );

/**
 * @brief Swaps values of 2 double variables
 */
void SwapDouble( double* a, double* b );

/**
 * @brief Custom func to check if a is NAN or not
 *
 * @return True if a == NAN and False if a != NAN
 */
int isnanUt( double a );

#endif //TRIAL_TOOLS_H
