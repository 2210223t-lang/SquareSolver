#ifndef TRIAL_TOOLS_H
#define TRIAL_TOOLS_H

enum Modes{ TERMINAL_INPUT_ERROR = -1, AUTO_TEST = 0, MANUAL_TEST = 1, USER_MODE = 2 };
enum RootAmount{ INFINITY_ROOTS = -1, NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2 };

double RandDouble( void );
bool EqualsDouble( double a, double b );
void SwapDouble( double* a, double* b );

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"

#endif //TRIAL_TOOLS_H
