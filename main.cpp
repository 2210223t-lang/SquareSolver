#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "Colours.h"
#include "SquareEquationSolver.h"

enum Modes{ TERMINAL_INPUT_ERROR = -1, AUTO_TEST = 0, MANUAL_TEST = 1, USER_INPUT = 2 };

int TerminalCommands( int argc, char* argv[], FILE* InputStream );


int main( int argc, char* argv[] ) {
    char Repeat = 'y';
    FILE* InputStream = stdin;
    int CompilingMode = 0;

    CompilingMode = TerminalCommands( argc, argv, InputStream );

    while ( tolower( Repeat ) == 'y' ) {

        SquareEquationSolver( InputStream );

        printf( "Do you want to calculate again?\n(y/n)\n" );

        scanf( "%c", &Repeat );

    }

    fclose( InputStream );
    printf( reset );
    return 0;

}


int TerminalCommands( int argc, char* argv[], FILE* InputStream) {

    if ( argc > 1 ) {

        if ( !strcmp( argv[ 1 ], "autotest") ) {

            return AUTO_TEST;

        }
        else if ( !strcmp( argv[ 1 ], "mantest" ) ) {

            if ( argc > 2 ) {

                InputStream = fopen( argv[ 2 ], "r" );
                return ( InputStream ) ? MANUAL_TEST : TERMINAL_INPUT_ERROR;

            }

                return MANUAL_TEST;

        }

    }

    return USER_INPUT;

}
