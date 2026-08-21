#include <math.h>
#include <assert.h>

enum RootAmount{ InfinityRoots = -1, NoRoots = 0, OneRoot = 1, TwoRoots = 2 };

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
        return 1;
    }
    else {
        if ( Equals( c, 0 ) ) {
            return InfinityRoots;
        }
        else {
            return NoRoots;
        }
    }
}


int SquareSl( double a, double b, double c, double* x1, double* x2 ) {
    assert( x1 );
    assert( x2 );

    double DisSqr = b * b - 4 * a * c;

    if ( DisSqr < 0 ) {
        return NoRoots;
    }
    else if ( Equals( a, 0 ) ) {
        return LinearSl( b, c, x1 );
    }
    else {
      double Dis = sqrt( DisSqr );

        if ( Equals( DisSqr, 0 ) ) {
            *x1 = ( -b + Dis ) / ( 2 * a );
            return OneRoot;
        }
        else {
            *x1 = ( -b + Dis ) / ( 2 * a );
            *x2 = ( -b - Dis ) / ( 2 * a );
            return TwoRoots;
        }
    }
}
