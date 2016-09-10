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
//#include <unordered_map>

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

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫째 줄에 도시의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 100) 
둘째 줄부터 N개의 줄에 도시의 모양이 주어진다. 
비어있으면 점('.'), 벽은 '#', 도현이의 위치는 K, 학교의 위치는 H이다.

출력
첫째 줄에 도현이가 학교를 가지 못하게 하기 위해서 바꿔야 하는 벽의 최소 개수를 출력한다. 
만약, 벽을 아무리 세워도 학교에 가는 것을 막을 수 없다면 -1을 출력한다.
*/

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_V = 100 * 100 * 2;
int N, M;

struct Edge{
    int u, v, c, f;
    Edge():u(-1), v(-1), c(0), f(0) {}
    Edge(int nu, int nv, int nc): u(nu), v(nv), c(nc), f(0) {}
    int oppo(int node){
        return node == u ? v : u;
    }
    int spare(int node){
        return node == u ? c - f : f;
    }
    int add_flow(int node, int nf){
        if(node == u) f += nf;
        else f -= nf;
    }
};

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int main(){
    freopen("1420.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    int S, T;

    vector<Edge*> adj[MAX_V];
    
    char m[MAX_N][MAX_M];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %1c", &m[i][j]);
            if(m[i][j] == 'K'){
                S = (i * M + j) * 2 + 1;
            }
            else if(m[i][j] == 'H'){
                T = (i * M + j) * 2;
            }
        }
    }

    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(m[x][y] == '#') continue;
            if(m[x][y] == 'H'){
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(is_range(nx, ny) && m[nx][ny] == 'K'){
                        printf("-1\n");
                        return 0;
                    }
                }
            }
            int here_i = (x * M + y) * 2;
            int here_o = here_i + 1;
            
            Edge* edge = new Edge(here_i, here_o, 1);
            adj[here_i].push_back(edge);
            adj[here_o].push_back(edge);
 
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                int there_i = (nx * M + ny) * 2;
                int there_o = there_i + 1;
                if(is_range(nx, ny) && m[nx][ny] != '#'){
                    edge = new Edge(here_o, there_i, INF);
                    adj[here_o].push_back(edge);
                    adj[there_i].push_back(edge); 
                }
            }
        }
    }
    int total_flow = 0;

    while(true){
        qi q;
        q.push(S);
        vi prev(MAX_V, -1);
        Edge* edge[MAX_V];

        while(!q.empty() && prev[T] == -1){
            int here = q.front(); q.pop();

            for(int i = 0; i < adj[here].size(); i++){
                Edge* e = adj[here][i];
                int there = e->oppo(here);

                if(e->spare(here) && prev[there] == -1){
                    prev[there] = here;
                    edge[there] = e;
                    q.push(there);
                }
            }
        }
        
        if(prev[T] == -1) break;

        for(int i = T; i != S; i = prev[i]){
            edge[i]->add_flow(edge[i]->oppo(i), 1);
        }
        total_flow++;
    }
    printf("%d\n", total_flow);
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
    */
}