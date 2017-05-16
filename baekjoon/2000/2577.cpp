#include <stdio.h>

int count[10];
int A, B, C, D;

int main(){
    freopen("2577.txt", "r", stdin);
    scanf("%d %d %d", &A, &B, &C);
    D = A * B * C;
    while(D > 0){
	count[D % 10]++;
	D /= 10;
    }
    for(int i = 0; i < 10; i++){
	printf("%d\n", count[i]);
    }
}
