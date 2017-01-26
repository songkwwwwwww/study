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


const int MAX_N = 14;
const int MAX_M = 14;
const int MOD = 9901;
int N, M;

int d[MAX_N + 1][MAX_M + 1][1 << MAX_M];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

int solve(int x, int y, int state){
    // base case
    if(x == N)
        return state == 0 ? 1 : 0;
    if(y == M)
        return solve(x + 1, 0, state);
    
    int& ret = d[x][y][state];
    if(ret != -1) return ret;

    ret = 0;
    if(y + 1 < M && !(state & 1) && !(state & 2) ){
        ret += solve(x, y + 2, state >> 2 );
        ret %= MOD;
    }
    if(y < M && !(state & 1)){
        ret += solve(x, y + 1, (state | 1 << M) >> 1);
        ret %= MOD;
    }
    if(state & 1){
        ret += solve(x, y + 1, state >> 1);
        ret %= MOD;
    }
    return ret;
}

int main(){
    freopen("1648.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    memset(d, -1, sizeof(d));
    int ans = solve(0, 0, 0);
    printf("%d\n", ans); 
}