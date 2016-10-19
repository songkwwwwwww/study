/*
    canalee90님 코드
*/
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


const int MAX_N = 500;
const int MAX_M = 10000;
int N, M;
int adj[MAX_N + 3][MAX_N + 3];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int delete_edge(vvi& parent, int there){
    for(int i = 0; i < parent[there].size(); i++){
        int here = parent[there][i];
        adj[here][there] = 0;
        delete_edge(parent, here);
    }
}

int dijkstra(int s, int t, vvi& parent){
    // cost, vertex
    priority_queue< pii > pq;
    pq.push(make_pair(0, s));
    vi dist(N, INF);
    dist[s] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for(int there = 0; there < N; there++){
            if(adj[here][there]){
                int next_cost = cost + adj[here][there];

                if(next_cost < dist[there]){
                    parent[there].clear();
                    parent[there].push_back(here);
                    dist[there] = next_cost;
                    pq.push(make_pair(-next_cost, there));
                }
                else if(next_cost == dist[there]){
                    parent[there].push_back(here);
                }
            }
        }
    }
    return dist[t];
}

int main(){
    freopen("5719.txt", "r", stdin);
    //setbuf(stdout, NULL);
    while(scanf("%d %d", &N, &M) != EOF && N && M){
        int S, T;
        scanf("%d %d", &S, &T);
        vvi parent; parent.resize(N);
        for(int u, v, w, i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            adj[u][v] = w;
        }
        dijkstra(S, T, parent);

        delete_edge(parent, T);

        int ans = dijkstra(S, T, parent);

        if(ans != INF) printf("%d\n", ans);
        else printf("-1\n");
        for(int i = 0; i < N; i++)
            parent[i].clear();
        memset(adj, 0, sizeof(adj));
    } // end of while

}