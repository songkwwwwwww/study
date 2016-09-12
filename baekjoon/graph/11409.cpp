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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 400;
const int MAX_M = 400;

int main(){
    freopen("11409.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    int V = N + M + 2;
    vvi c(V, vi(V));
    vvi d(V, vi(V));
    vvi f(V, vi(V));
    vi adj[V];
    int S = V - 2;
    int T = V - 1;
    for(int i = 0; i < N; i++){
        c[S][i] = 1;
        adj[S].push_back(i);
        adj[i].push_back(S);        
    }
    for(int i = N; i < N + M; i++){
        c[i][T] = 1;
        adj[i].push_back(T);
        adj[T].push_back(i);        
    }

    for(int num_of_works, u = 0; u < N; u++){
        scanf("%d", &num_of_works);
        for(int v, cost, i = 0; i < num_of_works; i++){
            scanf("%d %d", &v, &cost);
            v = N + v - 1;
            c[u][v] = 1;
            d[u][v] = -cost;
            d[v][u] = cost;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
    }
    int total_flow = 0, result = 0;
    while(true){
        qi q;
        q.push(S);
        vi prev(V, -1), dist(V, INF);
        vb in_q(V);
        dist[S] = 0;
        in_q[S] = true;

        while(!q.empty()){
            int here = q.front(); q.pop();
            in_q[here] = false;
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];
                
                if(c[here][there] - f[here][there] > 0
                    && dist[there] > dist[here] + d[here][there]){
                    dist[there] = dist[here] + d[here][there];
                    prev[there] = here;
                    if(!in_q[there]){
                        q.push(there);
                        in_q[there] = true;
                    }
                }

            }
        }

        if(prev[T] == -1) break;

        for(int i = T; i != S; i = prev[i]){
            result += -d[prev[i]][i];
            f[prev[i]][i]++;
            f[i][prev[i]]--; 
        }
        total_flow++;
    }
    printf("%d\n%d\n", total_flow, result);
}