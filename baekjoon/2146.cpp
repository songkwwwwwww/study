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
int N;
int m[MAX_N][MAX_N];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int dfs(int x, int y, int c){
    m[x][y] = c;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && m[nx][ny] == 1){
            dfs(nx, ny, c);
        }
    }
}

int main(){
    freopen("2146.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &m[i][j]);
    int c = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] == 1){
                dfs(i, j, c + 2);
                c++;
            }
        }
    }
    int ans = INF;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(m[x][y]){
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        if(m[i][j] && m[x][y] != m[i][j]){
                            ans = min(ans, abs(i - x) + abs(j - y) - 1);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}