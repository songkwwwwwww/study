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
첫째 줄에 테스트 케이스의 개수 T(1 <= T <= 1,000)가 주어진다. 
각 테스트 케이스는 양의 정수 1개로 이루어져있고, 이 수가 문제에서 설명한 N이고, 1,000보다 작거나 같다.

출력
각 테스트 케이스에 대해 한 줄에 하나씩 N의 재귀적인 팰린드롬 파티션의 개수를 출력한다.
*/


const int MAX_N = 1000;
int N;
vi d;
int solve(int n){
    // base case
    if(n < 1) return 0;
    if(n < 2) return 1;   

    int& ret = d[n];
    if(ret != -1) return ret;

    ret = 1;
    for(int i = 1; i <= n/2; i++){
        ret += solve(i);
    }

    return ret;
}

int main(){
    freopen("2705.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);
        d = vi(N + 1, -1);
        printf("%d\n", solve(N));
    }
}