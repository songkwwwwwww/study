#include <stdio.h>

const int MAX_N = 40;
int N, M;

int fibo[MAX_N + 3];


int main(){
    freopen("2302.txt", "r", stdin);
    fibo[0] = fibo[1] = 1; fibo[2] = 2;
    for(int i = 3; i <= MAX_N; i++){
	fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    scanf("%d %d", &N, &M);
    int s = 1, ans = 1;
    for(int i = 0; i < M; i++){
	int e;
	scanf("%d", &e);
	int gap = e - s;
	s = e + 1;
	ans *= fibo[gap];
    }
    int gap = N - s + 1;
    ans *= fibo[gap];
    printf("%d\n", ans);
}
