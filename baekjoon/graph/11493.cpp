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

*/

const int MAX_N = 500;
const int MAX_M = MAX_N * (MAX_N - 1) / 2;

int main(){
    freopen("11493.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        int N, M; // 정점의 개수, 간선의 개수
        scanf("%d %d", &N, &M);
        int V = N + 2;
        vi adj[V];
        vvi c(V, vi(V));
        vvi d(V, vi(V));
        vvi f(V, vi(V));
        int S = V - 2, T = V - 1;
        int n_black_coin = 0;
        for(int u, v, i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            u--; v--;
            c[u][v] = INF;
            d[u][v] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);            
        }
        for(int num, i = 0; i < N; i++){
            scanf("%d", &num);
            if(num == 0){ // black
                c[i][T] = 1;
                adj[i].push_back(T);
                adj[T].push_back(i);                
            }
        }
        for(int num, i = 0; i < N; i++){
            scanf("%d", &num);
            if(num == 0){ // has black coin 
                n_black_coin++;
                c[S][i] = 1;
                adj[S].push_back(i);
                adj[i].push_back(S);                
            }
        }
        int result = 0;
        for(int k = 0; k < n_black_coin; k++){
            qi q;
            q.push(S);
            vi prev(V, -1), dist(V, INF); 
            vb in_q(V);
            in_q[S] = true;
            dist[S] = 0;

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

            if(prev[T] == -1) break;

            for(int i = T; i != S; i = prev[i]){
                result += d[prev[i]][i];
                f[prev[i]][i]++;
                f[i][prev[i]]--;
            }
        }
        printf("%d\n", result);
    }
}