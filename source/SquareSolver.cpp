#include <math.h>
#include <assert.h>

#include "../header/Tools.h"
#include "../header/Structures.h"


int LinearSolve( double b, double c, double* x1 )
{
    assert( x1 );

    if ( !EqualsDouble( b, 0 ) )
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
    else
    {

        if ( EqualsDouble( c, 0 ) )
        {
            return INFINITY_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }

    }
}

int SquareSolve( struct Equation* Equ, struct Keys* CompiledRoots )
{
    assert( CompiledRoots );
    assert( Equ );

    CompiledRoots->x1 = NAN;
    CompiledRoots->x2 = NAN;

    double Dis = Equ->b * Equ->b - 4 * Equ->a * Equ->c;

    if ( Dis < 0 )
    {
        return NO_ROOTS;
    }
    else if ( EqualsDouble( Equ->a, 0 ) )
    {
        return LinearSolve( Equ->b, Equ->c, &( CompiledRoots->x1 ) );
    }
    else
    {
      double DisSqrt = sqrt( Dis );

        if ( EqualsDouble( Dis, 0 ) )
        {
            CompiledRoots->x1 = ( -( Equ->b ) + DisSqrt ) / ( 2 * ( Equ->a ) );
            return ONE_ROOT;
        }
        else
        {
            CompiledRoots->x1 = ( -( Equ->b ) - DisSqrt ) / ( 2 * ( Equ->a ) );
            CompiledRoots->x2 = ( -( Equ->b ) + DisSqrt ) / ( 2 * ( Equ->a ) );
            if ( CompiledRoots->x1 > CompiledRoots->x2 ) SwapDouble( &( CompiledRoots->x1 ), &( CompiledRoots->x2 ) );
            return TWO_ROOTS;
        }

    }

}
