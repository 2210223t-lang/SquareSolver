#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "../header/Colours.h"
#include "COTexEquation.h"
#include "COTexUtility.h"

//TODO read about dynamic data
//TODO systemspeak

//TODO FIX
double GetTemp( void )
{
    return ( double ) rand() / 53687091;
}

//TODO FIX IT
void Forecast ( void )
{
    int IncorrectInputCount = 0;

    printf( "Please, input" );

}

void KOTexStart( void )
{
    int Token = rand();
    char Answer[10] = "1234";

    Thinking( "Loading System", 4);

    printf( HCYN "Hi, it's KOTex, I'm innovative Human-based AI, that can provide you with essential functions.\n"
      BHRED "Tokens' amount: %d\n" reset,  Token );
    PrintAIFunctions();
    scanf( "%s", Answer );

    Thinking( "Processing", 3 );

    if ( !strcmp( Answer, "equation" ) )
    {
        COTexEquation();
    }
    else if ( !strcmp( Answer, "weather" ) )
    {
        //TODO add weather
    }
    else if ( !strcmp( Answer, "____" ) )//TODO add a function
    {
        //TODO add smth
    }
    else
    {
        printf( HRED "ERROR: Token shortage.\n"
                HRED "Token needed: %d\n"
                     "Token available: %d\n" reset, Token + 1, Token );
        Thinking( "Looking for appropriate function", 3);
        Thinking( "Loading essential libraries", 2 );
        printf( HCYN "Automaticaly running the most appropriate function of solving square equasion\n" reset );
        COTexEquation();
    }
    printf( reset );
}

