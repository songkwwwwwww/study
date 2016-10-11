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

const int dx[4] = {0, 1, 0, -1}; // E S, W, N;
const int dy[4] = {1, 0, -1, 0}; // E S, W, N;

const int INF = 987654321;

/*

*/


const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_K = 10;
int N, M, K;
int m[MAX_N + 3][MAX_M + 3];
int d[MAX_N + 3][MAX_M + 3][MAX_K + 3];


inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

int solve(int x, int y, int k){
    // base case
    if(x == N - 1 && y == M - 1){
        if(k >= K)
            return 0;
        else
            return INF;
    }
    if (k > 10) k = 10;
    
    int& ret = d[x][y][k];
    if(ret != -1) return ret;

    ret = INF;
    int here_val = abs(m[x][y]);
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny)){
            int there_val = abs(m[nx][ny]);
            int diff = abs(here_val - there_val);
            // 다음 칸에 생수통이 있을 경우, 즉 음수인 경우
            if(m[nx][ny] < 0){
                ret = min(ret, solve(nx, ny, k + 1) + diff);                 
            }
            // 다음 칸에 생수통이 없을 경우, 즉 양수인 경우
            else{
                ret = min(ret, solve(nx, ny, k) + diff);
            }
        }
    }

    return ret;
}

int main(){
    freopen("prob_id_18.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d %d", &M, &N, &K);
        N++; M++;

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                scanf("%d", &m[i][j]);

        memset(d, -1, sizeof(d));
        printf("Case #%d\n%d\n", tc, solve(0, 0, 0));
    }    
}

