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

const int dx[3] = {0, 0, 1}; // E W S;
const int dy[3] = {1, -1, 0}; // E W S;

const int INF = 987654321;

/*

*/


const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
int m[MAX_N][MAX_M];
int d[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int solve(int x, int y){
    if(x == N - 1 && y == M - 1) return m[N - 1][M - 1];
    visited[x][y] = true;
    
    int& ret = d[x][y];
    if(ret != -1) return ret; 

    ret = m[x][y];
    for(int i = 0; i < 3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && !visited[nx][ny]){
            ret = max(ret, solve(nx, ny) + m[x][y]);
        }
    }
    visited[x][y] = false;
    return ret;
}

int main(){
    freopen("2169.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &m[i][j]);
    
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0));
}