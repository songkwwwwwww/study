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

const int MAX_N = 400;
const int MAX_P = 10000;

int N, P;

int main(){
    freopen("2316.txt", "r", stdin);
    scanf("%d %d", &N, &P);
    
    VI adj[MAX_N * 2];
    VVI c(MAX_N * 2, VI(MAX_N * 2));
    VVI f(MAX_N * 2, VI(MAX_N * 2));
    
    for(int u, v, i = 0; i < N; i++){
        u = i * 2; v = i * 2 + 1;
        c[u][v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u, v, i = 0; i < P; i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        u = u * 2; v = v * 2;
        c[u + 1][v] = 1;
        c[v + 1][u] = 1;
        adj[u + 1].push_back(v);
        adj[v + 1].push_back(u);
    }
    int total = 0, S = 1, T = 2;
    while(true){
        QI q;
        q.push(S);
        VI prev(MAX_N * 2, -1);

        while(!q.empty()){
            int here = q.front(); q.pop();

            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];

                if(c[here][there] - f[here][there] > 0 && prev[there] == -1){
                    q.push(there);
                    prev[there] = here;
                    if(there == T) break;
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