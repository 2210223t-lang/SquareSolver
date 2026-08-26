#include <stdio.h>
// #include <string.h>

#include "../header/Colours.h"
#include "COTexAssert.h"

/**
 * @brief Argument amount constants for COTexGetopt
 */
enum ArgumentAmount{ NO_ARGUMENTS = 0, REQUIRED_ARGUMENT = 1, OPTIONAL_ARGUMENT = 2 };

static int number = 1; ///< Extern variable for COTexGetopt, which stores number of current argv element

/**
 * @brief Custom copy of a standart option command from getopt.h
 */
struct COTexOption
{
const char* Command;
int ArgumentAmount;
int* flag;
int value;
};

char* COTexoptarg; ///< Custom analogue of a standart optarg variable


/**
 * @brief Checks if inputted command corresponds a flag
 *
 * @param[ in ] Command char* Command is a inputted by user command
 *
 * @param[ in ] Flag const char* Flag flag from the programm's code
 *
 * @return False if Command don't correspondes Flag and true if correspondes
 */
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

int COTexGetopt_long_only( int argc, char* argv[], struct COTexOption* long_options, int* index )
{
    COTexAssert(  argv );
    COTexAssert( *argv );
    COTexAssert( long_options );

    if( number > argc - 1 )
        return -1;
    if( *argv[ number ] == '-' )
    {

        while( long_options->Command )
        {
            if ( CheckCommand( argv[ number ], long_options->Command ) )
            {
                if ( index ) *index = number;

                switch( long_options->ArgumentAmount )
                {
                    case NO_ARGUMENTS :
                        if ( long_options->flag )
                        {
                            number++;
                            *long_options->flag = long_options->value;
                            return 0;
                        }
                        else
                        {
                            number++;
                            return long_options->value;
                        }

                    case REQUIRED_ARGUMENT :
                        if ( argc - 1 >= number )
                        {
                            COTexoptarg = argv[ number + 1 ];

                            if ( *long_options->flag )
                            {
                                number++;
                                *long_options->flag = long_options->value;
                                return 0;
                            }
                            else
                            {
                                number++;
                                return long_options->value;
                            }
                        }
                        else
                        {
                            number++;
                            fprintf( stderr, "error");//TODO add a message
                            return '?';
                        }

                    case OPTIONAL_ARGUMENT :
                        if ( argc - 2 >= number && *argv[ number + 1 ] != '-' )
                        {

                            COTexoptarg = argv[ number + 1 ];

                            if ( long_options->flag )
                            {
                                number++;
                                *long_options->flag = long_options->value;
                                return 0;
                            }
                            else
                            {
                                number++;
                                return long_options->value;
                            }

                        }
                        else
                        {
                            number++;
                            return long_options->value;
                        }

                    default :
                        fprintf( stderr, HRED "COTexGetopt switch failure" );
                        number++;
                        return -1;

                }

            }
            long_options++;
        }
    }
    else if ( number > argc - 1 )
        return -1;
    number++;
    return '?';
}
