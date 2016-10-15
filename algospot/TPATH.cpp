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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

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


const int MAX_N = 2000;
const int MAX_M = 4000;
const int MAX_V = 1000;
int N, M;

//vector< vector< pii > > adj;
vector< pii > adj[MAX_N];

bool check(int lo, int hi){
    qi q;
    q.push(0);
    vb visited(N);
    visited[0] = true;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        if(here == N - 1) break;
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int v = adj[here][i].second;
            if(!visited[there] && lo <= v && v <= hi){
                q.push(there);
                visited[there] = true;
            }
        }
    }
    if(visited[N - 1]) return true;
    else return false;
}

int main(){
    freopen("TPATH.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        //adj.resize(N);
        vi weights; weights.reserve(M);
        for(int u, v, w, i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
            weights.push_back(w);
        }
        sort(weights.begin(), weights.end());
        weights.erase(unique(weights.begin(), weights.end()), weights.end());
        int ans = INF;
        for(int i = 0; i < weights.size(); i++){
            int l = i;
            int r = weights.size();
            while(l <= r){
                int m = (l + r) / 2;
                if(check(weights[i], weights[m])){
                    ans = min(ans, weights[m] - weights[i]);
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
        }
        printf("%d\n", ans);
        for(int i = 0; i < N; i++)
            adj[i].clear();
    }
}