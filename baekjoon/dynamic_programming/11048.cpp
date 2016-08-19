/*

*/

#include <cstdio>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int N, M; // 1<= N, M <= 1000

int a[1001][1001];
int d[1001];



int main(){
    freopen("11048.txt", "r", stdin);
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            d[j] = MAX(d[j], d[j-1]) + a[i][j];
        }
    }
    printf("%d\n", d[M]);
}
/*
#include <cstdio>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int N, M; // 1<= N, M <= 1000

int a[1001][1001];
int d[1001][1001];



int main(){
    freopen("11048.txt", "r", stdin);
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            d[i][j] = MAX( MAX( d[i-1][j], d[i-1][j-1] ), d[i][j-1]) + a[i][j];
        }
    }
    printf("%d\n", d[N][M]);
}

*/