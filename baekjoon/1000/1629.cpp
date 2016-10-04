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
//#include <unordered_map> // c++11

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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 8;
const int MAX_M = 8;

int A, B, MOD;

ll solve(int n, int k){
    if(k == 0) return 1;

    ll temp = solve(n, k / 2) % MOD;
    ll ans = temp * temp % MOD;
    if(k % 2 == 1) ans = ans * n % MOD;
    return ans;
}

int main(){
    freopen("1629.txt", "r", stdin);
    scanf("%d %d %d", &A, &B, &MOD);
    printf("%lld\n", solve(A, B));
}