#include <unistd.h>
#include <stdio.h>

#include "../header/Colours.h"

#define POINT_TIMING 700000


void Thinking( char* Text, int time )
{
    printf( GRN "%s...",  Text );
    fflush(stdout);

    for ( int i = 0; i < time; i++ )
    {
        usleep( POINT_TIMING );
        printf( "\r%s   ", Text );
        fflush(stdout);

        usleep( POINT_TIMING );
        printf( "\r%s.", Text );
        fflush(stdout);

        usleep( POINT_TIMING );
        printf( "\r%s..", Text );
        fflush(stdout);

        usleep( POINT_TIMING );
        printf( "\r%s...", Text );
        fflush(stdout);

    }
    printf("\r" reset );
}

void PrintAIFunctions()
{
    printf( HCYN "Unforturnately, you have Tokens only for a part of my inexhaustible variety of functions that allows you to: \n"
            "1)  \"____\". Type " RED "" reset HCYN "\n"//TODO add a function
            "2) To ask me for a forecast . You " RED "must" reset HCYN " type " HBLU "weather" reset HCYN "\n"
            "3) The most " RED "useless " reset HCYN "function is to calculate a Square or Linear Equation. "
            "But if you still want it, type " RED "equation\n" reset );
}
