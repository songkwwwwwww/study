/*
	https://www.acmicpc.net/problem/10844
*/

#include <cstdio>

#define MOD 1000000000
int N; // 1 <= N <= 100

int d[101][10]; 

int main(){
	freopen("10844.txt", "r", stdin);
	scanf("%d", &N);
	
	for(int i = 1; i <= 9; i++) d[1][i] = 1;
	for(int i = 2; i <= N; i++){
		for(int j = 0; j <= 9; j++){
			d[i][j] = 0;
			if(j - 1 >= 0) d[i][j] += d[i-1][j-1];
			if(j + 1 <= 9) d[i][j] += d[i-1][j+1];
			d[i][j] %= MOD;
		}		
	}

	long long ans = 0;
	for(int i = 0; i <= 9; i++) ans += d[N][i];
	ans %= MOD;
	printf("%lld\n", ans);
}
