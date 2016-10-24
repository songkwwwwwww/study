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


const int MAX_N = 30;
const int MAX_M = 30;
int N, M; // (0 < N ≤ M < 30)
int d[MAX_N + 1][MAX_M + 1];

int main(){
    freopen("1010.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);


    //mCn = m-1Cn-1 + m-1Cn
    for(int n = 0; n <= MAX_N; n++){
        d[n][0] = d[n][n] = 1;
        for(int r = 1; r <= n; r++){
            d[n][r] = d[n - 1][r] + d[n - 1][r - 1];
        }
    }
    while(TC--){
        scanf("%d %d", &N, &M);
        printf("%d\n", d[M][N]);    
    }
}
