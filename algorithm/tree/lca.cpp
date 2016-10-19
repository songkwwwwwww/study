/*
    프로그래밍 콘테스트 챌린징
*/
vector<int> adj[MAX_V];
int root;

// 부모를 2^k 회 찾아서 도달한 정점(루트를 지나친 경우에는 -1)
int parent[MAX_V][MAX_LOG_V]; 
int depth[MAX_V];

void dfs(int here, int p, int d){
    parent[here][0] = p;
    depth[here] = d;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        if(there != p)
            dfs(there, here, d + 1);
    }
}

void init(int V){
    // parent[0]과 depth를 초기화
    dfs(root, -1, 0);
    // parent를 초기화한다
    for(int k = 0; k + 1 < MAX_LOG_V; k++){
        for(int u = 0; u < V; u++){
            if(parent[u][k] < 0)
                parent[u][k + 1] = -1;
            else
                parent[u][k + 1] = parent[parent[u][k]][k];
        }
    }
}


// u와 v의 LCA를 구한다
int lca(int u, int v){
    // u와 v의 깊이가 같아질 때까지 부모를 찾는다
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < MAX_LOG_V; k++){
        if( (depth[v] - depth[u]) >> k & 1 ){
            v = parent[v][k];
        }
    }
    if(u == v) return u;

    // 이진 탐색으로 LCA를 구한다
    for(int k = MAX_LOG_V - 1; k >= 0; k--){
        if(parent[u][k] != parent[v][k]){
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    return parent[u][0];
}