/*
https://www.acmicpc.net/problem/9465
*/

#include <cstdio>

//#define MAX(a, b) (a) > (b) ? (a) : (b)

int MAX(int a, int b){
	return a > b ? a : b;
}

int n; // 1<= n <= 100,000
int arr[2][100000];
int dp[2][100000];



int main(){
	freopen("9465.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for(int i = 0; i < TC; i++){
		scanf("%d", &n);
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < n; k++){
				scanf("%d", &arr[j][k]);
			}			
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		for(int j = 1; j < n; j++){
			dp[0][j] = MAX(dp[0][j - 1], dp[1][j - 1] + arr[0][j]);
			dp[1][j] = MAX(dp[1][j - 1], dp[0][j - 1] + arr[1][j]);
		}
		printf("%d\n", MAX(dp[0][n - 1], dp[1][n - 1]) );
	}
}
