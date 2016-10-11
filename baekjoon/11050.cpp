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
자연수 N과 정수 K가 주어졌을 때 이항 계수 (NK)을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

출력
 (NK)을 출력한다
*/


const int MAX_N = 10;
const int MAX_K = MAX_N;
int N, K;

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int factorials[MAX_N + 1];

int main(){
    freopen("11050.txt", "r", stdin);
    //setbuf(stdout, NULL);
    factorials[0] = factorials[1] = 1;
    for(int i = 2; i <= MAX_N; i++){
        factorials[i] = factorials[i - 1] * i;
    }
    scanf("%d %d", &N, &K);
    printf("%d\n", factorials[N] / (factorials[K] * factorials[N - K]));
}