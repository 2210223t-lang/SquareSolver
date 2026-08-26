#include <stdio.h>
// #include <string.h>

#include "../header/Colours.h"
#include "COTexAssert.h"

enum ArgumentAmount{ NO_ARGUMENTS = 0, REQUIRED_ARGUMENT = 1, OPTIONAL_ARGUMENT = 2 };

static int number = 1;

struct COTexOption
{
const char* Command;
int ArgumentAmount;
int* flag;
int value;
};

char* COTexoptarg;


bool CheckCommand( char* Command, const char* Flag )
{
    Command++;

    while( *Command )
    {
        if ( *Command != *Flag || !*Flag )
            return false;
        Command++;
        Flag++;
    }

    return true;
}
/**
int[ in ]
 */
int COTexGetopt_long_only( int argc, char* argv[], struct COTexOption* long_options, int* index )
{
    COTexAssert(  argv );
    COTexAssert( *argv );
    COTexAssert( long_options );

    bool KeepGoing = true;
    if( *argv[ number ] == '-' )
    {
        while( KeepGoing == true && long_options->Command )
        {
            if ( CheckCommand( argv[ number ], long_options->Command ) )
            {
                KeepGoing = false;
                if ( index ) *index = number;

                switch( long_options->ArgumentAmount )
                {
                    case NO_ARGUMENTS :
                        if ( *long_options->flag )
                        {
                            *long_options->flag = long_options->value;
                            return 0;
                        }
                        else
                            return  long_options->value;

                    case REQUIRED_ARGUMENT :
                        if ( argc - 1 >= number )
                        {
                            COTexoptarg = argv[ number + 1 ];

                            if ( *long_options->flag )
                            {
                                *long_options->flag = long_options->value;
                                return 0;
                            }
                            else
                                return long_options->value;
                        }
                        else
                        {
                            fprintf( stderr, "error");//TODO add a message
                            return '?';
                        }

                    case OPTIONAL_ARGUMENT :
                        if ( argc - 2 >= number && *argv[ number + 1 ] != '-' )
                        {

                            COTexoptarg = argv[ number + 1 ]; //MENTOR - ask about

                            if ( long_options->flag )
                            {
                                *long_options->flag = long_options->value;
                                return 0;
                            }
                            else
                                return long_options->value;

                        }
                        else
                        {
                            return '?';
                        }

                    default :
                        fprintf( stderr, HRED "COTexGetopt switch failure" );
                        return -1;

                }

            }

            if( KeepGoing == true )
            {
                number++;
                long_options++;
            }
        }
    }
    else if ( number > argc - 1 )
        return -1;

    number++;
    return '?';
}
