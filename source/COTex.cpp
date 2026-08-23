#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "../header/Colours.h"
#include "../header/SquareSolver.h"
#include "../header/Structures.h"
#include "../header/COTexIO.h"

//TODO systemspeak
//TODO substract Thinking func into new src and header
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

double GetTemp( void )
{
    return ( double ) rand() / 53687091;
}

void Forecast ( void )
{
    int IncorrectInputCount = 0;

    printf( "Please, input" );

}


void COTexEquasion( void )
{
    struct Equation Equ = { .a = NAN, .b = NAN, .c = NAN };
    struct Keys CompiledRoots = { .x1 = NAN, .x2 = NAN };
    bool KeepGoing = false;
    char Repeat = 'y';

    while ( Repeat == 'y' )
    {
        COTexInput( &Equ );
        Thinking( "Initializing", 3);
        if ( KeepGoing == true )
        {
            CompiledRoots.RootAmount = SquareSolve( Equ, &CompiledRoots );
            Thinking( "Thinking", 6 );
            COTexOutput( CompiledRoots );
        }

        printf( "Do you want to calculate again?\n(" GRN "y" reset "/" RED "n" reset ")\n" );
        scanf( "%c", &Repeat );
        if ( Repeat != 'y' && Repeat != 'n')
        {
            printf( "You even can't enter a correct answer, working with equations is too complicated for you, i'm out." );
            abort();
        }
    }

}

int KOTexStart( void )
{
    int Token = rand();
    char Answer[10] = "1234";

    Thinking( "Loading System", 4);

    printf( "Hi, it's KOTex, im innovative Human-based AI, that can provide you with essential functions.\n"
      BHRED "System loading...Tokens' amount: %d\n" reset,  Token );
    printf( "My inexhaustible variety of functions allows you to: \n"
            "1)  \"____\". Type " HCYN "" reset "\n"//TODO add a function
            "2) To ask me for a forecast . You " RED "must" reset " type " HYEL "weather" reset "\n"
            "3) The most " RED "useless " reset "function is to calculate a Square or Linear Equation. "
            "But if you still want it, type " UMAG "equation\n" reset );
    scanf( "%s", Answer );

    Thinking( "Processing", 3 );

    if ( !strcmp( Answer, "equation" ) )
    {
        COTexEquation();
        return 1;
    }
    else if ( !strcmp( Answer, "weather" ) )
    {

        return 0;
    }
    else if ( !strcmp( Answer, "____" ) )//TODO add a function
    {

        return 0;
    }
    else
    {
        printf(" Because of your unability to make a choice by your self,"
               " I will punish you and run Square equation calculator :( " )

    }
}

