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

const int MAX_F = 100;
const int MAX_D = 100;
const int MAX_N = 100;
const int MAX_V = 402;


int main(){
    freopen("6241.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, F, D;
    scanf("%d %d %d", &N, &F, &D);
    int V = N * 2 + F + D + 2; // MAX_V = 402
    int S = V - 2;
    int T = V - 1;
    vi adj[V];
    vvi c(V, vi(V));
    vvi f(V, vi(V));
    // S -> dishes
    for(int i = 0; i < F; i++){
        c[S][N * 2 + i] = 1;
        adj[S].push_back(N * 2 + i);
        adj[N * 2 + i].push_back(S);
    }

    // drinks -> T
    for(int i = 0; i < D; i++){
        c[N * 2 + F + i][T] = 1;
        adj[N * 2 + F + i].push_back(T);
        adj[T].push_back(N * 2 + F + i);
    }

    // cow_i.a -> cow_i.b
    for(int i = 0; i < N; i++){
        c[i * 2][i * 2 + 1] = 1;
        adj[i * 2].push_back(i * 2 + 1);
        adj[i * 2 + 1].push_back(i * 2);
    }


    // cow_i
    // int V = N * 2 + F + D + 2;
    for(int i = 0; i < N; i++){
        int n, n_dishes, n_drinks;
        scanf("%d %d", &n_dishes, &n_drinks);
        // dishes -> cow_i.a 
        for(int j = 0; j < n_dishes; j++){
            scanf("%d", &n);
            c[N * 2 + n - 1][i * 2] = 1;
            adj[N * 2 + n - 1].push_back(i * 2);
            adj[i * 2].push_back(N * 2 + n - 1);
        }
        // cow_i.b -> drinks 
        for(int j = 0; j < n_drinks; j++){
            scanf("%d", &n);
            c[i * 2 + 1][N * 2 + F + n - 1] = 1;
            adj[i * 2 + 1].push_back(N * 2 + F + n - 1);
            adj[N * 2 + F + n - 1].push_back(i * 2 + 1);
        }
    }
    int total_flow = 0;
    while(true){
        vi prev(V, -1);
        qi q;
        q.push(S);
        while(!q.empty() && prev[T] == -1){
            int here = q.front(); q.pop();
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];

                if(c[here][there] - f[here][there] > 0 && prev[there] == -1){
                    q.push(there);
                    prev[there] = here;
                }
            }
        }
        if(prev[T] == -1) break;
        int flow = INF;

        for(int i = T; i != S; i = prev[i]){
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }
        for(int i = T; i != S; i = prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        total_flow += flow;
        
    }
    printf("%d\n", total_flow);
}