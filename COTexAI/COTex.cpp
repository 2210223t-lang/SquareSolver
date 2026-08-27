#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "../header/Colours.h"
#include "COTexEquation.h"
#include "COTexUtility.h"
#include "COTexFeatures.h"


void KOTexStart( void )
{
    srand( ( unsigned ) time( NULL ) );

    int Token = rand();
    char Answer[100] = "1234";

    Thinking( "Loading System", 4);

    PrintAI( "Hi, it's KOTex, I'm innovative Human-based AI-assistant, that can provide you with essential functions.\n", HCYN );
    PrintAI( "Tokens' amount: ", BHRED );
    printf( BHRED "%d\n" reset, Token );
    PrintAIFunctions();
    scanf( "%s", Answer );

    Thinking( "Processing", 3 );

    if ( !strcmp( Answer, "equation" ) )
    {
        COTexEquation();
    }
    else if ( !strcmp( Answer, "weather" ) )
    {
        COTexWeather();
    }
    else if ( !strcmp( Answer, "____" ) )
    {

    }
    else /// If user enterred incorrect keyword
    {
        PrintAI( "ERROR: Token shortage.\nToken needed to process you request: ", HRED );
        printf( HRED "%d\n" reset, Token + 1 );
        PrintAI( "Token available: ", HRED );
        printf( HRED "%d\n" reset, Token );
        Thinking( "Looking for appropriate function", 3);
        Thinking( "Loading essential libraries and extensions", 2 );
        PrintAI(  "Automaticaly running the most appropriate function of solving square equasion\n", HCYN);
        COTexEquation();
    }
    printf( reset );
}

