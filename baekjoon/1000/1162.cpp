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

const ll INF = numeric_limits<ll>::max();

/*

*/


const int MAX_N = 10000;
const int MAX_M = 50000;
const int MAX_K = 20;
int N, M, K;
// d[i][j] : 도시 개수 i, 포장 가능한 도로의 개수 j

int main(){
    freopen("1162.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d %d", &N, &M, &K);
    vector< vector<pii> > adj; adj.resize(N);
    for(int u, v, w, i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int S = 0, T = N - 1;
    // cost, vertex, count;
    priority_queue< pair<ll, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(S, K)));
    vvl dist(N, vl(K + 1, INF));
    dist[S][K] = 0;

    while(!pq.empty()){
        int here = pq.top().second.first;
        ll cost = -pq.top().first;
        int count = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            ll next_cost = cost + adj[here][i].second;

            if(count > 0 && cost < dist[there][count - 1]){
                dist[there][count - 1] = cost;
                pq.push(make_pair(-cost, make_pair(there, count - 1)));
            }

            if(next_cost < dist[there][count]){
                dist[there][count] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(there, count)));
            }
        }
    }
    
    ll ans = numeric_limits<ll>::max();
    for(int i = 0; i <= K; i++){
        ans = min(ans, dist[T][i]);
    }
    printf("%lld\n", ans);
}