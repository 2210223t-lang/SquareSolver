#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>

#include "../header/Structures.h"
#include "../header/Colours.h"
#include "COTexSpeech.h"
#include "../header/Tools.h"
#include "COTexUtility.h"
#include "../header/SquareSolver.h"
#include "COTexAssert.h"


/**
 * @brief Prints special sentence for every remaining amount of mistakes
 *
 * @param[ in ] MistakesAmount int* MistakesAmount shows remaining amount of mistakes
 *
 * @details When MistakesAmount == 0, it tells a user that it shots down and closing code
 */
void MistakesReaction( int* MistakesAmount )
{
    COTexAssert( MistakesAmount );

    switch ( *MistakesAmount )
    {
        case GOOD :
            printf( "\"" );
            PrintAI( GOOD_MOOD, HCYN );
            break;

        case NEUTRAL :
            printf( "\"" );
            PrintAI( NEUTRAL_MOOD, HCYN );
            break;

        case ANGRY :
            printf( "\"" );
            PrintAI( ANGRY_MOOD, HCYN );
            break;

        case FURY :
            printf( "\"" );
            PrintAI( FURY_MOOD, HCYN );
            break;

        case FRIED :
            printf( "\"" );
            PrintAI( "<---I'm fried, ", HCYN );
            PrintAI(" FUCK OUT!!!\n", HRED );
            Thinking( "Formatting a hard drive", 5 );
            abort();

        default :
            printf( "file %s, line %d\n", __FILE__, __LINE__);
            abort();

    };

}

/**
 * @brief Taking doubel from stdin
 *
 * @param[ in, out ] MistalesAmount int MistakesAmount shows how many input mistakes user can make
 *
 * @return Returns inputted value and NAN
 *
 * @details Works untill user will enter correct value or make too many mistakes.
 *          Function provide different feedback for different amount of made mistakes, imitating
 *          that AI is loosing his temper with every mistake
 */
double COTexGetDouble( int* MistakesAmount )
{
    COTexAssert( MistakesAmount );

    double Value = NAN;
    int InputAmount = scanf( "%lf", &Value );
    int Ch = getchar();

    Thinking( "Initializing", 3 );

    /// Checks if there are attempts left and that word is double
    while ( ( *MistakesAmount > 0 && ( Ch != '\n' || InputAmount == 0 ) ) || ( !isfinite( Value ) ) )
    {
         --( *MistakesAmount );

        putchar( '\"');
        if( !isfinite( Value ) ) printf( HRED "%lf" reset, Value );
        if( Ch != '\n' )
        {
            printf( HRED "%c" reset, Ch );
            while ( ( Ch = getchar() ) != '\n' ) printf( HRED "%c" reset, Ch );
        }

        MistakesReaction( MistakesAmount );

        InputAmount = scanf( "%le", &Value );
        Ch = getchar();

        Thinking( "Initializing", 3 );
    }

    return Value;
}

void COTexInput( struct Equation* Equ)
{
    COTexAssert( Equ );

    int CountOfMistakes = 5;

    PrintAI( "Please, enter a: ", HCYN );
    Equ->a = COTexGetDouble( &CountOfMistakes );

    PrintAI( "I'm waiting for b: ", HCYN );
    Equ->b = COTexGetDouble( &CountOfMistakes );

    PrintAI( "I hope that you will enter c: ", HCYN );
    Equ->c = COTexGetDouble( &CountOfMistakes );
}

void COTexOutput( struct Keys* CompiledRoots )
{

    switch ( CompiledRoots->RootAmount )
    {
        case INFINITY_ROOTS : /* infinity roots */
            printf( RED "Your equasion have infinity roots\n" reset );
            break;

        case NO_ROOTS : /* no roots */
            printf( YEL "Your equasion don't have any roots roots\n" reset );
            break;

        case ONE_ROOT : /* 1 root */
            printf( BLU "Your equasion have only one root and it is %lf\n" reset, CompiledRoots->x1 );
            break;

        case TWO_ROOTS : /* 2 roots */
            printf(  HCYN " 2 roots\nx1 = %lf\n x2 = %lf\n" reset, CompiledRoots->x1, CompiledRoots->x2 );
            break;

        default: /* ERROR */
            printf( RED "ERROR" reset );
            break;
    }

}

/**
 * @brief Starts calculating roots wit AI assistant
 *
 * @return 0 if user answered incorrect on ask for continuation of work and 1 if code exited successfully
 */
int COTexEquation( void )
{
    struct Equation Equ = { .a = NAN, .b = NAN, .c = NAN };
    struct Keys CompiledRoots = { .x1 = NAN, .x2 = NAN };
    char Repeat = 'y';

    while ( Repeat == 'y' )
    {
        COTexInput( &Equ );


        CompiledRoots.RootAmount = SquareSolve( &Equ, &CompiledRoots );
        Thinking( "Calculating Roots", 6 );
        COTexOutput( &CompiledRoots );

        printf( "Do you want to calculate again?\n(" HCYN );
        PrintAI(   "y",   GRN );
        PrintAI(   "/",  HCYN );
        PrintAI( "n",   RED );
        PrintAI(   ")",  HCYN );
        scanf( "%c", &Repeat );
        Thinking( "Kumekay", 3 );
        if ( Repeat != 'y' && Repeat != 'n')
        {
            PrintAI( "You even can't enter a correct answer, "
                     "working with equations is too complicated for you, i'm out.\n", MAG );
            Thinking( "Self-removing", 5 );
            return 0;
        }
    }
    return 1;
}
