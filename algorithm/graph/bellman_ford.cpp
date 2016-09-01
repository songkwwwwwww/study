/*
참조 :
    알고리즘 문제 해결 전략(종만북)
*/
/*
    O(|V||E|)

    실제 경로 계산하기

bellman_ford 알고리즘을 수행하는 과정에서 각 정점을 마지막으로 완화시킨 간선들을 모으면
스패닝 트리를 얻을 수 있다. 각 정점을 마지막으로 완화시킨 간선들은 항상 최단 경로 위에 있기 때문에,
각 정점에서부터 스패닝 트리의 루트인 시작점까지 거슬러 올라가는 경로는 항상 시작점에서 
해당 경로까지의 최단 경로이다. 
따라서 너비 우선 탐색이나 다익스트라 알고리즘과 비슷한 방식으로 
실제 정점의 목록을 계산할 수 있다.
*/

// 정점의 개수
int V;

// 그래프의 인접 리스트
// (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];

// 음수 사이클이 있을 경우 텅 빈 배열을 반환
vector<int> bellman_ford(int src){
    // 시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
    vector<int> upper(V, INF);

    upper[src] = 0;
    bool updated;
    // V번 순회한다.
    for(int iter = 0; iter < V; iter++){
        updated = false;
        for(int here = 0; here < V; here++){
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                // (here, there) 간선을 따라 완화를 시도한다.
                if(upper[there] > upper[here] + cost){
                    // 성공
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        // 모든 간선에 대해 완화가 실패했을 경우 |V|-1 번도 돌 필요 없이 곧장 종료.
        if(!updated) break;
    }
    // |V| 번 모두 업데이트가 되었다면 음수 사이클이 존재하므로 텅 빈 배열 반환.
    if(updated) upper.clear();
    return upper;
}