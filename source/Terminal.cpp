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
                AutoTest();
                break;

            case 'm' :
                InputStream = stdin;
                if ( COTexoptarg != NULL )
                    InputStream = fopen( COTexoptarg, "r" );

                if( InputStream )
                {
                    printf( "%d", ManualTest( InputStream ) );
                }
                else
                    fprintf( stderr, HRED "Incorrect filename" );//TODO add normal description
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
                    fprintf( stderr, HRED "Incorrect filename " );//TODO add normal desciption

                break;

            case 'h' :
                printf( "To start User Mode type -usermode\n"
                        "To start Auto Test type -autotest\n"
                        "To start Manual Test type -mantest\n"
                        "To start AI mode type -COTexmode\n" );
                break;

            case '?' :
                fprintf( stderr, HRED
                    "====================================================\n"
                    "       COTex AI Argument Analysis System v0.0.1\n"
                    "====================================================\n"
                    "Unfortunately, the program was unable to understand\n"
                    "one of the command-line options provided by the user.\n\n"
                    "AI analysis result:\n"
                    "  Status: ARGUMENT PARSING FAILURE\n"
                    "  Problematic option: %s\n"
                    "  Function: %s\n"
                    "  Source file: %s\n"
                    "  Line number: %d\n\n"
                    "Probable explanation:\n"
                    "  The option is unknown, misspelled, unsupported, or\n"
                    "  requires an argument that was not provided.\n\n"
                    "Suggested AI solution:\n"
                    "  1. Check the spelling of the command-line option.\n"
                    "  2. Verify whether the option requires an argument.\n"
                    "  3. Consult the program's help message.\n"
                    "  4. Try again with arguments the program understands.\n\n"
                    "The requested operation cannot continue until the\n"
                    "command-line arguments have been corrected.\n"
                    "====================================================\n",
                    *argv, __func__, __FILE__, __LINE__ );
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
