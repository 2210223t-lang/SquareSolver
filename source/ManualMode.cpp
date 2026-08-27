#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "../header/Structures.h"
#include "../header/Colours.h"
#include "../header/ModeUtility.h"

int ManualTest( FILE* InputStream )
{
    assert( InputStream );

    int MistakesCount = 0;
    struct Equation Preset = { .a = NAN, .b = NAN, .c = NAN };
    struct Keys Answers = { .x1 = NAN, .x2 = NAN };

    while ( GetEquation( &Preset, InputStream ) != EOF && GetKeys( &Answers, InputStream ) != EOF )
    {
        MistakesCount += CheckAnswer( &Preset, &Answers );
    }

    return MistakesCount;
}


void StartManualTest( char* COTexoptarg )
{

    FILE* InputStream = stdin;

    if ( COTexoptarg ) /// If there is an argument
        InputStream = fopen( COTexoptarg, "r" );

    if( InputStream ) /// If openned
    {
        printf( "Expected sequence of input: a, b, c, x1, x2, RootAmount.\n"
                "To stop testing press Ctrl + Z\n" );

        printf( "Test ended with: %d mistakes\n", ManualTest( InputStream ) );
    }
    else /// If didn't openned
        fprintf( stderr, HRED "IncorrectFilename: %s", COTexoptarg );
}
