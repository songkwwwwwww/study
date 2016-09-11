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

const int MAX_N = 25;
int N;
int m[MAX_N][MAX_N];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}

int dfs(int x, int y, int c){
    m[x][y] = c;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(m[nx][ny] == 1 && is_range(nx, ny)){
            dfs(nx, ny, c);
        }
    }
}

int main(){
    freopen("2667.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%1d", &m[i][j]);
    int c = 2;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] == 1){
                dfs(i, j, c);
                c++;
            }
        }
    }
    vi v(c - 2);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] != 0)
                v[m[i][j] - 2]++;
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", (int)v.size());
    for(int i = 0; i < v.size(); i++)
        printf("%d\n", v[i]);
}