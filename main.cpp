#include <stdio.h>

#include "Tools.h"
#include "Modes.h"
#include "Terminal.h"


int TerminalCommands( int argc, char* argv[], FILE* InputStream );


int main( int argc, char* argv[] ) {

    FILE* InputStream = stdin;
    int CompilingMode = 0;

    CompilingMode = TerminalCommands( argc, argv, InputStream );

    switch ( CompilingMode ) {

        case USER_MODE :
            UserCalc( InputStream );
            break;

        case AUTO_TEST :
            AutoTest();
            break;

        default:
            printf( RED "ERROR, run code again." reset );
            break;


    }

    fclose( InputStream );
    printf( reset );
    return 0;

}



