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


const int MAX_N = 20000;
const int MAX_M = 200000;
int N, M;
vvi adj;
vi color;

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int dfs(int here, int c){
    color[here] = c;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];

        if(color[there] == c) return false;
        
        if(color[there] == 0){
            if(!dfs(there, -c))
                return false;
        }
    }
    return true;
}

int main(){
    freopen("1707.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        adj.resize(N); 
        color = vi(N);
        for(int u, v, i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = true;        
        for(int i = 0; i < N; i++){
            if(color[i] == 0){
                if(!dfs(i, 1)){
                    flag = false;
                    break;
                }
            }
        }
        for(int i = 0; i < N; i++)
            adj[i].clear();
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}