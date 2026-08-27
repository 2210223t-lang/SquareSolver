#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "../header/Tools.h"
#include "../header/Colours.h"
#include "../header/Structures.h"

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

bool UserInput( FILE* IStream, struct Equation* Equ)
{
    assert( Equ );
    assert( IStream );

    int CountOfMistakes = MAX_INPUT_AMOUNT;

    printf( "Enter a: " );
    Equ->a = GetDouble( IStream, &CountOfMistakes );

    if ( !isnan( Equ->a ) )
    {
        printf( "\nEnter b: " );
        Equ->b = GetDouble( IStream, &CountOfMistakes );
    }

    if ( !isnan( Equ->b ) )
    {
        printf( "\nEnter c: " );
        Equ->c = GetDouble( IStream, &CountOfMistakes );
    }

    return ( isnan( Equ->c ) ) ? false : true;
}

void Output( struct Keys* CompiledRoots )
{

    switch ( CompiledRoots->RootAmount )
    {
        case INFINITY_ROOTS : /* infinity roots */
            printf( RED "too many roots\n" reset );
            break;

        case NO_ROOTS : /* no roots */
            printf( YEL "0 roots\n" reset );
            break;

        case ONE_ROOT : /* 1 root */
            printf( GRN "1 root\nx1 = %lf\n" reset, CompiledRoots->x1 );
            break;

        case TWO_ROOTS : /* 2 roots */
            printf( GRN " 2 roots\n x1 = %lf\n x2 = %lf\n" reset, CompiledRoots->x1, CompiledRoots->x2 );
            break;

        default: /* ERROR */
            printf( RED "Error, unexpected amount of roots" reset );
            break;
    }

}
