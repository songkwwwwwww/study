#include <cstdio>
#include <iostream>
#include <algorithm>

int N, M; // 1 <= N, M <= 100,0000

int a[1000000];
int b[1000000];
int c[1000000];

int main(){
    freopen("11728.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    for(int i = 0; i < M; i++) scanf("%d", &b[i]);

    int i = 0, j = 0, cur = 0;
    while(i < N && j < M){
        if(a[i] <= b[j]){
            c[cur++] = a[i++];
        }
        else{
            c[cur++] = b[j++];
        }
    }
    
    while (i < N) c[cur++] = a[i++];
    while (j < M) c[cur++] = b[j++];

    for (int i = 0; i < N + M; i++) printf("%d ",c[i]);
    printf("\n");
}