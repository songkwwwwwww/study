#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
처리과정
 dp[n] = n번째 직사각형의 수
 dp[n] = dp[n-1] + dp[n-2]
*/
int cache[1001];
const int MOD = 10007;

int tiling(int width){
	if(width <= 1) return 1;
	int& ret = cache[width];;
	if(ret != -1) return ret;
	return ret = (tiling(width -2) + tiling(width -1)) % MOD;
}
	

int main() {
	freopen("11726.txt", "r", stdin);
    int n; // 1<= n <= 1000
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", tiling(n));
	
	return 0;
}