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
첫째 줄에는 2개의 정수 N(1≤N≤1,000), M 이 있다. 
첫 번째 정수 N 은 가로등의 개수를 나타내는 정수이고, 
두 번째 정수 M 은 마징가 처음에 위치하는 가로등 번호이다. 
*/


const int MAX_N = 1000;
const int MAX_M = 8;
int N, M;

ll d[MAX_N][MAX_N][2];

ll D[MAX_N], W[MAX_N];
ll p_sum[MAX_N];

//vi D; // 가로등의 위치
//vi W; // 가로등의 전력 소비량
//vi p_sum; // 전력 소비량의 부분 합

// range : [i, j]
ll solve(int i, int j, bool is_left){
    // base case;
    if( (i == 0 && j == N - 1) || N == 1 )
        return 0;

    ll& ret = d[i][j][is_left];
    if(ret != -1) return ret;

    int pos = is_left ? i : j;
    ret = 0x7fffffff;
    // 오른쪽 가로등을 끈다
    if(j + 1 <= N - 1){
        ret = min(ret, 
            solve(i, j + 1, false) + (D[j + 1] - D[pos]) * (p_sum[N - 1] - p_sum[j] + p_sum[i - 1]));
    }
    // 왼쪽 가로등을 끈다
    if(0 <= i - 1){
        ret = min(ret, 
            solve(i - 1, j, true) + (D[pos] - D[i - 1]) * (p_sum[N - 1] - p_sum[j] + p_sum[i - 1]));
    }
    return ret;
}

int main(){
    freopen("2315.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    //D = vi(N);
    //W = vi(N);
    //p_sum = vi(N);
    
    scanf("%lld %lld", &D[0], &W[0]); 
    p_sum[0] = W[0];
    for(int i = 1; i < N; i++){
        scanf("%lld %lld", &D[i], &W[i]);
        p_sum[i] = p_sum[i - 1] + W[i];
    }
    memset(d, -1, sizeof(d));
    
    printf("%lld\n", solve(M - 1, M - 1, true));
}