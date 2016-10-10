#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;

const int MAX_V = 10000;
const int MAX_E = 100000;
int V, E;
vi p;

int find(int a){
    if(p[a] < 0) return a;
    else return p[a] = find(p[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[b] = a;
}

int main(){
    freopen("1197.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &V, &E);
    vector< vector<pii> > adj; adj.resize(V);
    p = vi(V, -1);
    for(int i = 0; i < E; i++){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        A--; B--;
        adj[A].push_back(make_pair(B, C));
        adj[B].push_back(make_pair(A, C));
    }
    vector< pair< int , pair<int, int> > > edges;

    for(int u = 0; u < V; u++){
        for(int i = 0; i < adj[u].size(); i++){
            int there = adj[u][i].first;
            int cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, there)));
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(int i = 0; i < edges.size(); i++){
        int here = edges[i].second.first;
        int there = edges[i].second.second;
        int cost = edges[i].first;
        if(find(here) == find(there)) continue;

        merge(here, there);
        ans += cost;
    }
    printf("%d\n", ans);
}