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
const int MOD = 1000000007LL;

/*

*/

const int MAX_N = 1000000;
const int MAX_M = MAX_N;
int N, M;

ll factorials[MAX_N + MAX_M + 3];

ll pow_m(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int main(){
    freopen("prob_id_5.txt", "r", stdin);
    setbuf(stdout, NULL);
    factorials[1] = 1;
    for(int i = 2; i <= MAX_N + MAX_M + 2; i++)
        factorials[i] = (factorials[i - 1] * i) % MOD;
    
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d", &N, &M);
        ll A = factorials[N + M + 2];
        ll B = (factorials[N + 1] * factorials[M + 1]) % MOD;
        
        ll ans = ((A * pow_m(B, MOD - 2)) % MOD) - 1;

        printf("Case #%d\n%lld\n", tc, ans);
    }
}