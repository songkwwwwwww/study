
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
const int MAX_N = 300;
const int MAX_M = 5000;

int N, M;

int main(){
    freopen("5651.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        VI adj[N];
        VVI c(N, VI(N));
        VVI f(N, VI(N));
        for(int u, v, w, i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            c[u][v] += w;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int total_count = 0, S = 0, T = N - 1;
        while(true){
            QI q;
            q.push(S);
            VI prev(N, -1);
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

            if(prev[T] == -1)
                break;
            
            int flow = INF, count = 0;
            for(int residual, i = T; i != S; i = prev[i]){
                residual = c[prev[i]][i] - f[prev[i]][i];
                if(flow > residual){
                    flow = residual;
                    count = 1;
                }
                else if(flow == residual)
                    count++;
            }
            for(int i = T; i != S; i = prev[i]){
                f[prev[i]][i] += flow;
                f[i][prev[i]] -= flow;
            }
            total_count += count;
        }
        printf("%d\n", total_count);
    }
}