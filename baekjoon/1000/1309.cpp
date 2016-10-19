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

const int MOD = 9901;

const int MAX_N = 100000;
int N;
int d[MAX_N + 1][3];
inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int main(){
    freopen("1309.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    d[0][0] = d[0][1] = d[0][2] = 1;
    d[1][0] = d[1][1] = d[1][2] = 1;
    for(int i = 2; i <= N; i++){
        // 사자를 놓지 않을 경우
        d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % MOD;
        // 사자를 왼쪽에 놓을 경우
        d[i][1] = (d[i - 1][0] + d[i - 1][2]) % MOD;
        // 사자를 오른쪽에 놓을 경우
        d[i][2] = (d[i - 1][0] + d[i - 1][1]) % MOD;
    }
    printf("%d\n", (d[N][0] + d[N][1] + d[N][2]) % MOD);
}