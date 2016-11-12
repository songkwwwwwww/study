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


const ll MAX_N = 100;
const ll MAX_M = 100;
ll N, M;
ll d[MAX_N + 1][MAX_M + 1];

int main(){
    freopen("2407.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%lld %lld", &N, &M);

    //vvl d(N + 1, vl(M + 1));

    for(int n = 0; n <= N; n++){
        d[n][0] = d[n][n] = 1;
        for(int r = 1; r <= n; r++){
            d[n][r] = d[n - 1][r - 1] + d[n - 1][r];
        }
    }

    printf("%lld\n", d[N][M]);
}