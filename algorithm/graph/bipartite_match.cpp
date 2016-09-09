/*
참조 :
    알고리즘 문제 해결 전략(종만북)
*/

// A와 B의 정점 개수
int n, m;
// adj[i][j] A_i 와 B_i가 연결되어 있는가?
bool adj[MAX_N][MAX_M];
// 각 정점에 매칭된 상대 정점의 번호를 저장한다.
vector<int> a_match, b_match;
// dfs()의 방문 여부
vector<bool> visited;
// A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로를 찾는다.
bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < m; b++){
        if(adj[a][b]){
            if(b_match[b] == -1 || dfs(b_match[b])){
                // 증가 경로 발견. a와 b를 매칭시킨다.
                a_match[a] = b;
                b_match[b] = a;
                return true;
            }
        }
    }
    return false;
}

// a_match, b_match 배열을 계산하고 최대 매칭의 크기를 반환한다.
int bipartite_match(){
    // 처음에는 어떤 정점도 연결되어 있지 않다.
    a_match = vector<int>(n, -1);
    b_match = vector<int>(m, -1);
    int size = 0;
    for(int start = 0; start < n; start++){
        visited = vector<bool>(n, false);
        // dfs를 이영해 start에서 시작하는 증가 경로를 찾는다.
        if(dfs(start))
            ++size;
    }
    return size;
}