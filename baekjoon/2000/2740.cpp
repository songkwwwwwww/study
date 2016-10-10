#include <cstdio>

const int MAX_N = 100;
const int MAX_M = 100;



int main(){
    freopen("2740.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M, K;
    
    scanf("%d %d", &N, &M);
    int a[MAX_N][MAX_M];
    int b[MAX_N][MAX_M];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &a[i][j]);

    scanf("%d %d", &M, &K);    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            scanf("%d", &b[i][j]);

    int c[MAX_N][MAX_M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            c[i][j] = 0;
            for(int k = 0; k < M; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    
}