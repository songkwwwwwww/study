#include <cstdio>

const int MOD = 1000000; // 10^6
const int MAX_N = 15 * 100000; // 15 * 10^k-1
int d[MAX_N + 1];

int main(){
    freopen("2749.txt", "r", stdin);
    //setbuf(stdout, NULL);
    
    //d[0] = 0;
    d[1] = 1;
    d[2] = 1;
    for(int i = 3; i <= MAX_N; i++){
        d[i] = (d[i - 1] + d[i - 2]) % MOD;
    }
    long long N;
    scanf("%lld", &N);
    printf("%d\n", d[N % MAX_N]);
}