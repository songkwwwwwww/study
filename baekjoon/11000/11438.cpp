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
문제
N(2 ≤ N ≤ 100,000)개의 정점으로 이루어진 트리가 주어진다. 
트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.

두 노드의 쌍 M(1 ≤ M ≤ 100,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.

입력
첫째 줄에 노드의 개수 N이 주어지고, 다음 N-1개 줄에는 트리 상에서 연결된 두 정점이 주어진다. 
그 다음 줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 주어지고, 다음 M개 줄에는 정점 쌍이 주어진다.

출력
M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 공통 조상을 출력한다.
*/


const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_LOG = 20;

int N, M;

// Preprocess:
//int par[MAX_N][MAX_LOG]; // initially all -1
vvi par;
vi h;
vvi adj;
/*
void dfs(int here, int p = -1){
	par[here][0] = p;
	if(p != -1)
		h[here] = h[p] + 1;
	for(int i = 1; i < MAX_LOG; i++)
		if(par[here][i - 1] != -1)
			par[here][i] = par[par[here][i-1]][i-1];
	for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        if(p - there)
		    dfs(there, here);
    }
}

// Query:
int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAX_LOG - 1; i >= 0; i --)
		if(par[v][i] + 1 && h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = MAX_LOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i]){
			v = par[v][i];
            u = par[u][i];
        }
	return par[v][0];
}
*/

void make_tree(int here){
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        if(h[there] == -1){
            par[there][0] = here;
            h[there] = h[here] + 1;
            make_tree(there);
        }
    }
}

int solve(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int diff = h[u] - h[v];
    
    for(int i = 0; diff; i++){
        if(diff % 2)
            u = par[u][i];
        diff /= 2;
    }

    if(u != v){
        for(int i = MAX_LOG - 1; i >= 0; i--){
            if(par[u][i] != -1 && par[u][i] != par[v][i]){
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    }
    else{ // u == v
        return u;
    }
}

int main(){
    freopen("11438.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    adj.resize(N);
    par = vvi(N, vi(MAX_LOG, -1));
    h = vi(N, -1);
    h[0] = 0;
    //h.resize(N);
    for(int u, v, i = 0; i < N - 1; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    //dfs(0);
    make_tree(0);
    for(int j = 0; j < MAX_LOG - 1; j++)
        for(int i = 1; i < N; i++)
            if(par[i][j] != -1)
                par[i][j + 1] = par[par[i][j]][j];

    
    scanf("%d", &M);
    for(int u, v, i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        //printf("%d\n", LCA(u - 1, v - 1) + 1);
        printf("%d\n", solve(u - 1, v - 1) + 1);        
    }
}