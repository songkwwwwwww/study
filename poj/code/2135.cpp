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


const int MAX_N = 1000;
const int MAX_M = 10000;
const int MAX_V = MAX_N + 2;

// 변을 나타내는 구조체 (방문처, 용량, 비용, 역변)
struct edge{
    int to, cap, cost, rev;
};

int N, M, V; // 정점 수
vector<edge> adj[MAX_V];
int dist[MAX_V]; // 최단거리
int prev_v[MAX_V], prev_e[MAX_V]; // 직전의 정점과 변

// from 에서 to로 향하는 용량 cap, 비용 cost의 변을 그래프에 추가
void add_edge(int from, int to, int cap, int cost){
    adj[from].push_back((edge){to, cap, cost, adj[to].size()});
    adj[to].push_back((edge){from, 0, -cost, adj[from].size() - 1});
}

int min_cost_flow(int s, int t){
    int res = 0;
    while(true){
        vb in_q(V);
        qi q;
        memset(prev_v, -1, sizeof(prev_v));
        memset(prev_e, -1, sizeof(prev_e));
        memset(dist, INF, sizeof(dist));
        dist[s] = 0;
        in_q[s] = true;
        q.push(s);

        while(!q.empty()){
            int here = q.front(); q.pop();
            in_q[here] = false;

            for(int i = 0; i < adj[here].size(); i++){
                printf("here : %d, i : %d\n", here, i);
                edge& e = adj[here][i];
                if(e.cap > 0 && dist[e.to] > dist[here] + e.cost){
                    printf(">\n");
                    dist[e.to] = dist[here] + e.cost;
                    prev_v[e.to] = here;
                    prev_e[e.to] = i;
                    if(!in_q[e.to]){
                        printf("hello\n");
                        q.push(e.to);
                        in_q[e.to] = true;
                    }
                }
            }
        }
        if(prev_v[t] == -1) break;

        int d = INF;
        for(int i = t; i != s; i = prev_v[i]){
            d = min(d, adj[prev_v[i]][prev_e[i]].cap);
        }
        //f -= d;
        //res += d * dist[t];
        for(int i = t; i != s; i = prev_v[i]){
            edge& e = adj[prev_v[i]][prev_e[i]];
            res += d * e.cost;
            e.cap -= d;
            adj[i][e.rev].cap += d;
        }
    } // end of while(f > 0)
    return res;
}


int main(){
    freopen("2135.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    int s = 0, t = N - 1;
    V = N;
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        printf("u : %d, v : %d, w : %d\n", u, v, w);
        add_edge(u, v, 1, w);
        //add_edge(v, u, 1, w);
    }
    printf("%d\n", min_cost_flow(s, t));
}