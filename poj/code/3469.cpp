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
//#include <unordered_map> // c++11

#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 20000;
const int MAX_M = 200000;
const int MAX_V = MAX_N + 2;

int N, M;

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


int main(){
    freopen("3469.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    int s = N, t = N + 1;
    // a[i], b[i]
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(s, i, a);
        add_edge(i, t, b);        
    }
    for(int i = 0; i < M; i++){
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        add_edge(a - 1, b - 1, cost);
        add_edge(b - 1, a - 1, cost);
    }
    printf("%d\n", max_flow(s, t));
    return 0;
}