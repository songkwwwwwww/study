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
const int MOD = 10007;

/*

*/


const int MAX_N = 1000;
const int MAX_K = MAX_N;
int N, K;

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int d[MAX_N + 1][MAX_N + 1];
// nCr = n-1Cr + n-1Cr-1
// d[n][r] = d[n - 1][r] + d[n - 1][r - 1];
int main(){
    freopen("11051.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    

    for(int n = 0; n <= N; n++){
        d[n][0] = d[n][n] = 1;
        for(int r = 1; r <= n; r++){
            d[n][r] = d[n - 1][r] + d[n - 1][r - 1];
            d[n][r] %= MOD;
        }
    }
    printf("%d\n", d[N][K]);
}