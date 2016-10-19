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

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MOD = 1000000000;
const int MAX_N = 200;
const int MAX_K = 200;
int N, K;
int d[MAX_N + 3][MAX_K + 3];

int solve(int sum, int k){
    // base case
    if(k == 0){
        if(sum == 0)
            return 1;
        else
            return 0;   
    }

    int& ret = d[sum][k];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i = sum; i >= 0; i--){
        ret += solve(sum - i, k - 1);
        ret %= MOD;
    }
    return ret;
}

int main(){
    freopen("2225.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(N, K));
}