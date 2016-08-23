#include <stdio.h>

using namespace std;

int N; // 1<= N <=64

char a[64][65];

bool same(int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(a[x][y] != a[i][j]) return false;
        }
    }
    return true;
}


int solve(int x, int y, int n){
    if(same(x, y, n)){
        printf("%c", a[x][y]);
    }
    else{
        int m = n/2;
        printf("(");
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                solve(x + i * m, y + j * m, m);
            }
        }
        printf(")");
    }
}

int main(){
    freopen("1992.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", a[i]);
    /*
    for (int i=0; i < N; i++) {
       for (int j=0; j < N; j++) {
            scanf("%1d",&a[i][j]);
       }
    }*/
    solve(0, 0, N);
    printf("\n");
}