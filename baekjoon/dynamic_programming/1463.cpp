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
 N번째 최소값이 되려면 N/3 , N/2 , N-1 의 값 최소값중에서 1을 더하면 된다.
 dp[n] = n을 1로 만드는데 최소 연산 횟수
*/
const int INFINITE = 0x7fffffff;

int cache[1000001];
// Memoization (Top Down):
// assume that a cache array is initialized to -1
int calc(int n) {
	// base case
	if (n == 1)	return 0;

	int& ret = cache[n];
	// is it cached?
	if (ret != -1) return ret;

	int result = INFINITE;
	if ((n % 3) == 0 ) 
		result = min(result, 1 + calc(n / 3));
	if ( (n % 2) == 0 ) 
		result = min(result, 1 + calc(n / 2));

	ret = min(result, 1 + calc(n - 1));
	return ret;
}
int main(){
    freopen("1463.txt", "r", stdin);
	int N;
	scanf("%d", &N);// 1 <= N <= 1,000,000
	memset(cache, -1, sizeof(cache));

	printf("%d\n", calc(N));
}