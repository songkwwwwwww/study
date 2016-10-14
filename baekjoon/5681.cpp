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


const int MAX_N = 1000;
int N;
int a[MAX_N + 3][MAX_N + 3];
bool c[MAX_N + 3][MAX_N + 3];
int d[MAX_N + 3][MAX_N + 3];


int solve(int x, int y){
    // base case
    if(x == N + 1) return 0;

    int& ret = d[x][y];
    if(c[x][y]) return ret;
    c[x][y] = true;

    // 현재 공을 고르거나 고르지 않는 경우
    ret = max(0, a[x][y]);

    for(int i = 0; i <= 1; i++){
        ret = max(ret, solve(x + 1, y + i) + a[x][y]);
    }

    return ret;
}

int main(){
    freopen("5681.txt", "r", stdin);
    //setbuf(stdout, NULL);
    while(scanf("%d", &N) != EOF && N){
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= i; j++)
                scanf("%d", &a[i][j]);
        
        int ans = max(0, solve(1, 1));
        printf("%d\n", ans);
        memset(c, false, sizeof(c));        
        memset(d, 0, sizeof(d));
    }
}