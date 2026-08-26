#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include "../header/SquareSolver.h"
#include "../header/UserIO.h"
#include "../header/Tools.h"
#include "../header/Colours.h"
#include "../header/Structures.h"


int GetEquation( struct Equation* Equation, FILE* InputStream )
{
    assert( Equation );
    assert( InputStream );

    if ( fscanf( InputStream, "%lf", &( Equation->a ) ) == EOF ||
         fscanf( InputStream, "%lf", &( Equation->b ) ) == EOF ||
         fscanf( InputStream, "%lf", &( Equation->c ) ) == EOF )
    {
        return EOF;
    }

    return 0;
}

int GetKeys( struct Keys* Ans, FILE* InputStream )
{
    assert( Ans );
    assert( InputStream );

    if ( fscanf( InputStream, "%lf", &(     Ans->x1     ) ) == EOF ||
         fscanf( InputStream, "%lf", &(     Ans->x2     ) ) == EOF ||
         fscanf( InputStream, "%d",  &( Ans->RootAmount ) ) == EOF )
    {
        return EOF;
    }

    return 0;
}


int CheckAnswer ( struct Equation Test, struct Keys Answers )
{
    struct Keys CompiledRoots = { .x1 = NAN, .x2 = NAN };

    CompiledRoots.RootAmount = SquareSolve( Test, &CompiledRoots );

    if ( !EqualsDouble( Answers.x1, CompiledRoots.x1 ) ||
         !EqualsDouble( Answers.x2, CompiledRoots.x2 ) ||
         !( Answers.RootAmount == CompiledRoots.RootAmount ) )
    {
        printf( RED "ERROR: a = %lf, b = %lf, c = %lf\n"
                    "Expected: x1 = %lf, x2 = %lf, RootAmount = %d\n"
                    "Result:   x1 = %lf, x2 = %lf, RootAmount = %d\n" reset,
                    Test.a, Test.b, Test.c, Answers.x1, Answers.x2,
                    Answers.RootAmount, CompiledRoots.x1, CompiledRoots.x2, CompiledRoots.RootAmount );
        return 1;
    }

    return 0;
}

void UserCalc( FILE* InputStream)
{
    assert( InputStream );

    struct Equation Equ = { .a = NAN, .b = NAN, .c = NAN };
    struct Keys CompiledRoots = { .x1 = NAN, .x2 = NAN };
    bool KeepGoing = false;
    char Repeat = 'y';

    while ( tolower( Repeat ) == 'y' )
    {
        KeepGoing = UserInput( InputStream, &Equ );

        if ( KeepGoing == true )
        {
            CompiledRoots.RootAmount = SquareSolve( Equ, &CompiledRoots );
            Output( CompiledRoots );
        }

        printf( "Do you want to calculate again?\n(" GRN "y" reset "/" RED "n" reset ")\n" );
        scanf( "%c", &Repeat );
    }

}

int ManualTest ( FILE* InputStream )
{
    assert( InputStream );

    int MistakesCount = 0;
    struct Equation Preset = { .a = NAN, .b = NAN, .c = NAN };
    struct Keys Answers = { .x1 = NAN, .x2 = NAN };

    while ( GetEquation( &Preset, InputStream ) != EOF && GetKeys( &Answers, InputStream ) != EOF )
    {
        MistakesCount += CheckAnswer( Preset, Answers );
    }

    return MistakesCount;
}

int AutoTest( void )
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
        MistakesCount += CheckAnswer( TestPreset[ i ], Answers[ i ] );
    }
    return MistakesCount;
}
