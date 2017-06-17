#include <stdio.h>

const int MAX_N = 200000;
const int MAX_M = 100000;
int N, M;

bool a[MAX_N + 3];
int b[MAX_M + 3];
int c;
int d[MAX_N + 3];
int e;

int main(){
    freopen("13399.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
	int n;
	scanf("%d", &n);
	b[c++] = n;
    }
    for(int i = c - 1; i >= 0; i--){
	if(!a[b[i]]){
	    a[b[i]] = true;
	    printf("%d\n", b[i]);
	    d[e++] = b[i];
	}
    }
    for(int i = 1; i <= N; i++){
	if(!a[i]){
	    d[e++] = i;
	    printf("%d\n", i);
	}
    }
}
