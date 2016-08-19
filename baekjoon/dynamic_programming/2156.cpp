/*
https://www.acmicpc.net/problem/2156
*/



#include <cstdio>

int n; // 1<= n <= 10,000

int a[10001];

// d[n] = max( d[n-1], d[n-2] + a[n], d[n-3] + a[n-1] + a[n] )
int d[10001];

int MAX(int a, int b){
    return a > b ? a : b;
}


int main(){
    freopen("2156.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    d[1] = a[1];
    d[2] = a[1] + a[2];
    d[3] = MAX(MAX(a[1] + a[2], a[1] + a[3]), a[2] + a[3]);
    for(int i = 4; i <= n; i++){
        d[i] = MAX( MAX(d[i-1], d[i-2] + a[i]), d[i-3] + a[i-1] + a[i]) ;
    }
    printf("%d\n", d[n]);
}


/*
#include <cstdio>

int n; // 1<= n <= 10,000

int a[10001];

// d[n] = max( d[n-1], d[n-2] + a[n], d[n-3] + a[n-1] + a[n] )
int d[10001][3];

int MAX(int a, int b){
    return a > b ? a : b;
}

int main(){
    freopen("2156.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    d[1][0] = 0;
    d[1][1] = a[1];
    d[1][2] = a[1];
    for(int i = 2; i <= n; i++){
        d[i][0] = MAX( MAX(d[i-1][0], d[i-1][1]), d[i-1][2] );
        d[i][1] = d[i-1][0] + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }
    printf("%d\n", d[n]);
}
*/