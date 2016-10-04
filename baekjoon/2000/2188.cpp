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

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;


/*

*/

const int MAX_N = 200;
const int MAX_M = 200;
const int MAX_V = 200 * 2 + 2;

const int S = MAX_V - 2; // source
const int T = MAX_V - 1; // sink

int N, M;


int main(){
    freopen("2188.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    
    vvi c(MAX_V, vi(MAX_V));
    vvi f(MAX_V, vi(MAX_V));
    
    vector<int> adj[MAX_V];

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
        qi q;
        q.push(S);
        vi prev(MAX_V, -1);

        while(!q.empty()){
            int here = q.front(); q.pop();

            for(int i = 0; i < adj[here].size(); i++){
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