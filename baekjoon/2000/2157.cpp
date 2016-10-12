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


const int MAX_N = 300;
const int MAX_M = MAX_N;
const int MAX_K = 100000;
int N, M, K;
int d[MAX_N + 1][MAX_M + 1];
vector< vector< pii > > adj;

int solve(int here, int count){
    // base case
    if(here == N - 1){
        if(count <= M)
            return 0;
        else
            return -INF;
    } 
    if(count > M) return -INF;

    int& ret = d[here][count];
    if(ret != -1) return ret;

    ret = -INF;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i].first;
        int cost = adj[here][i].second;
        ret = max(ret, solve(there, count + 1) + cost);
    }
    return ret;
}

int main(){
    freopen("2157.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d %d", &N, &M, &K);
    adj.resize(N);
    for(int u, v, w, i = 0; i < K; i++){
        scanf("%d %d %d", &u, &v, &w);
        if(u < v)
            adj[u - 1].push_back(make_pair(v - 1, w));
    }
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 1));
}