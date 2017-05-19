#include <stdio.h>

int main(){
    freopen("10707.txt", "r", stdin);

    int A, B, C, D, P;
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
    int cost_a = A * P;
    int cost_b = B;
    if(P > C){
	cost_b += ((P - C) * D );
    }
    printf("%d\n", cost_a < cost_b ? cost_a : cost_b);
}
