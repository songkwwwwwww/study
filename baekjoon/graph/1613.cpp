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

const int INF = 987654321;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*

*/

const int MAX_V = 400;
const int MAX_E = 50000;

int V, E, S;

int adj[400][400];

int main(){
    freopen("1613.txt", "r", stdin);
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF; 
            //adj[i][j] = INF;

    for(int u, v, i = 0; i < E; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = 1;
    }
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    scanf("%d", &S);
    for(int s, e, i = 0; i < S; i++){
        scanf("%d %d", &s, &e);
        s--; e--;
        if(adj[s][e] == INF && adj[e][s] == INF) printf("0\n");
        else if(adj[s][e] != INF && adj[s][e] > 0) printf("-1\n");
        else if(adj[e][s] != INF && adj[e][s] > 0)printf("1\n");
    }
}