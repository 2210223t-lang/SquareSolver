#include <math.h>
#include <assert.h>

#include "../header/Tools.h"


int LinearSl( double b, double c, double* x1 ) {
    assert( x1 );

    if ( !EqualsDouble( b, 0 ) ) {

        *x1 = -c / b;
        return ONE_ROOT;

    }
    else {
        if ( EqualsDouble( c, 0 ) ) {

            return INFINITY_ROOTS;

        }
        else {

            return NO_ROOTS;

        }
    }
}


int SquareSl( double a, double b, double c, double* x1, double* x2 ) {
    assert( x1 );
    assert( x2 );

    *x1 = NAN;
    *x2 = NAN;

    double DisSqr = b * b - 4 * a * c;

    if ( DisSqr < 0 ) {

        return NO_ROOTS;

    }
    else if ( EqualsDouble( a, 0 ) ) {

        return LinearSl( b, c, x1 );

    }
    else {

      double Dis = sqrt( DisSqr );

        if ( EqualsDouble( DisSqr, 0 ) ) {

            *x1 = ( -b + Dis ) / ( 2 * a );
            return ONE_ROOT;

        }
        else {

            *x1 = ( -b - Dis ) / ( 2 * a );
            *x2 = ( -b + Dis ) / ( 2 * a );
            if ( *x1 > *x2 ) SwapDouble( x1, x2 );
            return TWO_ROOTS;

        }
    }
}
