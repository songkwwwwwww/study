#include <stdio.h>
#include <iostream>
using namespace std;

int N, r, c; // N = 2 ^ k, k <= 15

int solve(int x, int y, int n){
    if(n == 1){
        return 0;
    }
    else{
        int m = n / 2;
        if( x < m ){
            if( y < m){
                return solve(x, y, m);
            }
            else{ // y >= m
                return m * m + solve(x, y-m, m);
            }
        }
        else{ // x >= m
            if( y < m){
                return m * m * 2 + solve(x-m, y, m);
            }
            else{ // y >= m
                return m * m * 3 + solve(x-m, y-m, m);
            }
        }
            
    }
}

int main(){
    freopen("1074.txt", "r", stdin);
    
    while(cin >> N >> r >> c){
        printf("%d\n", solve(r, c, 2 << N));
    }
}