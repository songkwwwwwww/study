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

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_V = MAX_N + MAX_M + 2;

int main(){
    freopen("11405.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    int V = N + M + 2;
    int S = V - 2;
    int T = V - 1; 
    vvi c(V, vi(V)); 
    vvi d(V, vi(V)); 
    vvi f(V, vi(V)); 
    vi adj[V];

    for(int i = M; i < M + N; i++){
        scanf("%d", &c[i][T]);
        adj[i].push_back(T);
        adj[T].push_back(i);
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &c[S][i]);
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
    for(int cost, i = 0; i < M; i++){
        for(int j = M; j < M + N; j++){
            scanf("%d", &cost);
            c[i][j] = INF;
            d[i][j] = cost;
            d[j][i] = -cost;                        
            adj[i].push_back(j);
            adj[j].push_back(i);            
        }
    }

    int result = 0;
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

        int flow = INF;

        for(int i = T; i != S; i = prev[i]){
            flow = min(flow, c[prev[i]][i] -f[prev[i]][i]);
        }

        for(int i = T; i != S; i = prev[i]){
            result += flow * d[prev[i]][i];
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
    }
    printf("%d\n", result);
}