#ifndef TRIAL_STRUCTURES_H
#define TRIAL_STRUCTURES_H

/**
 * @brief Stores Equation coefficents
 */
struct Equation
{
    double a; ///< Quadratic coefficient
    double b; ///< Linear coefficient
    double c; ///< constant term
};

/**
 * @brief Stores keys for some equation
 *
 * @warning If equation has one root, than x1 store it's value, while x2 NAN.
 *          If equation has 0 roots, both x1 and x2 store NAN.
 */
struct Keys
{
    double x1; ///< First coefficient
    double x2; ///< Second coefficient
    int RootAmount; ///< Amount of real roots
};

#endif // TRIAL_STRUCTURES_H
