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
const int MOD = 1000000000;
/*


문제
45656이란 수를 보자.
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
그럼, 오늘도 역시 세준이는 0부터 9까지 모든 한 자리수가 자리수로 등장하면서, 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N이면서 0에서 9가 모두 등장하는 계단 수가 총 몇 개 있는 지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
*/

const int MAX_N = 100;
int N;
int d[MAX_N + 1][10][1<<10];

int solve(int n, int l, int state){
    // base case
    if(n == N){
        return state == (1 << 10) - 1;
    }

    int& ret = d[n][l][state];
    if(ret != -1) return ret;
    
    ret = 0;
    if(l - 1 >= 0){
        ret += solve(n + 1, l - 1, state | (1 << (l - 1)) );
        ret %= MOD;
    }
    if(l + 1 <= 9){
        ret += solve(n + 1, l + 1, state | (1 << (l + 1)) );
        ret %= MOD;
    }

    return ret; 
}

int main(){
    freopen("1562.txt", "r", stdin);
    scanf("%d", &N);
    memset(d, -1, sizeof(d));
    int result = 0;
    for(int i = 1; i <= 9; i++){
        result += solve(1, i, 1 << i);
        result %= MOD;
    }
    printf("%d\n", result);    
}