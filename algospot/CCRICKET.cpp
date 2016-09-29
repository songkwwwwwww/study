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
int N, M, P1, P2, V;
int m[MAX_N][MAX_M];

vi a_match, b_match;
vb visited;
vvi adj;

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

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
    freopen("CCRICKET.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d %d", &N, &M, &P1, &P2);

        int total_tile = 0;
        V = N * M;
        vi even_vertex; even_vertex.reserve(V / 2);
        adj.resize(V);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf("%1d", &m[i][j]);
                // 해당 격자에 타일이 깨졌다면
                if(m[i][j] == 0){
                    // 짝수 인덱스의 정점을 가지는 타일
                    if( !((i + j) & 1) ){
                        even_vertex.push_back(i * M + j);
                    }
                    total_tile++;              
                }
            }
        }
        if(2 * P1 <= P2){
            printf("%d\n", total_tile * P1);
            continue;
        }
        
        for(int i = 0; i < even_vertex.size(); i++){
            int here = even_vertex[i];
            for(int d = 0; d < 4; d++){
                int nx = (here / M) + dx[d];
                int ny = (here % M) + dy[d];
                if(is_range(nx, ny) && m[nx][ny] == 0){
                    int there = nx * M + ny;
                    adj[here].push_back(there);
                    adj[there].push_back(there);
                }
            }
        }
        a_match = vi(V, -1);
        b_match = vi(V, -1);
        int count = 0;
        for(int i = 0; i < even_vertex.size(); i++){
            visited = vb(V);
            if(dfs(even_vertex[i]))
                count++;
        }
        printf("%d\n", (total_tile - 2 * count) * P1 + count * P2 );
        adj.clear();
    } // end of while
}