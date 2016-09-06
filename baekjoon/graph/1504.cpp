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

const int INF = 87654321;
const int MAX_V = 800;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*

*/

int V, E;

vector< pair<int, int> > adj[MAX_V];

vector<int> dijkstra(int src){
    vector<int> dist(V, INF);
    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = cost + adj[here][i].second;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    freopen("1504.txt", "r", stdin);
    scanf("%d %d", &V, &E);
    for(int u, v, w, i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u - 1].push_back(make_pair(v - 1, w));
        adj[v - 1].push_back(make_pair(u - 1, w));
    }
    int m1, m2;
    scanf("%d %d", &m1, &m2);
    m1--; m2--;
    // 1) 0 -> mid 1 -> mid 2 -> V - 1
    // 0 -> mid 1
    // + mid 1 -> mid 2
    // + mid 2 -> V - 1
    
    // 2) 0 -> mid 2 -> mid 1 -> V - 1
    // 0 -> mid 2
    // + mid 2 -> mid 1
    // + mid 1 -> V - 1
    vector<int> dist_from_zero = dijkstra(0);
    vector<int> dist_from_m1 = dijkstra(m1);
    vector<int> dist_from_m2 = dijkstra(m2);
    
    int distance1 = dist_from_zero[m1] + dist_from_m1[m2] + dist_from_m2[V-1];
    int distance2 = dist_from_zero[m2] + dist_from_m2[m1] + dist_from_m1[V-1];
    int result = MIN(distance1, distance2);
    if(result >= INF) printf("-1\n");
    else printf("%d\n", result);

}