#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "../header/Colours.h"

struct EquationGraph
{
float a;
float b;
float c;
};

#define MAX_INPUT_AMOUNT_GRAPH 5


float GetFloat( int* CountOfMistakes )
{
    assert( CountOfMistakes );

    float Value = 0;
    int InputAmount = scanf( "%f", &Value );
    int Ch = getchar();

    while ( --( *CountOfMistakes ) >= 0 && ( Ch != '\n' || InputAmount == 0 ) )
    {
            printf( "\"%c", Ch );

            while ( ( Ch = getchar() ) != '\n' ) putchar( Ch );

            if ( *CountOfMistakes > 0 )
            {
                printf( "\"" RED " is not a number, try again: " reset );
                InputAmount = scanf( "%f", &Value );
                Ch = getchar();
            }
            else
            {
                printf( "\"" RED " is not a number, too many attempts\n" reset );
                return 0;
            }

        }

    return Value;
}

bool GraphInput( struct EquationGraph* Equ )
{
    assert( Equ );

    int CountOfMistakes = MAX_INPUT_AMOUNT_GRAPH;

    printf( "Enter a: " );
    Equ->a = GetFloat( &CountOfMistakes );

    if ( CountOfMistakes > 0 )
    {
        printf( "\nEnter b: " );
        Equ->b = GetFloat( &CountOfMistakes );
    }

    if ( CountOfMistakes > 0 )
    {
        printf( "\nEnter c: " );
        Equ->c = GetFloat( &CountOfMistakes );
    }

    return ( CountOfMistakes <= 0 ) ? false : true;
}
