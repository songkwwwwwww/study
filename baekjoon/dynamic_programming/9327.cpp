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
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.

각 테스트 케이스의 첫째 줄에는 RAID-1 세트의 수 n과 확보해야 하는 용량 e 가 주어진다. (1 ≤ n ≤ 100 and 0 ≤ e ≤ 10^9)

둘째 줄에는 각 세트의 크기 S1 ... Sn (1 ≤ Si ≤ 2 000)가 주어진다.

출력
각 테스트 케이스 마다 변환해야 하는 용량(GB)을 출력한다. 용량을 e만큼 더 확보할 수 없는 경우에는 “FULL”을 출력한다.
*/


const int MAX_N = 100;
int N, E;
int S[MAX_N];
int sum[MAX_N];
int d[MAX_N + 1][MAX_N * 2000 + 1];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int main(){
    freopen("9327.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &E);
        for(int i = 0; i < N; i++)
            scanf("%d", &S[i]);
        memset(d, -1, sizeof(d));
        sum[N - 1] = S[N - 1];
        for(int i = N - 2; i >= 0; i--)
            sum[i] = sum[i + 1] + S[i];
        
        
    }
}