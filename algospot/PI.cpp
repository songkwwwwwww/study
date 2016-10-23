#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

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

*/
const int INF = 987654321;
//char digits[10001];
string N;
int cache[10002];

// [begin, end)
int calculate(int begin, int end){
	string M = N.substr(begin, end - begin);
	//cout << "M : " << M << endl;
	// 첫 글자로만 이루어진 문자열이라면 난이도는 1
	if(M == string(M.size(), M[0])) return 1;

	// 등차수열인지 검사한다.
	bool progressive = true;
	for(int i = 0; i < M.size() - 1; i++){
		if(M[i + 1] - M[i] != M[1] - M[0]){
			progressive = false;
			break;
		}			
	}
	// 등차수열이고 공차가 1 혹은 -1이면 난이도는 2
	if(progressive && abs(M[1] - M[0]) == 1) 
		return 2;

	// 두 수가 번갈아 등장하는지 확인한다.
	bool alternating = true;
	for(int i = 0; i < M.size(); i++)
		if(M[i] != M[i % 2]){
			alternating = false;
			break;
		}

	if(alternating) return 4;
	if(progressive) return 5;
	return 10;
}

// digits[index] 에서 난이도 최소 합 반환.
int solve(int begin){
	// base case
	if(begin == N.size()) return 0;
	// memoizarion
	int& ret = cache[begin];
	if(ret != -1) return ret;
	ret = INF;
	for(int L = 3; L <= 5; L++)
		if(begin + L <= N.size())
			ret = min(ret, solve(begin + L) + calculate(begin, begin + L));
	return ret;
}

int main(){
    freopen("PI.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--){
		cin >> N;
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(0));
	}
}