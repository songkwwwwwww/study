#include <cstdio>
#include <cstring>

int max(int a, int b){
	return a > b ? a : b;
}

int n; // 1<= n <=500
int arr[500][500];
int dp[501][501];



// calc(y, x) = arr[y][x] + max( calc(y+1, x), calc(y+1, x+1) )
int calc(int y, int x){
	// base case
	if(y == n-1) return arr[y][x];
	int& ret = dp[y][x];
	if(ret != -1) return ret;
	return ret = arr[y][x] + max( calc(y + 1, x), calc(y + 1, x + 1) );
}

int main(){
	freopen("1932.txt", "r", stdin);
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			scanf("%d", &arr[i][j]);
		}		
	}
	printf("%d", calc(0, 0));
}


/*
//other people's code

#include <cstdio>
#include <algorithm>
 
int main()
{
 
  int i, j, N, M = 0, t[501] = {0}, dp[501] = {0};
 
  scanf("%d", &N);
  for(i = 1; i <= N; i++)
  {
 
    for(j = 1; j <= i; j++) scanf("%d", &t[j]);
    for(j--; j >= 1; j--) dp[j] = t[j] + std::max(dp[j], dp[j - 1]); 
 
  }
 
  while(i--) if(M < dp[i]) M = dp[i];
  printf("%d", M);
 
}

*/
