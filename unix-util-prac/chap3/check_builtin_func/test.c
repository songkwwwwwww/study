//gcc -o test test.c -fdump-tree-all -da

#include <stdio.h>

int main(){
    char buffer[10];
    printf("test\n");
    printf("c");
    sprintf(buffer, "%s", "test");

    return 0;
}
