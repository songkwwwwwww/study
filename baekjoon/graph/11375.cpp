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

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
/*
vi adj[MAX_N];
vi a_match, b_match;
vector<bool> visited;
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
    a_match = vi(N, -1);
    b_match = vi(M, -1);
    int count = 0;
    for(int start = 0; start < N; start++){
        visited = vector<bool>(N, false);
        if(dfs(start))
            count++;
    }
    return count;
}
*/
bool FindMatch(int i, const vvi &w, vi &mr, vi &mc, vi &seen) {
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
 
int BipartiteMatching(const vvi &w) {
  vi mr = vi(w.size(), -1);
  vi mc = vi(w[0].size(), -1);
   
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    vi seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}
 

int main(){
    freopen("11375.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    vvi adj(N, vi(M));
    for(int num, v, u = 0; u < N; u++){
        scanf("%d", &num);
        for(int i = 0; i < num; i++){
            scanf("%d", &v);
            adj[u][v - 1] = 1;
            //adj[u].push_back(v-1);
        }
    }
    printf("%d\n", BipartiteMatching(adj));
    //printf("%d\n", bipartite_match());
}

/*

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
int N, M, match1[1000], match2[1000];
vector<int> adj[1000];
bool visited[1000];
 
bool DFS(int a){
    for(int b: adj[a]){
        if(visited[b]) continue;
        visited[b] = true;
        if(match2[b]==-1 || DFS(match2[b])){
            match1[a] = b;
            match2[b] = a;
            return true;
        }
    }
    return false;
}
 
int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int works;
        scanf("%d", &works);
        for(int j=0; j<works; j++){
            int oppo;
            scanf("%d", &oppo);
            adj[i].push_back(oppo-1);
        }
    }
    memset(match1, -1, sizeof(match1));
    memset(match2, -1, sizeof(match2));
    int result = 0;
    for(int i=0; i<N; i++){
        if(match1[i] == -1){
            memset(visited, 0, sizeof(visited));
            if(DFS(i)) result++;
        }
    }
    printf("%d\n", result);
}

*/