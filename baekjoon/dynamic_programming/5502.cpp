#include <cstdio>


int dp[5001][5001];

int max(int a, int b){
	return (a > b) ? a : b;
}

int main(){
	freopen("5502.txt", "r", stdin);

	int n; // 3 <= n <= 5,000
	scanf("%d", &n);
	char* str = new char[n + 2];
	char* r_str = new char[n + 2];
	scanf("%s", str + 1);	
	str[n + 1] = '\0';

	// reverse str to get r_str
	for(int i = 1; i <= n; i++){
		r_str[i] = str[n + 1 - i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(str[i] == r_str[j])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max( dp[i][j-1], dp[i-1][j]  );
		}
	}
	int result = n - dp[n][n];// the length of string - LCS

	printf("%d\n", result);
}
