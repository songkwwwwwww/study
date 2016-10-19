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


const int MAX_N = 50000;
int a[MAX_N + 3];
int d[MAX_N + 3][4];
int N, K;

// index부터 index + K - 1까지 싣을 수 있다.
int solve(int index, int k){
    // base case
    if(index >= N) return 0;

    int& ret = d[index][k];
    if(ret != -1) return ret;
    // 현재 화물을 패스하거나
    ret = solve(index + 1, k);

    // 화물을 적재할 수 있다면
    // 현재 화물부터 K개를 싣는다.
    if(k < 3){
        int sum = 0, i;
        for(i = index; i < index + K && i < N ; i++)
            sum += a[i];
        ret = max(ret, solve(i, k + 1) + sum);
    }
    return ret;
}

int main(){
    freopen("2616.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    scanf("%d", &K);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0));
}