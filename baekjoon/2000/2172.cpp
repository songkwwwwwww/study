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

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int INF = 987654321;

/*

*/


const int MAX_N = 20;
const int MAX_L = 20;
int N, L;
int m[MAX_N + 1][MAX_N + 1];
int d[MAX_L + 1][MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 1];


inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

// m[x1][y1] == m[x2][y2]
int solve(int len, int x1, int y1, int x2, int y2){
    // base case
    if(len == 1){
        if(x1 == x2 && y1 == y2) return 1;
        else return 0;
    }
    if(len == 2){
        int x_distance = abs(x2 - x1);
        int y_distance = abs(y2 - y1);
        if( (x_distance == 1 && y_distance == 0) ||
            (x_distance == 0 && y_distance == 1) ||
            (x_distance == 1 && y_distance == 1) )
            return 1;
        else return 0;
    }

    int& ret = d[len][x1][y1][x2][y2];
    if(ret != -1) return ret;
    ret = 0;

    for(int d = 0; d < 8; d++){
        int n_x1 = x1 + dx[d];
        int n_y1 = y1 + dy[d];
        if(is_range(n_x1, n_y1)){

            for(int d2 = 0; d2 < 8; d2++){
                int n_x2 = x2 + dx[d2];
                int n_y2 = y2 + dy[d2];
                if(is_range(n_x2, n_y2)){

                    if(m[n_x1][n_y1] == m[n_x2][n_y2]){
                        ret += solve(len - 2, n_x1, n_y1, n_x2, n_y2);
                    }
                }
            }
        }
    }
    return ret;
}


int main(){
    freopen("2172.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &m[i][j]);

    memset(d, -1, sizeof(d));
    int ans = 0;
    for(int x1 = 0; x1 < N; x1++){
        for(int y1 = 0; y1 < N; y1++){

            for(int x2 = 0; x2 < N; x2++){
                for(int y2 = 0; y2 < N; y2++){
                    if(m[x1][y1] == m[x2][y2]){
                        ans += solve(L, x1, y1, x2, y2);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}