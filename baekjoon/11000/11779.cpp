#include <cstdio>
#include <vector>
#include <queue>

#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef queue<int> qi;

typedef pair<int, int> pii;

const int MAX_N = 1000;
const int MAX_M = 100000;
const int INF = 987654321;


int main(){
    freopen("11779.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M, S, E;    
    scanf("%d %d", &N, &M);
    vector< vector<pii> > adj; adj.resize(N);

    for(int u, v, w, i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u].push_back(make_pair(v, w));
    }
    scanf("%d %d", &S, &E);
    S--; E--;
    // cost, vertex
    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, S));

    vi dist(N, INF);
    dist[S] = 0;
    
    vi back_track(N, -1);
    
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        if(here == E) break;
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_cost = cost + adj[here][i].second;

            if(next_cost < dist[there]){
                dist[there] = next_cost;
                pq.push(make_pair(-next_cost, there));
                back_track[there] = here;
            }
        }
    }

    vi ans; ans.reserve(N);
    for(int i = E; i != -1; i = back_track[i]){
        ans.push_back(i);
    }
    printf("%d\n", dist[E]);
    printf("%d\n", (int)ans.size());
    
    for(int i = (int)ans.size() - 1; i >= 0; i--){
        printf("%d%c", ans[i] + 1, i == 0 ? '\n' : ' ');
    }
}