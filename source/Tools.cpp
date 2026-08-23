#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double RandDouble( void )
{
    int x = rand() - RAND_MAX, y = rand() - RAND_MAX;
    double Random = 0.0;

    while ( isnan( Random = (double) x / y ) || isinf( Random ) );

    return Random;
}

bool EqualsDouble( double a, double b )
{
    const double eps = 1e-6;

    if ( isnan( a ) && isnan( b ) ) return true;

    if ( fabs( a - b ) <= eps )
    {
        return true;
    }

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

int isnanUt( double a )
{
    return !( a * INFINITY == INFINITY );
}
