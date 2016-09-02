/*
참조 :
    알고리즘 문제 해결 전략(종만북)
*/

// adj[u][v] = u 에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];

// via[u][v] = u 에서 v까지 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점
// -1로 초기화해 둔다.
int via[MAX_V][MAX_V];
// 플로이드의 모든 쌍 최단 거리 알고리즘
void floyd2(){
    for(int i = 0; i < V; i++) adj[i][j] = 0;
    memset(via, -1, sizeof(via));
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    via[i][j] = k;
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
}

// u 에서 v로 가는 최단 경로를 계산해 path에 저장한다.
void reconstruct(int u, int v, vector<int>& path){
    // base case
    if(via[u][v] == -1){
        path.push_back(u);
        if(u != v) path.push_back(v);
    }
    else{
        int w = via[u][v];
        reconstruct(u, w, path);
        path.pop_back();
        reconstruct(w, v, path); 
    }
}


/*
플로이드 알고리즘의 또 다른 유명한 사용 예로 가중치 없는 그래프에서 각 정점 간의
도달 가능성 여부를 계산하는 것이 있다.
모든 정점 쌍 u, v에 대해 u에서 v로 가는 경로가 있는지를 확인하는 것.
C_k(u, v)의 정의를 0번부터 k번 정점까지를 경유점으로 썼을 때,
u에서 v로 가는 경로가 있는지 여부를 나타내도록 변경한다. 그러면 다음과 같은 점화식이 성립
C_k(u, v) = C_k-1(u, v) || (C_k-1(u, k) && C_k-1(k, v))
*/