#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
 처리과정
 dp[n] : n번째 직사각형을 채우는 방법
 dp[n] = dp[n-1] +2dp[n-2]
*/
int cache[1001];
const int MOD = 10007;

int main(){
    freopen("11727.txt", "r", stdin);
    // tiling(width) = (2*tiling(width -2) + tiling(width -1)) % MOD;
	int n; // 1<= n <= 1000
	scanf("%d", &n);
	cache[1] = 1; cache[2] =3;
	for(int i = 3; i <= n; i++){
		cache[i] = (2*cache[i - 2] + cache[i - 1]) % MOD; 	
	}
	printf("%d\n", cache[n]);
	
	return 0;
}