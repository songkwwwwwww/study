#include <stdio.h>

#define PRId32 "d"
#define PRIu64 "lu"

int main(){
    int x = 10;
    unsigned long y = 6000000000;

    printf("x = %" PRId32 ", y = %" PRIu64 "\n", x, y);
    // = printf("x = %d, y = %lu\n", x, y);
}
