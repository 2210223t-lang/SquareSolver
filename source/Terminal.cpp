#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../header/Modes.h"
#include "../COTexAI/AI.h"
#include "../COTexAI/COTexGetopt.h"
#include "../header/Colours.h"


void TerminalCommands( int argc, char* argv[] )
{
    FILE* InputStream = stdin;

    struct COTexOption long_options[] = { { "COTexmode",      NO_ARGUMENTS, 0, 'c' },
                                          {  "autotest",      NO_ARGUMENTS, 0, 'a' },
                                          {   "mantest", OPTIONAL_ARGUMENT, 0, 'm' },
                                          {  "usermode", OPTIONAL_ARGUMENT, 0, 'u' },
                                          {      "help",      NO_ARGUMENTS, 0, 'h' },
                                          {           0,                 0, 0,  0  } };
    int Command = 0;
    bool KeepGoing = true;

    while( KeepGoing == true && ( Command = COTexGetopt_long_only( argc, argv, long_options, NULL ) ) != -1 )
    {
        switch ( Command )
        {
            case 'c' :
                KOTexStart();
                break;

            case 'a' :
                printf( "Test ended with: %d mistakes.\n", AutoTest() );
                break;

            case 'm' :
                InputStream = stdin;
                printf( "Expected sequence of input: a, b, c, x1, x2, RootAmount.\n"
                        "To stop testing press Ctrl + Z\n" );
                if ( COTexoptarg != NULL )
                    InputStream = fopen( COTexoptarg, "r" );

                if( InputStream )
                {
                    printf( "Test ended with: %d mistakes\n", ManualTest( InputStream ) );
                }
                else
                    fprintf( stderr, HRED "IncorrectFilename: %s", FileNameFailure );
                break;

            case 'u' :
                InputStream = stdin;
                if ( COTexoptarg != NULL )
                    InputStream = fopen( COTexoptarg, "r" );
                if ( InputStream )
                {
                    UserCalc( InputStream );
                }
                else
                    fprintf( stderr, HRED "%s", FileNameFailure );

                break;

            case 'h' :
                printf( "To start User    Mode type -usermode\n"
                        "To start Auto    Test type -autotest\n"
                        "To start Manual  Test type -mantest\n"
                        "To start AI      mode type -COTexmode\n" );
                break;

            case '?' :
                KeepGoing = false;
                break;

            default :
                fprintf( stderr, "Getopt error" );
                KeepGoing = false;
                break;
        }

    }
    fclose( InputStream );
}
