#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../header/AutoTest.h"
#include "../COTexAI/AI.h"
#include "../COTexAI/COTexGetopt.h"
#include "../header/UserMode.h"
#include "../header/ManualMode.h"

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

    while ( KeepGoing == true && ( Command = COTexGetopt_long_only( argc, argv, long_options, NULL ) ) != -1 )
    {
        switch ( Command )
        {
            case 'c' : /// COTex
                COTexStart();
                break;

            case 'a' : /// Auto test
                AutoTest();
                break;

            case 'm' : /// Manual test
                StartManualTest( COTexoptarg );
                break;

            case 'u' : /// User mode
                RunUserMode( COTexoptarg );
                break;

            case 'h' : /// Help
                printf( "To start User    Mode type -usermode\n"
                        "To start Auto    Test type -autotest\n"
                        "To start Manual  Test type -mantest\n"
                        "To start AI      mode type -COTexmode\n" );
                break;

            case '?' : /// Unknown command
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
