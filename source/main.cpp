#include <stdio.h>

#include "../header/Tools.h"
#include "../header/Modes.h"
#include "../header/Terminal.h"
#include "../header/Colours.h"


int main( int argc, char* argv[] )
{
    FILE* InputStream = stdin;
    int CompilingMode = 0;

    CompilingMode = TerminalCommands( argc, argv, &InputStream );
///TODO extract into func
    switch ( CompilingMode )
    {

        case USER_MODE :
            UserCalc( &InputStream );
            break;

        case AUTO_TEST :
            AutoTest();
            break;

        case MANUAL_TEST :
            printf( "%d", ManualTest( &InputStream ) );
            break;

        default :
            printf( RED "ERROR, run code again." reset );
            break;

    }

    fclose( InputStream );
    printf( reset "end\n" );
    return 0;
}



