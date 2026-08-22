#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "FuncSolver.h"
#include "CorrectIO.h"

void SquareEquationSolver( FILE* IStream, int mode ) {
    assert( IStream );

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    int RootCount = 0;
    bool KeepGoing = false;

    if ( mode == 2 ) {

        KeepGoing = Input( IStream, &a, &b, &c );

        if ( KeepGoing == true ) {

            RootCount = SquareSl( a, b, c, &x1, &x2 );

            Output( &x1, &x2, &RootCount );

        }

    }


}
