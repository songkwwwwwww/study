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
//#include <unordered_map>

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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef queue<int> QI;

const int INF = 987654321;

/*

*/
const int MAX_V = 52;
VI adj[MAX_V];


int c_to_i(char ch){
    if('A' <= ch && ch <= 'Z')
        return ch - 'A';
    else if('a' <= ch && ch <= 'z')
        return ch - 'a' + 26;
    else 
        return -1;
}

int main(){
    freopen("6086.txt", "r", stdin);
    int N; scanf("%d", &N);

    VVI c(MAX_V, VI(MAX_V));
    VVI f(MAX_V, VI(MAX_V));

    for(int i = 0; i < N; i++){
        char u, v; int w, nu, nv;
        scanf(" %c %c %d", &u, &v, &w);
        nu = c_to_i(u);
        nv = c_to_i(v);
        c[nu][nv] += w;
        adj[nu].push_back(nv);
        adj[nv].push_back(nu);
    }

    int total = 0, S = c_to_i('A'), T = c_to_i('Z');

    while(true){
        VI prev(MAX_V, -1);
        QI q;
        q.push(S);

        while(!q.empty()){
            int here = q.front(); q.pop();
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];
                if(c[here][there] - f[here][there] > 0 && prev[there] == -1){
                    q.push(there);
                    prev[there] = here;
                    if(there == T) break;
                }
            }
        }
        if(prev[T] == -1) break;

        int flow = INF;
        for(int i = T; i != S; i = prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i = T; i != S; i = prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        total += flow;
    }
    printf("%d\n", total);    
}
/*

struct MaxFlow {
  int N;
  VVI cap, flow;
  VI dad, Q;

  MaxFlow(int N) :
    N(N), cap(N, VI(N)), flow(N, VI(N)), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    this->cap[from][to] += cap;
  }

  int BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), -1);
    dad[s] = -2;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < N; i++) {
        if (dad[i] == -1 && cap[x][i] - flow[x][i] > 0) {
          dad[i] = x;
          Q[tail++] = i;
        }
      }
    }

    if (dad[t] == -1) return 0;

    int totflow = 0;
    for (int i = 0; i < N; i++) {
      if (dad[i] == -1) continue;
      int amt = cap[i][t] - flow[i][t];
      for (int j = i; amt && j != s; j = dad[j])
        amt = min(amt, cap[dad[j]][j] - flow[dad[j]][j]);
      if (amt == 0) continue;
      flow[i][t] += amt;
      flow[t][i] -= amt;
      for (int j = i; j != s; j = dad[j]) {
        flow[dad[j]][j] += amt;
        flow[j][dad[j]] -= amt;
      }
      totflow += amt;
    }

    return totflow;
  }

  int GetMaxFlow(int source, int sink) {
    int totflow = 0;
    while (int flow = BlockingFlow(source, sink))
      totflow += flow;
    return totflow;
  }
};

int c_to_i(char ch){
    if('A' <= ch && ch <= 'Z')
        return ch - 'A';
    else if('a' <= ch && ch <= 'z')
        return ch - 'a' + 26;
    else 
        return -1;
}

int main(){
    freopen("6086.txt", "r", stdin);
    int N; scanf("%d", &N);
    MaxFlow mf(52);
    for(int i = 0; i < N; i++){
        char u, v; int w, nu, nv;
        scanf(" %c %c %d", &u, &v, &w);
        nu = c_to_i(u);
        nv = c_to_i(v);
        mf.AddEdge(nu, nv, w);
    }
    printf("%d\n", mf.GetMaxFlow(0, 25));
}
*/