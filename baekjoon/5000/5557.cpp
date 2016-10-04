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

/*

*/


const int MAX_N = 100;
int N;
vi a;
vvl d;
ll solve(int cur, int sum){
    // base case
    if(cur == N - 2){
        if(sum == a[N - 1])
            return 1;
        else
            return 0;
    }

    ll& ret = d[cur][sum];
    if(ret != -1) return ret;

    ret = 0;
    if(sum + a[cur + 1] <= 20)
        ret += solve(cur + 1, sum + a[cur + 1]);
    if(sum - a[cur + 1] >= 0)
        ret += solve(cur + 1, sum - a[cur + 1]);
    return ret;        
}

int main(){
    freopen("5557.txt", "r", stdin);
    scanf("%d", &N);
    a = vi(N);
    d = vvl(N + 1, vl(21, -1));
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("%lld\n", solve(0, a[0]));
}