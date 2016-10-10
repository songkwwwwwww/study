#include <cstdio>

const int MAX_N = 100;
const int MAX_M = 100;



int main(){
    freopen("2738.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M;
    
    scanf("%d %d", &N, &M);
    int a[MAX_N][MAX_M];
    int b[MAX_N][MAX_M];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &b[i][j]);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
    
}