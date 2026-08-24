#include <unistd.h>
#include <stdio.h>

#include "../header/Colours.h"

#define POINT_TIMING 700000

#include <stdio.h>
#include <stdlib.h>

#define COTexAssert(condition)                                             \
    do {                                                                   \
        if (!(condition)) {                                                \
            fprintf(stderr,                                                \
                "\n"                                                       \
                "====================================================\n"   \
                "       COTex AI Diagnostic System v0.0.1\n"               \
                "====================================================\n"   \
                "Unfortunately, the program encountered a condition\n"     \
                "that it was emotionally and technically unprepared\n"     \
                "to process.\n\n"                                          \
                "AI analysis result:\n"                                    \
                "  Status: CRITICAL FAILURE\n"                             \
                "  Failed condition: %s\n"                                \
                "  Function: %s\n"                                        \
                "  Source file: %s\n"                                     \
                "  Line number: %d\n\n"                                   \
                "Probable explanation:\n"                                  \
                "  A required pointer may be NULL, an assumption may\n"    \
                "  be incorrect, or reality may have refused to follow\n"  \
                "  the programmer's expectations.\n\n"                     \
                "Suggested AI solution:\n"                                 \
                "  1. Inspect the failed condition.\n"                     \
                "  2. Check all relevant pointers and arguments.\n"        \
                "  3. Question every decision that led to this moment.\n"  \
                "  4. Fix the bug and pretend this never happened.\n\n"    \
                "The program will now terminate to prevent further\n"      \
                "damage and unnecessary consumption of your tokens.\n"     \
                "====================================================\n",  \
                #condition, __func__, __FILE__, __LINE__);                 \
            abort();                                                       \
        }                                                                  \
    } while (0)


void PrintAI( const char* text, const char* colour )
{
    COTexAssert( text );
    COTexAssert( colour );

    while( *text )
    {
        printf( "%s%c", colour, *text );
        fflush( stdout );
        usleep( 50000 );
        text++;
    }
    printf( reset );
}

void Thinking( const char* Text, int time )
{
    COTexAssert( Text );

    PrintAI( Text, GRN );

    fflush(stdout);

    for ( int i = 0; i < time; i++ )
    {

        usleep( POINT_TIMING );
        printf( GRN "\r%s.", Text );
        fflush(stdout);

        usleep( POINT_TIMING );
        printf( GRN "\r%s..", Text );
        fflush(stdout);

        usleep( POINT_TIMING );
        printf( GRN "\r%s...", Text );
        fflush(stdout);

        usleep( POINT_TIMING );
        printf( GRN "\r%s   ", Text );
        fflush(stdout);

    }
    printf("\r" reset );
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
    PrintAI( "function is to calculate a Square or Linear Equation. But if you still want it, type ",HCYN);
    PrintAI( "equation\n", RED );
}
