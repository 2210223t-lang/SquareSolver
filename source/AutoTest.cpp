#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "../header/Structures.h"
#include "../header/Tools.h"
#include "../header/ModeUtility.h"

void AutoTest( void )
{
    struct Equation TestPreset[] = { { .a =  1.0, .b =  2.0, .c =   1.0 },
                                     { .a =  2.0, .b =  2.0, .c =   2.0 },
                                     { .a =  0.0, .b =  0.0, .c =   0.0 },
                                     { .a = -1.0, .b = 12.0, .c = -32.0 },
                                     { .a =  1.0, .b = -5.0, .c =   6.0 },
                                     { .a =  1.0, .b = -4.0, .c =   4.0 },
                                     { .a =  1.0, .b =  0.0, .c =  -9.0 },
                                     { .a =  1.0, .b =  4.0, .c =   0.0 },
                                     { .a =  0.0, .b =  3.0, .c =  -6.0 },
                                     { .a =  1.0, .b =  0.0, .c =  -1.0 } };

    struct Keys Answers[] = { { .x1 = -1.0, .x2 = NAN, .RootAmount =       ONE_ROOT },
                              { .x1 =  NAN, .x2 = NAN, .RootAmount =       NO_ROOTS },
                              { .x1 =  NAN, .x2 = NAN, .RootAmount = INFINITY_ROOTS },
                              { .x1 =  4.0, .x2 = 8.0, .RootAmount =      TWO_ROOTS },
                              { .x1 =  2.0, .x2 = 3.0, .RootAmount =      TWO_ROOTS },
                              { .x1 =  2.0, .x2 = NAN, .RootAmount =       ONE_ROOT },
                              { .x1 = -3.0, .x2 = 3.0, .RootAmount =      TWO_ROOTS },
                              { .x1 = -4.0, .x2 = 0.0, .RootAmount =      TWO_ROOTS },
                              { .x1 =  2.0, .x2 = NAN, .RootAmount =       ONE_ROOT },
                              { .x1 = -1.0, .x2 = 1.0, .RootAmount =      TWO_ROOTS } };


    int TestAmount = sizeof( TestPreset ) / sizeof( Equation );
    int MistakesCount = 0;

    for ( int i = 0; i < TestAmount; i++ )
    {
        MistakesCount += CheckAnswer( &TestPreset[ i ], &Answers[ i ] );
    }
    printf( "Tests ended with %d mistakes", MistakesCount );
}
