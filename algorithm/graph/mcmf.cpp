/*
    kks227님 코드
*/

// c[MAX_V][MAX_V] : 각 간선의 용량
// d[MAX_V][MAX_V] : 각 간선의 비용
// f[MAX_V][MAX_V] : 각 간선에 흐르는 중인 유량

while(true){
    vi prev(MAX_V, -1), dist(MAX_V, INF);
    vb in_q(MAX_V);
    dist[S] = 0;
    in_q[S] = true;
    qi q;
    q.push(S);

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

    // 더 이상 경로가 없다면 종료
    if(prev[T] == -1) break;

    // 경로 상에서 가장 residual이 작은 간선을 찾아 최대 흘릴 수 있는 flow 찾음
    int flow = INF;

    for(int i = T; i != S; i = prev[i])
        flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
    
    for(int i = T; i != S; i = prev[i]){
        result += flow * d[prev[i]][i];
        f[prev[i]][i] += flow;
        f[i][prev[i]] -= flow;
    }
}


/*
    프로그래밍 콘테스트 챌린징
*/
// 벨만포드 사용





// 다익스트라 사용
typedef pair<int, int> pii; // first는 최단거리, second는 정점의 번호

// 변을 나타내는 구조체 (방문처, 용량, 비용, 역변)
struct edge{
    int to, cap, cost, rev;
};

int V; // 정점 수
vector<edge> adj[MAX_V];
int h[MAX_V]; // 포텐셜
int dist[MAX_V]; // 최단거리
int prev_v[MAX_V], prev_e[MAX_V]; // 직전의 정점과 변

// from 에서 to로 향하는 용량 cap, 비용 cost의 변을 그래프에 추가
void add_edge(int from, int to, int cap, int cost){
    adj[from].push_back((edge){to, cap, cost, adj[to].size()});
    adj[to].push_back((edge){from, 0, -cost, adj[from].size() - 1});
}

// s에서 t로의 유량 f의 최소 비용 흐름을 구한다
// 흘릴 수 없는 경우는 -1를 반환
/*
int min_cost_flow(int s, int t, int f){
    int res = 0;
    memset(h, 0, sizeof(h));
    while(f > 0){
        priority_queue< pii, vector<pii>, greater<pii> > pq;
        memset(dist, INF, sizeof(dist));
        dist[s] = 0;
        // 거리와 정점 순으로 넣는다
        pq.push(pii(0, s));
        while(!pq.empty()){
            int cost = pq.top().first;
            int here = pq.top().second;
            pq.pop();
            if(dist[here] < cost) continue;
            for(int i = 0; i < adj[here].size(); i++){
                edge& e = adj[here][i];
                if(dist[e.to] > dist[here] + e.cost + h[here] - h[e.to]){
                    dist[e.to] = dist[here] + e.cost + h[here] - h[e.to];
                    prev_v[e.to] = here;
                    prev_e[e.to] = i;
                    pq.push(pii(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == INF){
            // 이 이상은 흘릴 수 없다.
            return -1;
        }
        for(int v = 0; v < V; v++) h[v] += dist[v];

        // s-t 간 최단 경로로 힘껏 흘린다.
        int d = f;
        for(int i = t; i != s; i = prev_v[i])
            d = min(d, adj[prev_v[i]][prev_e[i]].cap);
        f -= d;
        res += d * dist[t];
        for(int i = t; i != s; i = prev_v[i]){
            edge& e = adj[prev_v[i]][prev_e[i]];
            e.cap -= d;
            adj[i][e.rev].cap += d;
        }
    } // end of while(f > 0)
    return res;
}*/

int min_cost_flow(int s, int t, int f){
    int res = 0;
    memset(h, 0, sizeof(h));
    while(f > 0){
        priority_queue< pii, vector<pii>, greater<pii> > pq;
        memset(dist, INF, sizeof(dist));
        dist[s] = 0;
        // 거리와 정점 순으로 넣는다
        pq.push(pii(0, s));
        while(!pq.empty()){
            int cost = pq.top().first;
            int here = pq.top().second;
            pq.pop();
            if(dist[here] < cost) continue;
            for(int i = 0; i < adj[here].size(); i++){
                edge& e = adj[here][i];
                if(dist[e.to] > dist[here] + e.cost + h[here] - h[e.to]){
                    dist[e.to] = dist[here] + e.cost + h[here] - h[e.to];
                    prev_v[e.to] = here;
                    prev_e[e.to] = i;
                    pq.push(pii(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == INF){
            // 이 이상은 흘릴 수 없다.
            return -1;
        }
        for(int v = 0; v < V; v++) h[v] += dist[v];

        // s-t 간 최단 경로로 힘껏 흘린다.
        int d = f;
        for(int i = t; i != s; i = prev_v[i])
            d = min(d, adj[prev_v[i]][prev_e[i]].cap);
        f -= d;
        res += d * dist[t];
        for(int i = t; i != s; i = prev_v[i]){
            edge& e = adj[prev_v[i]][prev_e[i]];
            e.cap -= d;
            adj[i][e.rev].cap += d;
        }
    } // end of while(f > 0)
    return res;
}
