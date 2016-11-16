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


const int MAX_N = 100;
int N, C, D, d;
int X[MAX_N], Y[MAX_N];
int x_len, y_len;

int dp[MAX_N + 1][MAX_N + 1][2][2];
int solve(int x_i, int y_i, int x_prev, int y_prev){
    // base case
    if(x_i == x_len && y_i == y_len)
        return 0;
    
    int& ret = dp[x_i][y_i][x_prev][y_prev];
    if(ret != -1) return ret;

    ret = INF;

    // 두 팀 모두 훈련을 할 경우
    if(x_i < x_len && y_i < y_len){
        int cost = C;
        if(X[x_i] != Y[y_i])
            cost += C;
        
        ret = min(ret, solve(x_i + 1, y_i + 1, 0, 0) + cost);    
    }

    // X만 훈련을 할 경우
    if(x_i < x_len){
        int cost = C;

        // y는 쉰다
        // 전에도 쉬었다면
        if(y_prev == 1){ 
            cost += d;
        }
        // 처음 쉰다면
        else{
            cost += (D + d);
        }
        ret = min(ret, solve(x_i + 1, y_i, 0, 1) + cost);
    }

    // Y만 훈련을 할 경우
    if(y_i < y_len){
        int cost = C;
        // x는 쉰다
        // 전에도 쉬었다면
        if(x_prev == 1){ 
            cost += d;
        }
        // 처음 쉰다면
        else{
            cost += (D + d);
        }
        ret = min(ret, solve(x_i, y_i + 1, 1, 0) + cost);
    }
    
    // 둘다 쉴 경우
    int cost = d + d;
    // x가 처음 쉰다면
    if(x_prev == 0){
        cost += D;
    }
    // y가 처음 쉰다면
    if(y_prev == 0){
        cost += D;
    }
    ret = min(ret, solve(x_i, y_i, 1, 1) + cost);
    return ret;
}

int main(){
    freopen("9023.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC;
    scanf("%d", &TC);
    for(int n, tc = 1; tc <= TC; tc++){
        scanf("%d %d %d", &C, &D, &d);
        x_len = 0;
        while(scanf("%d", &n) && n != 0){
            X[x_len] = n;
            x_len++;
        }
        y_len = 0;
        while(scanf("%d", &n) && n != 0){
            Y[y_len] = n;
            y_len++;
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, 0);
        printf("%d\n", ans);
    }
}