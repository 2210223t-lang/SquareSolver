#include <math.h>
#include <assert.h>

enum RootAmount{ INFINITY_ROOTS = -1, NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2 };

bool Equals( double a, double b ){
    const double eps = 1e-7;

    if ( fabs( a-b ) <= eps ) {
        return true;
    }
    return false;
}

int LinearSl( double b, double c, double* x1 ) {
    assert( x1 );

    if ( !Equals( b, 0 ) ) {
        *x1 = -c / b;
        return ONE_ROOT;
    }
    else {
        if ( Equals( c, 0 ) ) {
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

    double DisSqr = b * b - 4 * a * c;

    if ( DisSqr < 0 ) {
        return NO_ROOTS;
    }
    else if ( Equals( a, 0 ) ) {
        return LinearSl( b, c, x1 );
    }
    else {
      double Dis = sqrt( DisSqr );

        if ( Equals( DisSqr, 0 ) ) {
            *x1 = ( -b + Dis ) / ( 2 * a );
            return ONE_ROOT;
        }
        else {
            *x1 = ( -b - Dis ) / ( 2 * a );
            *x2 = ( -b + Dis ) / ( 2 * a );
            return TWO_ROOTS;
        }
    }
}
