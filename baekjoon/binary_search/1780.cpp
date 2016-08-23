#include <stdio.h>

using namespace std;

int N; // 1 <= N <= 3^7, N=3^k

// index 0 = # of -1 
// index 1 = # of 0 
// index 2 = # of 1
int cnt[3];

int a[3000][3000];

bool same(int x, int y, int n){
    int val = a[x][y];
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(val != a[i][j]) return false;
        }
    }
    return true;
}

int solve(int x, int y, int n){
    if(same(x, y, n)){
        cnt[a[x][y] + 1]++;
        return 0;
    }

    int m = n/3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            solve(x + i*m, y + j*m, m);
}

int main(){
    freopen("1780.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    solve(0, 0, N);
    printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);
    return 0;
}