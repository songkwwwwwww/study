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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;
const int MOD = 1000000;

/*
개근상을 받을 수 없는 사람은 지각을 두 번 이상 했거나, 결석을 세 번 연속으로 한 사람이다.
*/


const int MAX_N = 1000;
int N;
int d[MAX_N + 1][2][3];

int solve(int days, int L, int A){
    // base case
    if(days == N) return 1;

    int& ret = d[days][L][A];
    if(ret != -1) return ret;

    ret = 0;
    // 오늘 출석한 경우
    ret += solve(days + 1, L, 0);
    ret %= MOD;
    // 지각을 한 번도 안했다면 한 번까지는 할 수 있다.
    if(L < 1){
        ret += solve(days + 1, L + 1, 0);
        ret %= MOD;    
    }
    // 연속 결석을 0번이나 1번한 상태라면 한 번 더 할 수 있다.
    if(A < 2){
        ret += solve(days + 1, L, A + 1);
        ret %= MOD;
    }
    return ret;
}

int main(){
    freopen("1563.txt", "r", stdin);
    scanf("%d", &N);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0, 0));
}