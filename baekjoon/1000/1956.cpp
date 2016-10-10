#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

const int INF = 400;

const int MAX_V = 400;
const int MAX_E = MAX_V * (MAX_V - 1);


int main(){
    freopen("1956.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int V, E;
    scanf("%d %d", &V, &E);
    vvi adj(V, vi(V, INF));
    
    for(int u, v, w, i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u][v] = w;
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                    if(adj[i][j] > adj[i][k] + adj[k][j]){
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < V; i++) {
        if (adj[i][i] != 0){
            ans = min(ans, adj[i][i]);
        }
    }
    printf("%d\n",ans == INF ? -1 : ans);
}