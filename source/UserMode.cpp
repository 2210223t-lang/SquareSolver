#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>


#include "../header/Structures.h"
#include "../header/Tools.h"
#include "../header/Colours.h"
#include "../header/SquareSolver.h"

#define MAX_INPUT_AMOUNT 8;


double GetDouble( FILE* IStream, int* CountOfMistakes )
{
    assert( CountOfMistakes );
    assert( IStream );

    double Value = NAN;
    int InputAmount = fscanf( IStream, "%le", &Value );
    int Ch = getc( IStream );

    while ( --( *CountOfMistakes ) >= 0 && ( Ch != '\n' || InputAmount == 0 ) )
    {
            printf( "\"%c", Ch );

            while ( ( Ch = getc( IStream ) ) != '\n' ) putchar( Ch );

            if ( *CountOfMistakes > 0 )
            {
                printf( "\"" RED " is not a number, try again: " reset );
                InputAmount = fscanf( IStream, "%le", &Value );
                Ch = getc( IStream );
            }
            else
            {
                printf( "\"" RED " is not a number, too many attempts\n" reset );
                return NAN;
            }

        }

    return Value;
}

bool UserInput( FILE* IStream, struct Equation* Equ )
{
    assert( Equ );
    assert( IStream );

    int CountOfMistakes = MAX_INPUT_AMOUNT;

    printf( "Enter a: " );
    Equ->a = GetDouble( IStream, &CountOfMistakes );

    if ( CountOfMistakes > 0 )
    {
        printf( "\nEnter b: " );
        Equ->b = GetDouble( IStream, &CountOfMistakes );
    }

    if ( CountOfMistakes > 0 )
    {
        printf( "\nEnter c: " );
        Equ->c = GetDouble( IStream, &CountOfMistakes );
    }

    return ( CountOfMistakes <= 0 ) ? false : true;
}

void Output( struct Keys* CompiledRoots )
{

    switch ( CompiledRoots->RootAmount )
    {
        case INFINITY_ROOTS : /* infinity roots */
            printf( RED "Too many roots\n" reset );
            break;

        case NO_ROOTS : /* no roots */
            printf( YEL "0 roots\n" reset );
            break;

        case ONE_ROOT : /* 1 root */
            printf( GRN "1 root\nx1 = %lf\n" reset, CompiledRoots->x1 );
            break;

        case TWO_ROOTS : /* 2 roots */
            printf( GRN "2 roots\nx1 = %lf\nx2 = %lf\n" reset, CompiledRoots->x1, CompiledRoots->x2 );
            break;

        default: /* ERROR */
            printf( RED "Error, unexpected amount of roots" reset );
            break;
    }

}

void UserCalc( FILE* InputStream )
{
    assert( InputStream );

    struct Equation Equ = { .a = NAN, .b = NAN, .c = NAN };
    struct Keys CompiledRoots = { .x1 = NAN, .x2 = NAN };
    bool KeepGoing = false;
    char Repeat = 'y';

    while ( tolower( Repeat ) == 'y' )
    {
        KeepGoing = UserInput( InputStream, &Equ );

        if ( KeepGoing == true )
        {
            CompiledRoots.RootAmount = SquareSolve( &Equ, &CompiledRoots );
            Output( &CompiledRoots );
        }

        printf( "Do you want to calculate again?\n(" GRN "y" reset "/" RED "n" reset ")\n" );
        scanf( "%c", &Repeat );
    }

}

void RunUserMode( char* COTexoptarg )
{
    FILE* InputStream = stdin;

    if ( COTexoptarg != NULL ) /// If no argument
        InputStream = fopen( COTexoptarg, "r" );

    if ( InputStream ) /// If file openned
    {
        UserCalc( InputStream );
    }
    else /// If file didn't opened
        fprintf( stderr, HRED "Cannot open the file: %s", COTexoptarg );
}


