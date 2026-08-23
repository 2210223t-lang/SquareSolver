#ifndef TRIAL_TOOLS_H
#define TRIAL_TOOLS_H

enum Modes{ TERMINAL_INPUT_ERROR = -1, AUTO_TEST = 0, MANUAL_TEST = 1, USER_MODE = 2 };
enum RootAmount{ INFINITY_ROOTS = -1, NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2 };

double RandDouble( void );
bool EqualsDouble( double a, double b );
void SwapDouble( double* a, double* b );


struct Equation
{
    double a, b, c;
    double x1, x2;
};

#endif //TRIAL_TOOLS_H
