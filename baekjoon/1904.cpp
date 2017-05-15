#include <stdio.h>


const int MAX_N = 1000000;
const int MOD = 15746;
int N;
int d[4];

int main(){
    freopen("1904.txt", "r", stdin);
    scanf("%d", &N);
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= N; i++){
	d[i % 3] = ( d[ (i - 1) % 3] + d[ (i - 2) % 3] ) % MOD;
    }
    printf("%d\n", d[N % 3]);
}
