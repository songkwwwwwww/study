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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫 번째 줄에는 UCPC 구성원의 수 N(1≤N≤500)이 주어진다.
두 번째 줄에는 N개의 정수가 주어지는데, i번째 수가 1이면 i번 사람은 무조건 A진영에 들어가야 함을, 2라면 무조건 B진영에 들어가야 함을, 0이면 어느 진영에 들어가든지 상관 없다는 것을 의미한다.
세 번째 줄부터 N개의 줄에 걸쳐 i번 사람과 j번 사람이 다른 진영에 들어갈 때의 슬픔 정도 w[i, j]가 주어진다. (i+2)번째 줄에 j번째 수는 w[i, j]를 의미한다. 주어지는 입력은 항상 w[i, j]=w[j, i]를 만족하고, w[i, i]=0이다. w[i, j]는 1,000보다 크지 않은 음이 아닌 정수이다.

출력
첫 줄에 N명의 사람이 A, B 두 진영에 적절히 들어가 슬픈 정도의 합이 최소가 될 때의 슬픔 정도의 합을 출력한다.
두 번째 줄에는 슬픈 정도의 합이 최소가 될 때 A진영에 들어가는 사람들의 번호를 공백으로 구분하여 출력하고,
세 번째 줄에는 슬픈 정도의 합이 최소가 될 때 B진영에 들어가는 사람들의 번호를 공백으로 구분하여 출력한다.
만약 한 진영에 사람이 한 명도 들어가지 않은 경우 빈 줄을 출력한다. 가능한 경우가 여러 가지인 경우 그중 아무거나 하나 출력한다.
*/

const int MAX_N = 500;
const int MAX_V = MAX_N + 2;

int V, S, T;

vi level, work;
vvi c(MAX_V, vi(MAX_V)), f(MAX_V, vi(MAX_V));
//vvi c, f;
vi adj[MAX_V];

bool bfs(){
    level = vi(V, -1);
    level[S] = 0;

    qi q;
    q.push(S);
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];

            if(level[there] == -1 && c[here][there] - f[here][there] >0 ){
                level[there] = level[here] + 1;
                q.push(there);
            }
        }
    }
    return level[T] != -1;
}

int dfs(int here, int flow){
    if(here == T) return flow;

    for(int& i = work[here]; i < adj[here].size(); i++){
        int there = adj[here][i];

        if(level[there] == level[here] + 1 && c[here][there] - f[here][there] > 0){
            int df = dfs(there, min(flow, c[here][there] - f[here][there]));
            if(df > 0){
                f[here][there] += df;
                f[there][here] -= df;
                return df;
            }
        }
    }
    // 증가 경로를 찾지 못할 경우, 유량 0
    return 0;
}

int main(){
    freopen("13161.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    V = N + 2;
    S = V - 2, T = V - 1;
    for(int team, u = 0; u < N; u++){
        scanf("%d", &team);
        if(team == 1){
            c[S][u] = INF;
            adj[S].push_back(u);
            adj[u].push_back(S);
        }
        else if(team == 2){
            c[u][T] = INF;            
            adj[u].push_back(T);
            adj[T].push_back(u);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &c[i][j]);
            if(i != j) adj[i].push_back(j);
        }
    }
    int total_flow = 0;

    while(bfs()){
        work = vi(V, 0);
        while(true){
            int flow = dfs(S, INF);
            if(flow == 0) break;
            total_flow += flow;
        }
    }
    printf("%d\n", total_flow);

    qi q;
    q.push(S);
    vb visited(V);
    visited[S] = true;
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];

            if(!visited[there] && c[here][there] - f[here][there] > 0){
                q.push(there);
                visited[there]= true;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(visited[i]) printf("%d ", i + 1);
    }
    printf("\n");
    for(int i = 0; i < N; i++){
        if(!visited[i]) printf("%d ", i + 1);
    }
    printf("\n");
    
}