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


const int MAX_N = 500;
const int MAX_K = 10000;
const int MAX_V = MAX_N * 2;

int N, K, V;

vi adj[MAX_V];
vi a_match, b_match;
vb visited;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;

    for(int i = 0; i < adj[a].size(); i++){
        int b = adj[a][i];
        if(b_match[b] == -1 || dfs(b_match[b])){
            a_match[a] = b;
            b_match[b] = a;
            return true;
        }
    }
    return false;
}

int bipartite_match(){
    a_match = vi(V, -1);
    b_match = vi(V, -1);
    int size = 0;
    for(int start = 0; start < N; start++){
        visited = vb(V);
        if(dfs(start))
            size++;
    }
    return size;
}

int main(){
    freopen("1867.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    V = N * 2;
    for(int i = 0; i < K; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v + N);
        adj[v + N].push_back(u);
    }
    printf("%d\n", bipartite_match());
}