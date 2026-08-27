#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


bool EqualsDouble( double a, double b )
{
    const double eps = 1e-6;

    if ( ( isnan( a ) && isnan( b ) ) ||
         ( isinf( a ) && isinf( b ) ) ||
         ( fabs( a - b ) <= eps ) )
        return true;

    return false;
}

void SwapDouble( double* a, double* b )
{
    assert( a );
    assert( b );

    double c = *a;
    *a = *b;
    *b = c;

}

bool isnanUt( double a )
{
    return !( a * INFINITY == INFINITY );
}
