#include <stdio.h>

int main(){
    freopen("5554.txt", "r", stdin);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int e = a + b + c + d;
    printf("%d\n%d\n", e / 60 , e % 60);
}
