#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "COTexUtility.h"
#include "../header/Colours.h"


void COTexWeather( void )
{
    srand( time( NULL ) );

    int flag = rand();
    int temp =  rand() / 53687091;

    switch( flag % 3 )
    {
        case 0 :
            PrintAI( "Rain is expected tomorrow, expected temperature is about ", HCYN );
            printf( "%d celsium degrees", temp );
            break;

        case 1 :
            PrintAI( "" )

    }
}
