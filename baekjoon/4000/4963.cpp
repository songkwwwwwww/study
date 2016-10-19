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

const int dx[8] = {0, 0, 1, -1, -1, 1, 1, -1}; // E W S N;
const int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 50;
const int MAX_M = 50;
int N, M;
int m[MAX_N][MAX_M];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

void dfs(int x, int y, int c){
    m[x][y] = c;

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && m[nx][ny] == 1){
            dfs(nx, ny, c);
        }
    }
}

int main(){
    freopen("4963.txt", "r", stdin);
    //setbuf(stdout, NULL);
    while(scanf("%d %d", &M, &N) != EOF && N && M){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                scanf("%d", &m[i][j]);
        int c = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(m[i][j] == 1){
                    dfs(i, j, c + 2);
                    c++;
                }
        
        printf("%d\n", c);

    }
}