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
const ll MOD = 1000000007;
/*

*/


const int MAX_N = 100;
const int MAX_L = 100;
const int MAX_R = 100;
int N, L, R;

ll d[MAX_N + 1][MAX_L + 1][MAX_R + 1];

/*
    d[N][L][R] : 빌딩 N개, 왼쪽에서 L개 보임, 오른쪽에서 R개 보이는 빌딩 배치의 개수
*/
ll solve(int n, int l, int r){
    if(n == 1)
        return (l == 1 && r == 1);
    
    ll& ret = d[n][l][r];
    if(ret != -1) return ret;

    ret = solve(n - 1, l, r) * (n - 2) + solve(n - 1, l - 1, r) + solve(n - 1, l, r - 1);
    
    return ret;
}

int main(){
    freopen("8895.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    memset(d, -1, sizeof(d));
    while(TC--){
        scanf("%d %d %d", &N, &L, &R);
        printf("%lld\n", solve(N, L, R));
    }
}