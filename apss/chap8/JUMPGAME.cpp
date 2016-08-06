/*
JUMPGAME
https://algospot.com/judge/problem/read/JUMPGAME
*/

#include <cstdio>
#include <cstring>
int n; // 2 <= n <= 100
int board[100][100];
int dp[100][100];

int jump(int y, int x){
	// base case: 
	if(y >= n || x >= n) return 0;
	// base case
	if(y == n - 1 && x == n - 1) return 1;
	
	int& ret = dp[y][x];
	if(ret != -1) return ret;
	int jump_size = board[y][x];
	return ret = ( jump(y + jump_size, x) || jump(y, x + jump_size) );
}

int main(){
	freopen("JUMPGAME.txt", "r", stdin);
	int TC; // TC <= 50
	scanf("%d", &TC);
	for(int i = 0; i < TC; i++){
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				scanf("%d", &board[j][k]);
			}
		}
		memset(dp, -1, sizeof(dp));
		if(jump(0, 0) == true) printf("YES\n");
		else printf("NO\n");
	}
}
