/*
    https://www.acmicpc.net/problem/11057
*/
#include <cstdio>

int N; // 1 <= N <= 1,000
int d[1001][10];

int main(){
    freopen("11057.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i <= 9; i++) d[1][i] = 1;
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                d[i][j] += d[i - 1][k];
            }
            d[i][j] %= 10007;
        }        
    }
    int sum = 0;
    for(int i = 0; i <= 9; i++) sum += d[N][i];
    sum %= 10007;
    printf("%d\n", sum);
}