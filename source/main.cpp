#include <stdio.h>
#include <assert.h>

#include "../header/Tools.h"
#include "../header/Modes.h"
#include "../header/Terminal.h"
#include "../header/Colours.h"
#include "../header/AI.h"

void ChoosingMode( int CompilingMode, FILE** InputStream );


int main( int argc, char* argv[] )
{
    FILE* InputStream = stdin;
    int CompilingMode = 0;

    CompilingMode = TerminalCommands( argc, argv, &InputStream );

    ChoosingMode( CompilingMode, &InputStream );

    fclose( InputStream );
    printf( reset "end\n" );
    return 0;
}

void ChoosingMode( int CompilingMode, FILE* InputStream )
{
    assert( InputStream );

    switch ( CompilingMode )
    {

        case USER_MODE :
            UserCalc( InputStream );
            break;

        case AUTO_TEST :
            AutoTest();
            break;

        case MANUAL_TEST :
            printf( "%d", ManualTest( InputStream ) );
            break;

        default :
            printf( RED "ERROR, run code again." reset );
            break;

    }

}
