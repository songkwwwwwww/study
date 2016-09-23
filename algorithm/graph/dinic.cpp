/*
    kks227님 코드
*/
const int MAX_N;
const int MAX_V = MAX_N + 2;
const int S = MAX_V - 2;
const int T = MAX_V - 1;
const int INF = 987654321;

int N;
int c[MAX_V][MAX_V], f[MAX_V][MAX_V];
int level[MAX_V]; // 레벨 그래프에서 정점의 레벨(S가 0)
int work[MAX_V]; // dfs 중, 이 정점이 몇 번째 간선까지 탐색했는지 기억하는 용도
vi adj[MAX_V];

// 디닉 전용 bfs
bool dfs(){
    memset(level, -1, sizeof(level));
    level[S] = 0;

    qi q;
    q.push(S);
    while(!q.empty()){
        int here = q.front(); q.pop();
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            // 레벨 값이 설정되지 않았고, 간선에 residual이 있을 때만 이동
            if(level[there] == -1 && c[here][there] - f[here][there] > 0){
                level[there] = level[here] + 1;
                q.push(there);
            }
        }
    }
    // 싱크에 도달 가능하면 true, 아니면 false
    return level[T] != -1;
}

// 디닉 전용 dfs, here에서 dest로 최대 flow만큼의 유량을 보냄
int dfs(int here, int dest, int flow){
    // base case : dest에 도달함
    if(here == dest) return flow;

    // 현재 정점에서 인접한 정점들을 탐색
    // 이때, 이번 단계에서 이미 쓸모없다고 판단한 간선은 다시 볼 필요가 없으므로
    // work 배열로 간선 인덱스를 저장해 둔다
    for(int& i = work[here]; i < adj[here].size(); i++){
        int there = adj[here][i];
        // there의 레벨이 here보다 한단계 높고 (+1), 간선에 residual이 남아있어야만 이동
        // 결과적으로 경로상의 간선들 중 가장 작은 residual 이 됨
        int df = dfs(there, dest, min(c[here][there] - f[here][there], flow));
        // 증가 경로가 있다면, 유량을 df 만큼 흘리고 종료
        if(df > 0){
            f[here][there] += df;
            f[there][here] -= df;
            return df;
        }
    }
    // 증가 경로를 찾지 못함, 유량 0 흘림
    return 0;
}  


int main(){


    int total_flow = 0;
    // 레벨 그래프를 구축하여 싱크가 도달 가능한 동안 반복
    while(bfs()){
        memset(work, 0, sizeof(work));
        // 차단 유량 (blocking flow) 구하기
        while(true){
            int flow = dfs(S, T, INF); // dfs를 사용하여 각 경로를 찾음
            if(flow == 0) break; // 더 이상 경로가 없다면 종료
            total_flow += flow; // 총 유량에 현재 유량 더하기 
        }
    }

}


/*
    프로그래밍 콘테스트 챌린징
*/

// 변을 나타내는 구조체(방문처, 용량, 역변)
struct edge{
    int to, cap, rev;
};

vector<edge> adj[MAX_V]; // 그래프에 인접 리스트 표현
int level[MAX_V]; // s부터의 거리
int iter[MAX_V]; // 어디까지 조사해 볼지

// from에서 to로 향하는 용량 cap의 변을 그래프에 추가
void add_edge(int from, int to, int cap){
    adj[from].push_back((edge){to, cap, adj[to].size()});
    adj[to].push_back((edge){from, 0, adj[from].size() - 1});
}

// s로부터의 최단 거리를 bfs로 계산
void bfs(int s){
    memset(level, -1, sizeof(level));
    qi q;
    q.push(s);
    level[s] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        for(int i = 0; i < adj[here].size(); i++){
            edge& e = adj[here][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[here] + 1;
                q.push(e.to);
            }
        }
    }
}

// 증가 경로를 dfs로 탐색
int dfs(int here, int dest, int f){
    if(here == dest) return f;
    for(int& i = iter[here]; i < adj[here].size(); i++){
        edge& e = adj[here][i];
        if(e.cap > 0 && level[here] < level[e.to]){
            int d = dfs(e.to, dest, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                adj[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// s에서 t로의 최대 흐름을 구한다
int max_flow(int s, int t){
    int flow = 0;
    while(true){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0){
            flow += f;
        }
    }
}