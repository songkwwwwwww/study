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

const int MAX_V = 1000;
const int MAX_E = 10000;


int main(){
    freopen("3640.txt", "r", stdin);
    int V, E;
    while(scanf("%d %d", &V, &E) == 2){
        int total_v = 2 * V;
        int S = 1, T = 2 * (V - 1);
        vi adj[total_v];
        vvi c(total_v, vi(total_v));
        vvi d(total_v, vi(total_v));
        vvi f(total_v, vi(total_v));
        for(int i = 0; i < 2 * V; i += 2){
            c[i][i + 1] = 1;
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        for(int u, v, cost, i = 0; i < E; i++){
            scanf("%d %d %d", &u, &v, &cost);
            u = (u - 1) * 2 + 1;
            v = (v - 1) * 2;
            c[u][v] = 1;
            d[u][v] = cost;
            d[v][u] = -cost;
            adj[u].push_back(v);
            adj[v].push_back(u);
            /*
            u = (u - 1) * 2;
            v = (v - 1) * 2;
            c[u + 1][v] = 1;
            d[u + 1][v] = cost;
            d[v + 1][u] = -cost;
            adj[u + 1].push_back(v);
            adj[v + 1].push_back(u);
            */
        }
        int counter = 0, result = 0, total_flow = 0;
        for(int k=0; k<2; k++){
           // if(counter == 2) break;
            qi q;
            q.push(S);
            vi prev(total_v, -1), dist(total_v, INF);
            vb in_q(total_v);
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
            total_flow++;
            counter++;
        }
        printf("%d\n", result);
    }
}