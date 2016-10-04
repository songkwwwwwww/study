#include <cstdio>
#include <vector>
#include <algorithm>


int mat_a[50][50], mat_b[50][50];

void flip(int x, int y){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            mat_a[x + i][y + j] ^= 1;
        }
    }
}


int main(){
    freopen("1080.txt", "r", stdin);
    int N, M; // 1 <= N, M <= 50
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &mat_a[i][j]);
            
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &mat_b[i][j]);
    
    int cnt = 0;
    for(int i = 0; i < N -2; i++){
        for(int j = 0; j < M - 2; j++){
            if(mat_a[i][j] != mat_b[i][j]){
                flip(i, j);
                cnt++;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat_a[i][j] != mat_b[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}