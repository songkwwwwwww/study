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
const int INF = 0x7fffffff;
const int MAX_V = 1002;

// 화재 장소의 수 n
// 소방서의 수 m
// 1 <= n, 1 <= m, n + m <= V
int V, E, n, m;

// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src){
    vector<int> dist(V + 1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
        if(dist[here] < cost) continue;
        // 인접한 정점들을 모두 검사한다.
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = cost + adj[here][i].second;
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
    freopen("FIRETRUCKS.txt", "r", stdin);
    int TC, a, b, c; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d %d", &V, &E, &n, &m);
        for(int i = 0; i < E; i++){
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        
        vector<int> fire_house(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &fire_house[i]);

        V++;
        for(int i = 0; i < m; i++){
            int num;
            scanf("%d", &num);
            adj[V].push_back(make_pair(num, 0));
        }

        vector<int> dist = dijkstra(V);
        int result = 0;
        for(int i = 0; i < fire_house.size(); i++)
            result += dist[fire_house[i]];
        printf("%d\n", result);

        for(int i = 1; i <= V; i++)
            adj[i].clear();
        
    }
}