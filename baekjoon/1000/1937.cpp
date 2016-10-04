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


const int MAX_N = 500;
int N;
int m[MAX_N][MAX_N];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}

int d[MAX_N][MAX_N];

int solve(int x, int y){
    int& ret = d[x][y];
    if(ret != -1) return ret;

    ret = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && m[x][y] < m[nx][ny]){
            ret = max(ret, 1 + solve(nx, ny));
        }
    }
    return ret;
}

int main(){
    freopen("1937.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &m[i][j]);
    
    int ans = 0;
    memset(d, -1, sizeof(d));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(d[i][j] == -1){
                ans = max(ans, solve(i, j));
            }
        }
    }
    printf("%d\n", ans);
}