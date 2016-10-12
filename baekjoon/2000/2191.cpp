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


const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_S = 100;
const int MAX_V = 100;
int N, M, S, V;
vvi adj;
vi a_match, b_match;
vb visited;

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(int i = 0; i < adj[a].size(); i++){
        int b = adj[a][i];
        if(b_match[b] == -1 || dfs(b_match[b])){
            // 증가 경로 발견. a와 b를 매칭시킨다.
            a_match[a] = b;
            b_match[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    freopen("2191.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d %d %d", &N, &M, &S, &V);
    vector<pdd> mouse, cave;
    for(int i = 0; i < N; i++){
        double a, b;
        scanf("%lf %lf", &a, &b);
        mouse.push_back(make_pair(a, b));
    }

    for(int i = 0; i < M; i++){
        double a, b;
        scanf("%lf %lf", &a, &b);
        cave.push_back(make_pair(a, b));
    }
    int cnt = 0;
    adj.resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            double dist = sqrt((cave[j].first - mouse[i].first) * (cave[j].first - mouse[i].first)
                            + (cave[j].second - mouse[i].second) * (cave[j].second - mouse[i].second));
            if(dist <= (double)S * V){
                adj[i].push_back(j);
            }
        }
    }
    int size = 0;
    a_match = vector<int>(N, -1);
    b_match = vector<int>(M, -1);
    for(int start = 0; start < N; start++){
        visited = vector<bool>(N, false);
        // dfs를 이용해 start에서 시작하는 증가 경로를 찾는다.
        if(dfs(start))
            ++size;
    }
    printf("%d\n", N - size);
}