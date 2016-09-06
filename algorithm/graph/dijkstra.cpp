/*
참조 :
    알고리즘 문제 해결 전략(종만북)
*/
/*
    다익스트라(Dijkstra) 알고리즘 :
단일 시작점 최단 경로 알고리즘.
시작 정점 s에서부터 다른 정점들까지의 최단 거리를 계산한다.
*/
/*
bfs와 유사한 형태를 가진 알고리즘으로 시작점에서 가까운 순서대로 정점을 방문한다.
일반 큐가 아닌 우선 순위큐를 사용한다.
*/

const int INF = numeric_limits<int>::max();
const int MAX_V = 10000;

// # 우선순위 큐를 사용하는 다익스트라 알고리즘
/*
O(|E|ln|V|)
*/
// 정점의 개수
int V;
// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src){
    vector<int> dist(V, INF);
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


// 우선순위 큐를 사용하지 않는 다익스트라 알고리즘
/*
정점의 수가 적거나 간선의 수가 매우 많은 경우에는 아예 우선순위 큐를 사용하지 않고
구현하는 방식이 더욱 빠른 경우가 있다.
이 방식에서는 다음에 방문할 정점을 별도의 큐에 보관하는 대신 매번 반복문을 이용해
방문하지 않은 정점 중 dist[]가 가장 작은 값을 찾는다.
O(|V|^2 + |E|)
*/

vector<int> dijkstra2(int src){
    vector<int> dist(V, INF);
    // 각 정점을 방문했는지 여부를 저장한다.
    vector<bool> visited(V, false);
    dist[src] = 0;
    while(true){
        // 아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
        int closest = INF, here;
        for(int i = 0; i < V; i++){
            if(dist[i] < closest && !visited[i]){
                here = i;
                closest = dist[i];
            }
        }
        if(closest == INF) break;
        // 가장 가까운 정점을 방문한다.
        visited[here] = true;
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            if(visited[there]) continue;
            int next_dist = dist[here] + adj[here][i].second;
            dist[there] = min(dist[there], next_dist);
        }
    }
    return dist;
}