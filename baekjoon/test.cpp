#include <stdio.h>

typedef unsigned long long ull;

ull a, b;

int main(){
    freopen("14623.txt", "r", stdin);
    scanf("%llx %llx", &a, &b);
    printf("a : %lld\n", a);
    printf("b : %lld\n", b);
    ull c = a * b;
    printf("%llx", c);
}

