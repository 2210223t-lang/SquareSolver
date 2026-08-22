#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "FuncSolver.h"
#include "UserIO.h"
#include "Tools.h"


struct TestingSet {

    double a;
    double b;
    double c;
    double x1exp;
    double x2exp;
    int RootAmountexp;

};


void UserCalc( FILE* IStream) {
    assert( IStream );

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    int RootCount = 0;
    bool KeepGoing = false;
    char Repeat = 'y';

    while ( Repeat == 'y' ) {
        KeepGoing = UserInput( IStream, &a, &b, &c );

        if ( KeepGoing == true ) {
            RootCount = SquareSl( a, b, c, &x1, &x2 );
            Output( &x1, &x2, &RootCount );

        }

        printf( "Do you want to calculate again?\n(" GRN "y" reset "/" RED "n" reset ")\n" );
        scanf( "%c", &Repeat );
    }

}

int AutoTest(){
    struct TestingSet TestData[] = { {  1.0,  2.0,   1.0,       -1.0,       NAN,       ONE_ROOT },
                                     {  2.0,  2.0,   2.0,        NAN,       NAN,       NO_ROOTS },
                                     {  0.0,  0.0,   0.0,        NAN,       NAN, INFINITY_ROOTS },
                                     { -1.0, 12.0, -32.0,        4.0,       8.0,      TWO_ROOTS },
                                     {  1.0, -5.0,   6.0,        2.0,       3.0,      TWO_ROOTS },
                                     {  1.0, -4.0,   4.0,        2.0,       NAN,       ONE_ROOT },
                                     {  1.0,  0.0,  -9.0, -sqrt( 9 ), sqrt( 9 ),      TWO_ROOTS },
                                     {  1.0,  4.0,   0.0,       -4.0,       0.0,      TWO_ROOTS },
                                     {  0.0,  3.0,  -6.0,        2.0,       NAN,       ONE_ROOT } };
    int TestAmount = sizeof( TestData ) / ( sizeof( TestingSet ) );

    int MistakeCount = 0;
    double x1 = NAN, x2 = NAN;
    int RootAmount = NO_ROOTS;

    for ( int i = 0; i < TestAmount; i++) {

        RootAmount = SquareSl( TestData[ i ].a, TestData[ i ].b, TestData[ i ].c, &x1, &x2 );

        if ( !EqualsDouble( TestData[ i ].x1exp, x1 ) || !EqualsDouble( TestData[ i ].x2exp, x2 ) ||
             ( TestData[ i ].RootAmountexp != RootAmount ) ) {

            printf( RED "ERROR: %d test: a = %lf, b = %lf, c = %lf\n"
                        "Expected: x1 = %lf, x2 = %lf, RootAmount = %d\n"
                        "Result:   x1 = %lf, x2 = %lf, RootAmount = %d\n" reset,
                        i + 1, TestData[ i ].a, TestData[ i ].b, TestData[ i ].c, TestData[ i ].x1exp,
                        TestData[ i ].x1exp, TestData[ i ].RootAmountexp, x1, x2, RootAmount );

            MistakeCount++;
        }
    }
return MistakeCount;
}

