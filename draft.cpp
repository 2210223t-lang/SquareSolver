#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
    // char c[8] = "\e[1;33m";
    // while( ( c = getchar() ) != '\n' ) putchar(c);
    printf("\e[1;33m");
    putchar('a');
    printf(" \e[0m");
    // printf("\e[0m");
    return 0;
}
