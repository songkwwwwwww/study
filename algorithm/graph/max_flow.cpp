// maximum_flow_problem
// https://en.wikipedia.org/wiki/Maximum_flow_problem 

// Edmonds–Karp algorithm
// O(VE^2)

// kks227님 코드
while(true){
    vector<int> prev(MAX_V, -1);
    queue<int> q;
    q.push(S);

    while(!q.empty()){
        int here = q.front(); q.pop();
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            if(c[here][there] - f[here][there] > 0 & prev[there] == -1){
                q.push(there);
                prev[there] = here;
                if(there == T)
                    break;
            }
        }
    }

    if(prev[T] == -1) break;

    int flow = INF;
    for(int i = T; i != S; i = prev[i]){
        flow = min(flow, c[prev[i][i] - f[prev[i]][i]);
    }
    for(int i = T; i != S; i = prev[i]){
        f[prev[i]][i] += flow;
        f[i][prev[i]] -= flow;
    }
    total_flow += flow;
}
