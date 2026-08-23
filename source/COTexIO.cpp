#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "../header/Structures.h"
#include "../header/Colours.h"
#include "../header/Colours.h"
#include "../header/COTexSpeech.h"

//TODO add assertAI with correct phrases!

void Thinking( char Text[], int time )
{
    printf( "%s...",  Text );
    fflush(stdout);

    for ( int i = 0; i < time; i++ )
    {
        sleep(1);
        printf( "\r%s   ", Text );
        fflush(stdout);

        sleep(1);
        printf( "\r%s.", Text );
        fflush(stdout);

        sleep(1);
        printf( "\r%s..", Text );
        fflush(stdout);

        sleep(1);
        printf( "\r%s...", Text );
        fflush(stdout);

    }
    printf("\r");
}

void MistakesReaction( int* MistakesAmount )
{

    switch ( *MistakesAmount )
    {
        case GOOD :
            printf( "%s", GOOD_MOOD );
            break;

        case NEUTRAL :
            printf( "%s", NEUTRAL_MOOD );
            break;

        case ANGRY :
            printf( "%s", ANGRY_MOOD );
            break;

        case FURY :
            printf( "%s", FURY_MOOD );
            break;

        case FRIED :
            printf( "%s", FRIED_MOOD );
            abort();

        default :
            printf( "file %s, line %d\n", __FILE__, __LINE__);
            abort();

    };

}

double COTexGetDouble( int* MistakesAmount )
{
    assert( MistakesAmount );

    double Value = NAN;
    int InputAmount = scanf( "%lf", &Value );
    int Ch = getchar();

    Thinking( "Initializing", 3 );

    while ( *MistakesAmount > 0 && ( Ch != '\n' || InputAmount == 0 ) )
    {
         --( *MistakesAmount );

        printf( RED "\"%c" reset, Ch );

        while ( ( Ch = getchar() ) != '\n' ) putchar( Ch );

        MistakesReaction( MistakesAmount );

        InputAmount = scanf( "%le", &Value );
        Ch = getchar();

        Thinking( "Initializing", 3 );
    }

    return Value;
}

void COTexInput( struct Equation* Equ)
{
    assert( Equ );

    int CountOfMistakes = 5;

    printf( "Please, enter a: " );
    Equ->a = COTexGetDouble( &CountOfMistakes );

    printf( "\nEnter b: " );
    Equ->b = COTexGetDouble( &CountOfMistakes );

    printf( "\nEnter c: " );
    Equ->c = COTexGetDouble( &CountOfMistakes );
}

void Output( struct Keys CompiledRoots )
{

    switch ( CompiledRoots.RootAmount )
    {
        case INFINITY_ROOTS : /* infinity roots */
            printf( RED "too many roots\n" reset );
            break;

        case NO_ROOTS : /* no roots */
            printf( YEL "0 roots\n" reset );
            break;

        case ONE_ROOT : /* 1 root */
            printf( GRN "1 root\nx1 = %lf\n" reset, CompiledRoots.x1 );
            break;

        case TWO_ROOTS : /* 2 roots */
            printf( GRN " 2 roots\nx1 = %lf\n x2 = %lf\n" reset, CompiledRoots.x1, CompiledRoots.x2 );
            break;

        default: /* ERROR */
            printf( RED "Error, unexpected amount of roots" reset );
            break;
    }

}
