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

const int dx[2] = {0, 1}; // E S;
const int dy[2] = {1, 0}; // E S;

const int INF = 987654321;

/*

*/


const int MAX_N = 100;
const int MAX_M = 100;
int N, M, A, B;
int m[MAX_N + 3][MAX_M + 3];
inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

int d[MAX_N + 3][MAX_M + 3][MAX_N + MAX_M];
int solve(int x, int y, int k){
    // base case
    if(x == N - 1 && y == M - 1){
        if(k == A)
            return 1;
        else
            return 0;
    }

    int& ret = d[x][y][k];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && m[nx][ny] != 2){
            ret += solve(nx, ny, k + m[nx][ny]);
        }
    }
    return ret;
}

int main(){
    freopen("2411.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d %d %d", &N, &M, &A, &B);
    for(int x, y, i = 0; i < A; i++){
        scanf("%d %d", &x, &y);
        x--; y--;
        m[x][y] = 1;
    }
    for(int x, y, i = 0; i < B; i++){
        scanf("%d %d", &x, &y);
        x--; y--;
        m[x][y] = 2;
    }
    memset(d, -1, sizeof(d));
    int ans = solve(0, 0, 0);
    printf("%d\n", ans);
}