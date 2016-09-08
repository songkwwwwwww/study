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
//#include <unordered_map>

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

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef queue<int> QI;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 200;
const int MAX_M = MAX_N * 2 + 2;
const int S = MAX_M - 2; // source
const int T = MAX_M - 1; // sink

int N, M;

int main(){
    freopen("2188.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    VVI c(MAX_M, VI(MAX_M));
    VVI f(MAX_M, VI(MAX_M));
    
    vector<int> adj[MAX_M];

    for(int n, v, u = 0; u < N; u++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            v = MAX_N + v - 1;

            c[u][v] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        c[S][u] = 1;
        adj[S].push_back(u);
        adj[u].push_back(S);
    }
    for(int u = MAX_N; u < MAX_N + M; u++){
        c[u][T] = 1;
        adj[u].push_back(T);
        adj[T].push_back(u);
    }

    int total = 0;
    while(true){
        QI q;
        q.push(S);
        VI prev(MAX_M, -1);

        while(!q.empty()){
            int here = q.front(); q.pop();

            for(int i; i < adj[here].size(); i++){
                int there = adj[here][i];

                if(c[here][there] - f[here][there] > 0 && prev[there] == -1){
                    q.push(there);
                    prev[there] = here;
                    if(there == T)
                        break;
                } 
            }
        }

        if(prev[T] == -1) break;

        
        for(int i = T; i != S; i = prev[i]){
            f[prev[i]][i]++;
            f[i][prev[i]]--;
        }
        total++;
    }
    printf("%d\n", total);
}