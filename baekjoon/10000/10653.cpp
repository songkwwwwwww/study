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
문제
농장에 있는 젖소들이 건강하지 못하다고 생각한 농부 존은 젖소들을 위한 마라톤 대회를 열었고, 농부 존의 총애를 받는 젖소 박승원 역시 이 대회에 참가할 예정이다.

마라톤 코스는 N (3 <= N <= 500) 개의 체크포인트로 구성되어 있으며, 1번 체크포인트에서 시작해서 모든 체크 포인트를 순서대로 방문한 후 N번 체크포인트에서 끝나야지 마라톤이 끝난다. 게으른 젖소 박승원은 막상 대회에 참가하려 하니 귀찮아져서 중간에 있는 체크포인트 K 개를 몰래 건너뛰려 한다. (K < N) 단, 1번 체크포인트와 N번 체크포인트를 건너뛰면 너무 눈치가 보이니 두 체크포인트는 건너뛰지 않을 생각이다.

젖소 박승원이 체크포인트를 최대 K 개 건너뛰면서 달릴 수 있다면, 과연 승원이가 달려야 하는 최소 거리는 얼마일까?

참고로, 젖소 마라톤 대회는 서울시내 한복판에서 진행될 예정이기 때문에 거리는 택시 거리(Manhattan Distance)로 계산하려고 한다. 즉, (x1,y1)과 (x2,y2) 점 간의 거리는 |x1-x2| + |y1-y2| 로 표시할 수 있다. (|x|는 절댓값 기호다.)

입력
첫번째 줄에 체크포인트의 수 N과 건너뛸 체크포인트의 수 K가 주어진다.

이후 N개의 줄에 정수가 두개씩 주어진다. 
i번째 줄의 첫번째 정수는 체크포인트 i의 x 좌표, 두번째 정수는 y 좌표이다. (-1000 <= x <= 1000, -1000 <= y <= 1000)

체크 포인트의 좌표는 겹칠 수도 있다 - 젖소 박승원이 한 체크포인트를 건너뛸 때는 그 번호의 체크포인트만 건너뛰며, 
그 점에 있는 모든 체크포인트를 건너뛰지 않는다.

출력
젖소 박승원이 체크포인트 K 개를 건너뛰고 달릴 수 있는 최소 거리를 출력하라.
*/


const int MAX_N = 500;
const int MAX_K = 500;
int N, K;

int d[MAX_N + 1][MAX_N + 1];
int X[MAX_N + 1], Y[MAX_N + 1];


int solve(int index, int k){
    if(index == N - 1) return 0;
    if(index >= N) return INF;

    int& ret = d[index][k];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i <= k; i++){
        ret = min(ret, solve(index + 1 + i, k - i)
            + abs(X[index + 1 + i] - X[index]) + abs(Y[index + 1 + i] - Y[index]));
    }
    return ret;
}

int main(){
    freopen("10653.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &X[i], &Y[i]);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, K));
}