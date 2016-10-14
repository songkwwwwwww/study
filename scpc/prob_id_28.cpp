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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

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


const int MAX_N = 100000;
const int MAX_M = 500000;
const int MAX_K = MAX_N;


int main(){
    freopen("prob_id_28.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        vector< vector< pii > > adj; adj.resize(N + 1);
        vi prev(N + 1, -1);
        for(int u, v, w, i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        int S = 0;
        
        priority_queue< pii > pq;
        //pq.push(make_pair(0, S));
        vi dist(N + 1, INF);
        dist[S] = 0;

        for(int n, i = 0; i < K; i++){
            scanf("%d", &n);
            prev[n] = n;
            dist[n] = 0;
            //adj[S].push_back(make_pair(n, 0));
            pq.push(make_pair(0, n));
        }


        while(!pq.empty()){
            int here = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            if(dist[here] < cost) continue;

            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i].first;
                int next_cost = cost + adj[here][i].second;

                if(next_cost < dist[there]){
                    dist[there] = next_cost;
                    pq.push(make_pair(-next_cost, there));
                    prev[there] = prev[here];
                }
                else if(next_cost == dist[there] && prev[here] < prev[there]){
                    prev[there] = prev[here];
                    pq.push(make_pair(-next_cost, there));
                }
            }
        }
        int dist_sum = 0;
        int vertex_sum = 0;
        for(int i = 1; i <= N; i++){
            dist_sum += dist[i];
            vertex_sum += prev[i];
        }
        printf("Case #%d\n%d\n%d\n", tc, dist_sum, vertex_sum);
    }
}