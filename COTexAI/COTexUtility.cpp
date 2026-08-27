#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header/Colours.h"
#include "COTexAssert.h"

#define POINT_TIMING 700000 ///< Sets a time between printing one point in Thinking func

#define PRINT_TIMING 50000 ///< Sets a time between printing letters in PrintAI func


void PrintAI( const char* text, const char* colour )
{
    COTexAssert( text );
    COTexAssert( colour );

    while ( *text )
    {
        printf( "%s%c", colour, *text );
        fflush( stdout );
        usleep( PRINT_TIMING );
        text++;
    }
    printf( reset );
}

void Thinking( const char* Text, int time )
{
    COTexAssert( Text );

    PrintAI( Text, GRN );

    fflush( stdout );

    for ( int i = 0; i < time; i++ )
    {

        usleep( POINT_TIMING );
        printf( GRN "\r%s.", Text );
        fflush( stdout );

        usleep( POINT_TIMING );
        printf( GRN "\r%s..", Text );
        fflush( stdout );

        usleep( POINT_TIMING );
        printf( GRN "\r%s...", Text );
        fflush( stdout );

        usleep( POINT_TIMING );
        printf( GRN "\r%s   ", Text );
        fflush( stdout );

    }
    printf( "\r" reset );
}




void PrintAIFunctions()
{
    PrintAI( "Unforturnately, you have Tokens only for a part of my inexhaustible variety of functions that allows you to: \n"
             "1)  \"____\". Type \n", HCYN );
    PrintAI( "2) To ask me for a forecast . You ", HCYN );
    PrintAI( "must ", RED );
    PrintAI( "type ", HCYN );
    PrintAI( "weather\n", HBLU );
    PrintAI( "3) The most ", HCYN );
    PrintAI( "useless ", RED );
    PrintAI( "function is to calculate a Square or Linear Equation. But if you still want it, type ",HCYN );
    PrintAI( "equation\n", RED );
}
