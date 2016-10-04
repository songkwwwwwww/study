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
입력
첫째 줄에는 정점 및 색깔의 개수 n(1≤n≤100,000)이 주어진다. 
다음 n-1개의 줄에는 각 줄에 두 개의 정수로 주어진 트리 상에서 연결되어 있는 두 정점의 번호가 주어진다.

출력
첫째 줄에 최소 비용을 출력한다.
*/


const int MAX_N = 100000;
int N;

//vvi adj;
//vvi d;
//vb visited;

vi adj[MAX_N];
int d[MAX_N][4];
bool visited[MAX_N];

int dfs(int here, int color){
    int& ret = d[here][color];
    if(ret != -1) return ret;
    
    visited[here] = true;
    ret = color;

    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        if(visited[there]) continue;
        int child = INF;

        for(int c = 0; c < 4; c++){
            if(c != color)
                child = min(child, dfs(there, c));
        }
        ret += child;
    }
    visited[here] = false;
    return ret;
}

int main(){
    freopen("1693.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    //adj.resize(N);
    for(int u, v, i = 0; i < N - 1; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int ans = INF;
    memset(d, -1, sizeof(d));
    //d = vvi(N, vi(5, -1));
    //visited = vb(N);
    for(int c = 0; c < 4; c++){
        ans = min(ans, dfs(0, c) + N);
    }
    printf("%d\n", ans);
}