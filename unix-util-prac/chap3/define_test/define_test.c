#include <stdio.h>
#include <stdlib.h>
#ifdef __WINDOWS__
#include <conio.h>
#endif

int main(){
#ifdef __linux__
    system("clear");
#elif __WINDOWS__
    system("cls");
#endif
    return 0;
}
