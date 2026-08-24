#ifndef TRIAL_COTEXUTILITY_H
#define TRIAL_COTEXUTILITY_H


void Thinking( char* Text, int time );
//TODO enhance assert
#define COTexAssert( a ) do {                                 \
        if ( !a ) {                                           \
            fprintf(stderr,                                   \
                    "Unfortunately, the code failed.\n"       \
                    "(NULL), function %s, file %s, line %d\n",\
                    __func__, __FILE__, __LINE__ );           \
            abort();                                          \
        }                                                     \
    } while ( 0 );

void PrintAIFunctions();

#endif // TRIAL_COTEXUTILITY_H
