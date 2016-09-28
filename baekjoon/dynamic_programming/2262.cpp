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
입력
첫째 줄에 자연수 n(1≤n≤256)이 주어진다. 
다음 줄에는 추첨 결과를 나타내는 n명의 선수들의 랭킹이 주어진다. 
각 선수의 랭킹은 1부터 n까지의 자연수로 나타나며, 랭킹이 같은 경우는 없다고 가정하자.

출력
첫째 줄에 답을 출력한다.
*/


const int MAX_N = 256;
int N;
vi rank;
vvi p_rank;

vvi d;
/*
    [start, end] 에서의 최소 랭킹 차이의 합
    = solve(start, mid) + solve(mid + 1, end) + 두 구간에서의 각각 가장 높은 랭킹끼리의 차이
*/
int solve(int start, int end){
    // base case
    if(start == end) return 0;


    int& ret = d[start][end];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = start; i < end; i++)
        ret = min(ret, 
            solve(start, i) + solve(i + 1, end) + abs(p_rank[start][i] - p_rank[i + 1][end]));

    return ret;
}

int main(){
    freopen("2262.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    rank.resize(N);
    p_rank = vvi(N, vi(N));
    d = vvi(N, vi(N, -1));

    for(int i = 0; i < N; i++)
        scanf("%d", &rank[i]);

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            p_rank[i][j] = rank[i];
            for(int k = i + 1; k <= j; k++){
                p_rank[i][j] = min(p_rank[i][j], rank[k]);
            }
        }
    }
    printf("%d\n", solve(0, N - 1));
}