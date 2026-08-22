#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "Colours.h"
#include "SquareEquationSolver.h"
#include "Terminal.h"

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



