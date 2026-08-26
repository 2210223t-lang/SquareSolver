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

    struct COTexOption long_options[] = { { "COTexmode", OPTIONAL_ARGUMENT, 0, 'c' },
                                          {  "autotest",      NO_ARGUMENTS, 0, 'a' },
                                          {   "mantest",      NO_ARGUMENTS, 0, 'm' },
                                          {  "usermode",      NO_ARGUMENTS, 0, 'u' },
                                          {      "help",      NO_ARGUMENTS, 0, 'h' },
                                          {           0,                 0, 0,  0  } };
    int Command = 0;

    while( ( Command = COTexGetopt_long_only( argc, argv++, long_options, NULL ) ) != -1 )
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
                //extern char* COTexoptarg;
                InputStream = stdin;
                if ( COTexoptarg != NULL )
                    InputStream = fopen( COTexoptarg, "r" );

                printf( "%d", ManualTest( InputStream ) );
                break;

            case 'u' :
                InputStream = stdin;
                if ( COTexoptarg != NULL )
                    InputStream = fopen( COTexoptarg, "r" );

                UserCalc( InputStream );
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
                    *( --argv ), __func__, __FILE__, __LINE__ );
                break;

            default :
                fprintf( stderr, "Getopt error" );
                break;
        }

    }
    fclose( InputStream );
}
