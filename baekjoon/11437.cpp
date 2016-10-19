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

const int MAX_LOG_V = 17;
const int MAX_M = 10000;
const int MAX_V = 50000;
int M, V;

vector<int> adj[MAX_V];
int root;

// 부모를 2^k 회 찾아서 도달한 정점(루트를 지나친 경우에는 -1)
int parent[MAX_V][MAX_LOG_V]; 
int depth[MAX_V];

void dfs(int here, int p, int d){
    parent[here][0] = p;
    depth[here] = d;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        if(there != p)
            dfs(there, here, d + 1);
    }
}

void init(int V){
    // parent[0]과 depth를 초기화
    dfs(root, -1, 0);
    // parent를 초기화한다
    for(int k = 0; k + 1 < MAX_LOG_V; k++){
        for(int u = 0; u < V; u++){
            if(parent[u][k] < 0)
                parent[u][k + 1] = -1;
            else
                parent[u][k + 1] = parent[parent[u][k]][k];
        }
    }
}


// u와 v의 LCA를 구한다
int lca(int u, int v){
    // u와 v의 깊이가 같아질 때까지 부모를 찾는다
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < MAX_LOG_V; k++){
        if( (depth[v] - depth[u]) >> k & 1 ){
            v = parent[v][k];
        }
    }
    if(u == v) return u;

    // 이진 탐색으로 LCA를 구한다
    for(int k = MAX_LOG_V - 1; k >= 0; k--){
        if(parent[u][k] != parent[v][k]){
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    return parent[u][0];
}

int main(){
    freopen("11437.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &V);
    for(int u, v, i = 0; i < V - 1; i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    root = 0;
    memset(parent, -1, sizeof(parent));
    init(V);
    scanf("%d", &M);
    for(int u, v, i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u - 1, v - 1) + 1);
    }
}