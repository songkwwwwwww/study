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

const int INF = 987654321;

/*

*/


const int MAX_N = 8;
const int MAX_M = 8;


int main(){
    freopen("1865.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC, N, M, W;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d", &N, &M, &W);
        vector<pii> adj[N];
        for(int i = 0; i < M; i++){
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            S--; E--;
            adj[S].push_back(pii(E, T));
            adj[E].push_back(pii(S, T));            
        }
        for(int i = 0; i < W; i++){
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            S--; E--;
            adj[S].push_back(pii(E, -T));
            //adj[E].push_back(pii(S, -T));  
        }
        bool minus_cycle = false;
        vi dist(N, INF);
        vb visited(N);
        for(int k = 0; k < N; k++){
            if(visited[k]) continue;
            visited[k] = true;
            dist[k] = 0;
            for(int l = 0; l < N; l++){
                for(int here = 0; here < N; here++){
                    for(int i = 0; i < adj[here].size(); i++){
                        int there = adj[here][i].first, d = adj[here][i].second;
                        if(dist[here] != INF && dist[there] > dist[here] + d){
                            dist[there] = dist[here] + d;
                            visited[there] = true;
                            if(l == N - 1) minus_cycle = true;
                        }
                    }
                }
            }
            if(minus_cycle) break;
        }
        if(minus_cycle) printf("YES\n");
        else printf("NO\n");
    }
}