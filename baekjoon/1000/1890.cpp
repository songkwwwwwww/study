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

typedef vector<int> vi;
typedef vector<vi> vvi;

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


const int MAX_N = 100;
int N;
int m[MAX_N + 1][MAX_N + 1];
ll d[MAX_N + 1][MAX_N + 1];

ll solve(int x, int y){
    // base case
    if(x == N - 1 && y == N - 1) return 1;
    if(x >= N || y >= N || (m[x][y] == 0)) return 0;

    ll& ret = d[x][y];
    if(ret != -1) return ret;

    return ret = solve(x + m[x][y], y) + solve(x, y + m[x][y]); 
}

int main(){
    freopen("1890.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &m[i][j]);
    
    memset(d, -1, sizeof(d));
    printf("%lld\n", solve(0, 0));
}