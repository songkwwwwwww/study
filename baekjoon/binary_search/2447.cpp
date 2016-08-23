#include <stdio.h>

#define BLANK 0
#define STAR 1
using namespace std;

int N; // N = 3 ^ k, 0 <= k < 8;
// 3 ^ 7 = 2187
char a[2187][2187];

int solve(int x, int y, int n, int color){
    int i, j, new_color;
    if(color == BLANK){
        for(int i = x; i < x + n; i++){
            for(int j = y; j < y + n; j++){
                a[i][j] = ' ';
            }
        }
    }
    else{ // color == STAR
        if(n == 1){
            a[x][y] = '*';
        }
        else{ // n >= 2
            new_color = STAR;
            int m = n / 3;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(i == 1 && j == 1)
                        new_color = BLANK;
                    else
                        new_color = STAR;
                    solve(x + i * m, y + j * m, m, new_color);
                }
            }
        }
    }
}

int main(){
    freopen("2447.txt", "r", stdin);
    scanf("%d", &N);
    
    solve(0, 0, N, STAR);
    for(int i = 0; i < N; i++)
        a[i][N] = '\0';

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
        //printf("%s\n", a[i]);
    return 0;
}