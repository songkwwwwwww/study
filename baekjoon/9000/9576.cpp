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
const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
vvi adj;
vi a_match, b_match;
vb visited;

int dfs(int a){
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

int main(){
    freopen("9576.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        adj.resize(M);
        for(int i = 0; i < M; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            for(int j = a; j <= b; j++){
                adj[i].push_back(j - 1);
            }
        }
        int size = 0;
        a_match = vi(M, -1);
        b_match = vi(N, -1);
        for(int start = 0; start < M; start++){
            visited = vb(M);
            if(dfs(start))
                size++;
        }
        printf("%d\n", size);
        for(int i = 0; i < M; i++)
            adj[i].clear();
    }
}

/*

// adj[i][j] A_i 와 B_i가 연결되어 있는가?
bool adj[MAX_N][MAX_M];
// 각 정점에 매칭된 상대 정점의 번호를 저장한다.
vector<int> a_match, b_match;
// dfs()의 방문 여부
vector<bool> visited;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < N; b++){
        if(adj[a][b]){
            if(b_match[b] == -1 || dfs(b_match[b])){
                // 증가 경로 발견. a와 b를 매칭시킨다.
                a_match[a] = b;
                b_match[b] = a;
                return true;
            }
        }
    }
    return false;
}

// a_match, b_match 배열을 계산하고 최대 매칭의 크기를 반환한다.
int bipartite_match(){
    // 처음에는 어떤 정점도 연결되어 있지 않다.
    a_match = vector<int>(M, -1);
    b_match = vector<int>(N, -1);
    int size = 0;
    for(int start = 0; start < M; start++){
        visited = vector<bool>(M, false);
        // dfs를 이영해 start에서 시작하는 증가 경로를 찾는다.
        if(dfs(start))
            ++size;
    }
    return size;
}

int main(){
    freopen("9576.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        //VVI adj(M, VI(N));
        //VI adj[MAX_M];
        for(int a, b, i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            for(int iter = a; iter <= b; iter++){
                adj[i][iter-1] = true;
                //adj[i].push_back(iter);
            }
        }
        
        printf("%d\n", bipartite_match());        
        memset(adj, 0, sizeof(adj));
    }
}
*/


/*
const int MAX_N = 1000;
const int MAX_M = 1000;

int N, M;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w) {
  VI mr = VI(w.size(), -1);
  VI mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int main(){
    freopen("9576.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        VVI adj(M, VI(N));
        //VI adj[MAX_M];
        for(int a, b, i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            for(int iter = a; iter <= b; iter++){
                adj[i][iter-1] = 1;
                //adj[i].push_back(iter);
            }
        }
        
        printf("%d\n", BipartiteMatching(adj));        
    }
}
*/