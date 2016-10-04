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
N(2≤N≤40,000)개의 정점으로 이루어진 트리가 주어지고 M(M≤10,000)개의 두 노드 쌍을 입력받을 때 
두 노드 사이의 거리를 출력하라.

입력
첫째 줄에 노드의 개수 N이 입력되고 다음 N-1개의 줄에 트리 상에 연결된 두 점과 거리를 입력받는다. 
그 다음 줄에 거리를 알고 싶은 M개의 노드 쌍이 한 줄에 한 쌍씩 입력된다. 
두 점 사이의 거리는 10,000보다 작거나 같은 자연수이다.

정점은 1번부터 N번까지 번호가 매겨져 있다.

출력
M개의 줄에 차례대로 입력받은 두 노드 사이의 거리를 출력한다.
*/


const int MAX_N = 40000;
const int MAX_M = 10000;
const int MAX_LOG = 16;
int N, M;

vi h;
vvi par;
vector< vector< pair<int, int> > > adj;
vi dist;

void make_tree(int here){
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i].first;
        if(h[there] == -1){
            par[there][0] = here;
            h[there] = h[here] + 1;
            dist[there] = dist[here] + adj[here][i].second;
            make_tree(there);
        }
    }
}

int solve(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    int diff = h[u] - h[v];
    for(int i = 0; diff; i++){
        if(diff % 2) u = par[u][i];
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
    else{
        return u;
    }
}

int main(){
    freopen("1761.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    h = vi(N, -1);
    par = vvi(N, vi(MAX_LOG, -1));
    adj.resize(N);
    dist = vi(N, INF);
    for(int u, v, w, i = 0; i < N - 1; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    h[0] = 0;
    dist[0] = 0;
    make_tree(0);
    for(int j = 0; j < MAX_LOG - 1; j++)
        for(int i = 1; i < N; i++)
            if(par[i][j] != -1)
                par[i][j + 1] = par[par[i][j]][j];

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int u, v, o_u, o_v;
        scanf("%d %d", &u, &v);
        o_u = --u;
        o_v = --v;
        int lca = solve(u, v);
        printf("%d\n", dist[o_u] + dist[o_v] - 2 * dist[lca]);
    }
}