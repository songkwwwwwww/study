#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*

*/

ll K;
ll d[90][2];
// cur : 현재 자리에서 1을 사용했는지 아닌지
ll pinary(int digits, bool cur){ 
    if(digits <= 1) return digits;
    ll& ret = d[digits][cur];
    if(ret != -1) return ret;

    ret = pinary(digits - 1, false);
    if(!cur) ret += pinary(digits - 1, true);
    return ret;
}

void skip(int digits, bool cur, long long k){
	printf("%d", cur);
	if(digits == 1) return;

	long long pivot = pinary(digits - 1, false);
    if(k < pivot) 
        skip(digits - 1, false, k);
	else // k >= pivot 
        skip(digits - 1, true, k - pivot);
}

int main(){
    freopen("2201.txt", "r", stdin);
    scanf("%lld", &K);
    memset(d, -1, sizeof(d));
    ll sum = 0;
    for(int i=1; ; i++){
		if(pinary(i, true) + sum >= K){
            skip(i, 1, K - sum - 1);
			break;
		}
		sum += pinary(i, true);
	}
}