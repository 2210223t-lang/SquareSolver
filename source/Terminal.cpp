#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <stdlib.h>

#include "../header/Modes.h"
#include "../COTexAI/AI.h"


void TerminalCommands( int argc, char* argv[] )
{
    FILE* InputStream = stdin;

    struct option long_options[] = { { "COTexmode",       no_argument, 0, 'c' },
                                     {  "autotest",       no_argument, 0, 'a' },
                                     {   "mantest", optional_argument, 0, 'm' },
                                     {  "usermode", optional_argument, 0, 'u' },
                                     {      "help",       no_argument, 0, 'h' },
                                     {           0,                 0, 0,  0  } };
    int Command = 0;

    while( ( Command = getopt_long_only( argc, argv, "cam::u::h", long_options, NULL ) ) != -1 )
    {
        switch ( Command )
        {
            case 'c' :
                KOTexStart();
                break;

            case 'a' :
                AutoTest();
                break;

            case 'm' :
                InputStream = stdin;
                if ( optarg != NULL )
                    InputStream = fopen( optarg, "r" );

                printf( "%d", ManualTest( InputStream ) );
                break;

            case 'u' :
                InputStream = stdin;
                if ( optarg != NULL )
                    InputStream = fopen( optarg, "r" );

                UserCalc( InputStream );
                break;

            case 'h' :
                printf( "To start User Mode type -usermode\n"
                        "To start Auto Test type -autotest\n"
                        "To start Manual Test type -mantest\n"
                        "To start AI mode type -COTexmode\n" );
                break;

            case '?' :
                fprintf( stderr, "Incorrect command" );
                break;

            default :
                fprintf( stderr, "Getopt error" );
                break;
        }

    }
    fclose( InputStream );
}
