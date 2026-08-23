#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "../header/FuncSolver.h"
#include "../header/UserIO.h"
#include "../header/Tools.h"
#include "../header/Colours.h"


//TODO how to write isnan( double ) without working with bytes
struct Keys
{
    double x1exp, x2exp;
    int RootAmountexp;
};

int GetEquation( struct Equation* Equ, FILE* *InputStream )
{
    assert( Equ );
    assert( *InputStream );

    Equ->x1 = NAN;
    Equ->x2 = NAN;
//TODO fix logic
    if ( fscanf( *InputStream, "%lf", &( Equ->a ) ) == EOF ||
         fscanf( *InputStream, "%lf", &( Equ->b ) ) == EOF ||
         fscanf( *InputStream, "%lf", &( Equ->c ) ) == EOF )
    {
        return EOF;
    }

    return 0;
}

int GetAnswers( struct Keys* Ans, FILE* *InputStream )
{
    assert( Ans );
    assert( InputStream );

    if ( fscanf( *InputStream, "%lf", &(     Ans->x1exp     ) ) == EOF ||
         fscanf( *InputStream, "%lf", &(     Ans->x2exp     ) ) == EOF ||
         fscanf( *InputStream, "%d",  &( Ans->RootAmountexp ) ) == EOF )
    {
        return EOF;
    }

    return 0;
}


int Check ( struct Equation* Test, struct Keys* Answers )
{
    assert( Test );
    assert( Answers );

    int RootAmount = SquareSl( Test->a, Test->b, Test->c, &( Test->x1 ), &( Test->x2 ) );

    if ( !EqualsDouble( Answers->x1exp, Test->x1 ) ||
         !EqualsDouble( Answers->x2exp, Test->x2 ) ||
         !( Answers->RootAmountexp == RootAmount ) )
    {
        printf( RED "ERROR: a = %lf, b = %lf, c = %lf\n"
                    "Expected: x1 = %lf, x2 = %lf, RootAmount = %d\n"
                    "Result:   x1 = %lf, x2 = %lf, RootAmount = %d\n" reset,
                    Test->a, Test->b, Test->c, Answers->x1exp, Answers->x2exp,
                    Answers->RootAmountexp, Test->x1, Test->x2, RootAmount );
        return 1;
    }

    return 0;
}

void UserCalc( FILE* InputStream)
{
    assert( InputStream );

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    int RootCount = 0;
    bool KeepGoing = false;
    char Repeat = 'y';

    while ( Repeat == 'y' )
    {
        KeepGoing = UserInput( InputStream, &a, &b, &c );

        if ( KeepGoing == true )
        {
            RootCount = SquareSl( a, b, c, &x1, &x2 );
            Output( x1, x2, RootCount );

        }

        printf( "Do you want to calculate again?\n(" GRN "y" reset "/" RED "n" reset ")\n" );
        scanf( "%c", &Repeat );
    }

}


int ManualTest ( FILE* *InputStream )
{
    assert( InputStream );

    int MistakesCount = 0;
    struct Equation Preset = { NAN, NAN, NAN, NAN, NAN };
    struct Keys Answers = { NAN, NAN, 0 };

    while ( GetEquation( &Preset, InputStream ) != EOF && GetAnswers( &Answers, InputStream ) != EOF )
    {
        MistakesCount += Check( &Preset, &Answers );
    }

    return MistakesCount;
}

int AutoTest( void )
{
    struct Equation TestPreset[] = { {  .a = 1.0,  2.0,   1.0, NAN, NAN },
                                     {  2.0,  2.0,   2.0, NAN, NAN },
                                     {  0.0,  0.0,   0.0, NAN, NAN },
                                     { -1.0, 12.0, -32.0, NAN, NAN },
                                     {  1.0, -5.0,   6.0, NAN, NAN },
                                     {  1.0, -4.0,   4.0, NAN, NAN },
                                     {  1.0,  0.0,  -9.0, NAN, NAN },
                                     {  1.0,  4.0,   0.0, NAN, NAN },
                                     {  0.0,  3.0,  -6.0, NAN, NAN },
                                     {  1.0,  0.0,  -1.0, NAN, NAN } };

    struct Keys Answers[] = { { -1.0, NAN,       ONE_ROOT }, {   NAN, NAN,  NO_ROOTS },
                              {  NAN, NAN, INFINITY_ROOTS }, {   4.0, 8.0, TWO_ROOTS },
                              {  2.0, 3.0,      TWO_ROOTS }, {   2.0, NAN,  ONE_ROOT },
                              { -3.0, 3.0,      TWO_ROOTS }, {  -4.0, 0.0, TWO_ROOTS },
                              {  2.0, NAN,       ONE_ROOT }, {  -1.0, 1.0, TWO_ROOTS } };

    int TestAmount = sizeof( TestPreset ) / sizeof( Equation );
    int MistakesCount = 0;

    for ( int i = 0; i < TestAmount; i++ )
    {
        MistakesCount += Check( &TestPreset[ i ], &Answers[ i ] );
    }
    return MistakesCount;
}
