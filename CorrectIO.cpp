#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "Colours.h"

enum RootAmount{ INFINITYROOTS = -1, NOROOTS = 0, ONEROOT = 1, TWOROOTS = 2 };

void Swap ( double* a, double* b ) {
    double c = *a;
    *a = *b;
    *b = c;
}

double GetDouble( FILE* IStream, int* CountOfMistakes ) {
    assert( CountOfMistakes );
    assert( IStream );

    double Value = NAN;
    int InputAmount = fscanf( IStream, "%le", &Value );
    int Ch = getc( IStream );

    while ( --( *CountOfMistakes ) >= 0 && ( Ch != '\n' || InputAmount == 0 ) ) {
            printf( "\"%c", Ch );

            while ( ( Ch = getc( IStream ) ) != '\n' ) {
                putchar( Ch );
            }
            if ( *CountOfMistakes > 0 ) {
                printf( RED "\" is not a number, try again: " reset );
                InputAmount = fscanf( IStream, "%le", &Value );
                Ch = getc( IStream );
            }
            else {
                printf( "\" is not a number, too many attempts\n" reset);
                return NAN;
            }
        }
    return Value;
}

bool Input( FILE* IStream, double* a, double* b, double* c ) {
    assert( a );
    assert( b );
    assert( c );
    assert( IStream );

    int CountOfMistakes = 5;

    printf( "Enter a: " );
    *a = GetDouble( IStream, &CountOfMistakes );

    if ( !isnan( *a ) ) {
        printf( "\nEnter b: " );
        *b = GetDouble( IStream, &CountOfMistakes );
    }

    if ( !isnan( *b ) ) {
        printf( "\nEnter c: " );
        *c = GetDouble( IStream, &CountOfMistakes );
    }

    if ( isnan( *c ) ) {
        return false;
    }
    else {
        return true;
    }
}

void Output( double* x1, double* x2, int* RootQuantity ) {
    assert( x1 );
    assert( x2 );
    assert( RootQuantity );

    switch ( *RootQuantity ) {
        case INFINITYROOTS : /* infinity roots */
            printf( RED "too many roots\n" reset );
            break;

        case NOROOTS : /* no roots */
            printf( "0 roots\n" );
            break;

        case ONEROOT : /* 1 root */
            printf( "1 root\n x1 = %lf\n", *x1 );
            break;

        case TWOROOTS : /* 2 roots */
            printf( " 2 roots\n x1 = %lf\n x2 = %lf\n", *x1, *x2 );
            break;

        default:
            printf( RED "Error, unexpected amount of roots" reset );
            break;
    }
}
