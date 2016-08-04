#include <cstdio>
#include <cstring>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int v[301]; // value for each stair
int n; // the # of stairs
int dp[301][2];
// dp[][0] : 1
// dp[][1] : 2


int main(){
	freopen("2579.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	dp[1][0] = v[1];

	dp[2][0] = v[1] + v[2];
	dp[2][1] = v[2];

	for(int i = 3; i <= n; i++){
		dp[i][0] = dp[i-1][1] + v[i];
		dp[i][1] = MAX( dp[i-2][0], dp[i-2][1] ) + v[i];
	}

	int result = MAX( dp[n][0], dp[n][1] );
	printf("%d", result );
}
