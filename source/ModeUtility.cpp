#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "../header/SquareSolver.h"
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

int CheckAnswer( struct Equation* Test, struct Keys* Answers )
{
    assert( Test );
    assert( Answers );

    struct Keys CompiledRoots = { .x1 = NAN, .x2 = NAN };

    CompiledRoots.RootAmount = SquareSolve( Test, &CompiledRoots );

    if ( !EqualsDouble( Answers->x1, CompiledRoots.x1 ) ||
         !EqualsDouble( Answers->x2, CompiledRoots.x2 ) ||
         !( Answers->RootAmount == CompiledRoots.RootAmount ) )
    {
        printf( RED "ERROR: a = %lf, b = %lf, c = %lf\n"
                    "Expected: x1 = %lf, x2 = %lf, RootAmount = %d\n"
                    "Result:   x1 = %lf, x2 = %lf, RootAmount = %d\n" reset,
                    Test->a, Test->b, Test->c, Answers->x1, Answers->x2,
                    Answers->RootAmount, CompiledRoots.x1, CompiledRoots.x2, CompiledRoots.RootAmount );
        return 1;
    }

    return 0;
}
