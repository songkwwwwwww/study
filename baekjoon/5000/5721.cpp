#include <cstdio>
#include <cstring>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)

//int arr[100001];
//int dp[100001];


int main(){
	freopen("5721.txt", "r", stdin);
	int m, n;
	scanf("%d %d", &m, &n);
	while(m && n){
	//	memset(dp, -1, sizeof(dp));
		int arr[100001];
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &arr[i * n + j]);
			}
		}
		int dp[100001];
		memcpy(dp, arr, sizeof(arr));

		for(int i = 0; i < m; i++){ // all rows
			for(int j = 2; j < n; j++){
				dp[i * n + j] = MAX(dp[i * n + j-1], dp[i * n + j-2] + arr[i * n + j] );
			} 
		}

		for(int i = 2; i < m; i++){
			dp[(i * n) + n-1] = MAX(dp[(i-1) * n + n-1] , dp[(i-2) * n + n-1] + dp[(i * n) + n-1] );
		}

		printf("%d\n", dp[(m-1)*n + n-1]);
		scanf("%d %d", &m, &n);
	}
}


/*
int m, n; // 1<= m * n <= 10,000

int arr[10000];
int dp[10000];


int calc(int y, int x){
	// base case
	if(y >= m || x >= n) return 0;
	
	int& ret = dp[y * n + x];
	if(ret != -1) return ret;

	int result = arr[y * n + x];
	for(int j = x + 2; j < n; j++){
		result = MAX(result, arr[y * n + x] + calc(y, j));
	}


	for(int i = y + 2; i < m; i++){
		for(int j = 0; j < n; j++){
			result = MAX(result, arr[y * n + x] + calc(i, j));
		}
	}
	return ret = result;	
}

int my_func(){
	int result = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			result = MAX(result, calc(i, j));		
		}
	}
	return result;
}

int main(){
	freopen("5721.txt", "r", stdin);	
	scanf("%d %d", &m, &n);
	while(m && n){
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &arr[i * n + j]);
			}
		}
		printf("%d\n", my_func());
		scanf("%d %d", &m, &n);
	}
}

*/
