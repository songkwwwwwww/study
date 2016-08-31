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

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
const double INF = numeric_limits<double>::max();
const int MAX_V = 10000;
// # 우선순위 큐를 사용하는 다익스트라 알고리즘
/*
O(|E|ln|V|)
*/

// 정점의 개수
int V, E;
// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, double> > adj[MAX_V];

vector<double> dijkstra(int src){
    vector<double> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<double, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
        if(dist[here] < cost) continue;
        // 인접한 정점들을 모두 검사한다.
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            double next_dist = cost + adj[here][i].second;
            // 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}



int main(){
    freopen("ROUTING.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    int a, b;
    double c, d;
    while(TC--){
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; i++){
            scanf("%d %d %lf", &a, &b, &c);
            d = log(c);
            adj[a].push_back(make_pair(b, d));
        }
        vector<double> dist = dijkstra(0);
        double result = dist[V - 1];
        printf("%.10lf\n", exp(result));
        for(int i = 0; i < V; i++) adj[i].clear();
    }
}