#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "COTexUtility.h"
#include "../header/Colours.h"


void COTexWeather( void )
{
    srand( ( unsigned ) time( NULL ) );

    int flag = rand();
    int temp =  abs ( rand() / 53687091 );

    switch( flag % 3 )
    {
        case 0 :
            PrintAI( "Rain is expected tomorrow, don't forget an umbrela. \nExpected temperature is about: ", HCYN );
            printf(  HCYN "%d", temp % 10 + 10 );
            PrintAI( "celsium degrees", HCYN );
            break;

        case 1 :
            PrintAI( "A draught is expected tomorrow, avoid spending too much time outside. \n"
                     "Expected temperature is about: ", HCYN );
            printf( HCYN "%d", temp %  20 + 20);
            PrintAI( "celsium degrees", HCYN );
            break;

        case 2 :
            PrintAI( "A storm warning has been issued for tomorrow.\n"
                     "Avoid windy areas and don't walk close to buildings\n", RED );
            break;

        default :
            fprintf( stderr, HRED " Error in working COTexweather module" reset );
            break;
    }
}
