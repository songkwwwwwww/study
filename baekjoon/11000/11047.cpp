#include <cstdio>

int main(){
    int N, K; // 1 <= N <= 10, 1 <= K <= 1,0000,0000
    int a[10];

    freopen("11047.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    int ans = 0;
    for(int i = N-1; i >= 0; i--){
        ans += K/a[i];
        K %= a[i];
    }
    printf("%d\n", ans);
}