#include <string.h>
#include <stdio.h>

enum Modes{ TERMINAL_INPUT_ERROR = -1, AUTO_TEST = 0, MANUAL_TEST = 1, USER_INPUT = 2 };


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
        else if ( !strcmp( argv[ 1 ], "userinp" ) ) {

            if ( argc > 2 ) {

                InputStream = fopen( argv[ 2 ], "r" );
                return ( InputStream ) ? MANUAL_TEST : TERMINAL_INPUT_ERROR;

            }

            return MANUAL_TEST;

        }
        else {

            return TERMINAL_INPUT_ERROR;

        }

    }

    return USER_INPUT;

}
