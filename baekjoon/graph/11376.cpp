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
const int MAX_M = 1000;
int N, M;
vi adj[MAX_N * 2];

vi a_match, b_match;
vb visited;

// A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로를 찾는다.
bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(int i = 0; i < adj[a].size(); i++){
        int b = adj[a][i];
        //if(visited[b]) continue;
        if(b_match[b] == -1 || dfs(b_match[b])){
            // 증가 경로 발견. a와 b를 매칭시킨다.
            a_match[a] = b;
            b_match[b] = a;
            return true;
        }
        
    }
    return false;
}

// a_match, b_match 배열을 계산하고 최대 매칭의 크기를 반환한다.
int bipartite_match(){
    // 처음에는 어떤 정점도 연결되어 있지 않다.
    a_match = vector<int>(2 * N, -1);
    b_match = vector<int>(M, -1);
    int count = 0;
    for(int start = 0; start < 2 * N; start++){
        visited = vector<bool>(2 * N, false);
        // dfs를 이용해 start에서 시작하는 증가 경로를 찾는다.
        if(dfs(start))
            count++;
    }
    return count;
}

int main(){
    freopen("11376.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    
    for(int num, v, u = 0; u < N; u++){
        scanf("%d", &num);
        adj[u * 2].reserve(num);
        adj[u * 2 + 1].reserve(num);
        
        for(int i = 0; i < num; i++){
            scanf("%d", &v);
            adj[u * 2].push_back(v - 1);
            adj[u * 2 + 1].push_back(v - 1);
        }
    }
    printf("%d\n", bipartite_match());
}