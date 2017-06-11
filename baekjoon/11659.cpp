#include <stdio.h>

const int MAX_N = 100000;
const int MAX_M = 100000;
int N, M;

int a[MAX_N + 3];
int s[MAX_N + 3];

int main(){
    freopen("11659.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
	scanf("%d", &a[i]);
	s[i] = s[i - 1] + a[i];
    }
    for(int i = 0; i < M; i++){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", s[b] - s[a - 1]);
    }
}
