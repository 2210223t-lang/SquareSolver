#ifndef TRIAL_INITIALIZE_H
#define TRIAL_INITIALIZE_H
#include <stdio.h>
#include "../header/Structures.h"

bool UserInput( FILE* IStream, struct Equation* Equ );

void Output( struct Keys CompiledRoots );

#endif //TRIAL_INITIALIZE_H
