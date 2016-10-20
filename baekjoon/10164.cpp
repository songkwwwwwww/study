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


const int MAX_N = 15;
const int MAX_M = 15;
const int MAX_K = MAX_N * MAX_M;
int N, M, K;
int d[MAX_N + 1][MAX_M + 1];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

int main(){
    freopen("10164.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d %d", &N, &M, &K);
    d[0][1] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            d[i][j] = d[i - 1][j] + d[i][j - 1];
        }
    }
    if(K){
        int x = (K - 1) / M + 1;
        int y = (K - 1) % M + 1;
        printf("%d\n", d[x][y] * d[N - x + 1][M - y + 1]);
    }
    else{
        printf("%d\n", d[N][M]);
    }
}