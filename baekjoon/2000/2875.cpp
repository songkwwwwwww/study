#include <cstdio>

int main(){
    freopen("2875.txt", "r", stdin);
    int W, M, K; // 0 <= W, M <= 100, 0 <= K <= W + M
    scanf("%d %d %d", &W, &M, &K);
    int ans = 0;
    while(W + M >= K + 3 && W >= 2 && M >= 1){
        W -= 2; 
        M--;
        ans++;
    }
    printf("%d\n", ans);
}