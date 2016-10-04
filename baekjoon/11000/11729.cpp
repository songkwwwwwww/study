#include <stdio.h>

using namespace std;

int N; // 1 <= N <= 20


void solve(int n, int x, int y){
    if(n == 0) return;
    solve(n - 1, x, 6 - x - y);
    printf("%d %d\n", x, y);
    solve(n - 1, 6 - x - y, y);
}

int main(){
    freopen("11729.txt", "r", stdin);
    scanf("%d", &N);
    printf("%d\n", (1 << N) - 1);
    solve(N, 1, 3);
}
