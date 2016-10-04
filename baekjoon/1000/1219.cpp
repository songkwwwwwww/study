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


const int MAX_N = 100;
const int MAX_M = 100;
int R[MAX_N][MAX_N];

int main(){
    freopen("1219.txt", "r", stdin);
    setbuf(stdout, NULL);
    int N, S, E, M;
    scanf("%d %d %d %d", &N, &S, &E, &M);
    vector< pair<int, ll> > adj[N];
    vi cities(N);
    for(int i = 0; i < M; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(pii(v, c));
        R[u][v] = 1;
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &cities[i]);
    }
    for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(R[i][k] && R[k][j]) R[i][j] = 1;

    bool minus_cycle = false;
    vector<ll> dist(N, INF);
    dist[S] = -cities[S];
    for(int l = 0; l < N; l++){
        for(int here = 0; here < N; here++){
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i].first;
                ll d = adj[here][i].second;
                if(dist[here] != INF && dist[there] > dist[here] + d- cities[there]){
                    dist[there] = dist[here] + d - cities[there];
                    if(l == N - 1 && R[there][E]) 
                        minus_cycle = true;
                }
            }
        }
    }

    if(minus_cycle)
        printf("Gee\n");
    else if(dist[E] == INF)
        printf("gg\n");
    else
        printf("%lld\n", -dist[E]); 
}
