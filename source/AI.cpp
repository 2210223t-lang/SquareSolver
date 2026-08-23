#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#include "../header/Colours.h"


void Thinking( char Text[], int time ) {
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
}
void Forecast ( int* Tokens )
{
    assert( Tokens );
    int IncorrectInputCount = 0;

    printf( "Please, input" );

}

double GetTemp( void )
{
    return ( double ) rand() / 53687091;
}

int KOTexStart( int MistakeAmount )
{
    int Token = rand();
    char Answer[10] = "1234";
    int ErrorCount = 0;

    Thinking( "Loading System", 4);

    printf( "Hi, it's KOTex, im innovative Human-based AI, that can provide you with essential functions.\n"
      BHRED "System loading...Tokens' amount: %d\n" reset,  Token );
    printf( "My inexhaustible variety of functions allows you to: \n"
            "1)  \"____\". Type " HCYN "" reset "\n"//TODO add a function
            "2) To ask me for a forecast . You " RED "must" reset " type " HYEL "weather" reset "\n"
            "3) The most " RED "useless " reset "function is to calculate a Square or Linear Equation. "
            "But if you still want it, type " UMAG "equation\n" reset );
    scanf( "%s", Answer );


    if ( !strcmp( Answer, "equation" ) )
    {
        printf( "Thanks for your choice!!!" );
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
        printf(" Because of your unability to make a choice by your self, i will punish you and run Square equation calculator ")
    }
}

