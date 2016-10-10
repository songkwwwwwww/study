#include <cstdio>

const int MAX_N = 300;
const int MAX_M = 300;
int d[MAX_N + 1][MAX_M + 1];

int main(){
    freopen("2167.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int a, N, M, K;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &a);
            d[i][j] = d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1] + a; 
        }
    }
    scanf("%d", &K);
    for(int k = 0; k < K; k++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1]);
    }

}