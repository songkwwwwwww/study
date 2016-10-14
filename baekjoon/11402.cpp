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



int main(){
    freopen("11402.txt", "r", stdin);
    //setbuf(stdout, NULL);
    ll N, K, M;
    scanf("%lld %lld %lld", &N, &K, &M);
    vvi d(M + 1, vi(M + 1));
    for(int i = 0; i <= M; i++){
        d[i][0] = d[i][i] = 1;
        d[i][1] = i;
        for(int j = 2; j <= i; j++){
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
            d[i][j] %= M;
        }
    }
    vi a, b;
    while(N > 0 || K > 0){
        a.push_back(N % M);
        b.push_back(K % M);
        N /= M;
        K /= M;
    }

    ll ans = 1;
    for(int i = 0; i < a.size(); i++){
        ans *= d[a[i]][b[i]];
        ans %= M;
    }
    printf("%lld\n", ans);
}