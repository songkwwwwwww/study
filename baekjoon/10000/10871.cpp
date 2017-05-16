#include <stdio.h>

const int MAX_N = 10000;
const int MAX_X = 10000;
int N, X;

int main(){
    freopen("10871.txt", "r", stdin);
    scanf("%d %d", &N, &X);

    for(int i = 0; i < N; i++){
	int n;
	scanf("%d", &n);
	if(n < X)
	    printf("%d ", n);
    }
    printf("\n");
}
