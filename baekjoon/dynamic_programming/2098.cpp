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
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 도시의 수 N이 주어진다. (2<=N<=16) 
다음 N개의 줄에는 비용 행렬이 주어진다. 
각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다.
 W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.

항상 순회할 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 외판원의 순회에 필요한 최소 비용을 출력한다.
*/

const int IMPOSSIBLE = 987654321;

int N;
int W[16][16];
int d[16][1<<16];


int solve(int here, int visited){
    if(visited == (1 << N) - 1){
        if(W[here][0] != 0) return W[here][0];
        return IMPOSSIBLE;
    }
    int& ret = d[here][visited];
    if(ret != -1) return ret;

    ret = IMPOSSIBLE;
    for(int i = 0; i < N; i++){
        if(!(visited & (1 << i)) && W[here][i] != 0)
            ret = min(ret, solve(i, visited | (1 << i)) + W[here][i]);
    }
    return ret;
}

int main(){
    freopen("2098.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 1));
}