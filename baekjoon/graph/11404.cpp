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
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*

*/

int V, E;
int adj[100][100];

int main(){
    freopen("11404.txt", "r", stdin);
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++){
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    
    for(int u, v, w, i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u - 1][v - 1] = min(adj[u - 1][v - 1], w);
    }

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}