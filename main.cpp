#include <stdio.h>
#include <ctype.h>

#include "SquareEquationSolver.h"

void ColourOverload();

int main( int argc, char* argv[] ) {
    char Repeat = 'y';
    FILE* IStream = stdin;

    if ( argc >= 2 ) {
        IStream = fopen( argv[1], "r" );
    }

    if ( IStream == NULL ) {
        printf("Run program again, you've enterred wrong file :(");

        return 0;
    }

    while ( tolower(Repeat) == 'y' ) {
        SquareEquationSolver( IStream );

        printf( "Do you want to calculate again?\n(y/n)\n" );

        scanf( "%c", &Repeat );
    }

    fclose( IStream );
    printf("\e[0m");
    return 0;
}
