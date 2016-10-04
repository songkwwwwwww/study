/*
	https://www.acmicpc.net/problem/11052
*/

#include <cstdio>

#define MAX(a, b) (a) > (b) ? (a) : (b)

int N; // 1 <= N <= 1000
int p[1001];

// D[N] = max( p[i] + D[N - i] )
int d[1001];


/*
 처리과정
 dp[n] : n개 붕어빵을 파는 최대 수익
 dp[n] =  dp[n-1]+arr[1]
        , dp[n-2]+arr[2]
        , dp[n-3]+arr[3] ...
        , dp[n-n]+arr[n]
        의 최대값
*/
int main(){
	freopen("11052.txt", "r", stdin);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &p[i]);
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			d[i] = MAX(d[i], d[i - j] + p[j]);			
		}
	}
	
	printf("%d\n", d[N]);
}
