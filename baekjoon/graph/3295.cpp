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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 1000;
const int MAX_M = 50000;
int N, M;
vb visited;

vi adj[MAX_N * 2];
vi a_match, b_match;

int dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    
    for(int i = 0; i < adj[a].size(); i++){
        int b = adj[a][i];

        if(b_match[b] == -1 || dfs(b_match[b])){
            a_match[a] = b;
            b_match[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    freopen("3295.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        for(int u, v, i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            adj[u * 2].push_back(v * 2 + 1);
        }

        a_match = vi(N * 2, -1);
        b_match = vi(N * 2, -1);        
        int total_count = 0;
        for(int start = 0; start < N * 2; start += 2){
            visited = vb(2 * N, false);
            if(dfs(start))
                total_count++;
        }
        printf("%d\n", total_count);
        for(int i = 0; i < 2 * N; i += 2)
            adj[i].clear();
    }
}