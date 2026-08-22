#include <stdlib.h>
#include <math.h>


double RandDouble( void ) {

    int x = rand() - RAND_MAX, y = rand() - RAND_MAX;
    double Random = 0.0;

    while ( isnan( Random = (double) x / y ) || isinf( Random ) );

    return Random;
}

bool EqualsDouble( double a, double b ) {

    const double eps = 1e-7;

    if ( isnan( a ) && isnan( b ) ) return true;

    if ( fabs( a-b ) <= eps ) {

        return true;

    }
    return false;

}

void SwapDouble( double* a, double* b ) {

    double c = *a;
    *a = *b;
    *b = c;

}

