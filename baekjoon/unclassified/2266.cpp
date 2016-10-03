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

E(N, K) : K 개의 금고를 가지고 F층을 알아낼 수 있는 최소한의 금고 낙하 횟수
두 정수 N, K가 주어졌을 때 E(N, K)를 구하는 프로그램을 작성하시오.


d[i][j] : i층 빌딩에서 j개의 금고로 최악의 경우 떨어뜨려야하는 최소 횟수
i층 빌딩에서 떨어뜨렸을 때 
1) 금고가 부서졌을 경우 : 
k-1 개의 금고로 (f - 1)층을 조사

2) 금고가 부서지지 않았을 경우 :
k개의 금고로 (i - f)층을 조사

d[i][j] = 1 + max(d[f - 1][j - 1] + d[i-f][j])
*/


const int MAX_N = 500;
const int MAX_K = MAX_N;
int N, K;
int d[MAX_N + 1][MAX_K + 1];


int main(){
    freopen("2266.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    // 1층인 경우 K 개에 상관 없이 1회로 끝난다.
    for(int i = 1; i <= K; i++){
        d[1][i] = 1;
    }
    // 1개의 금고를 가지고 있는 경우, 층 수만큼의 횟수가 필요하다.
    for(int i = 1; i <= N; i++){
        d[i][1] = i;
    }

    for(int j = 2; j <= K; j++){
        for(int i = 2; i <= N; i++){
            d[i][j] = INF;
            for(int f = 1; f <= i; f++){
                d[i][j] = min(d[i][j], 1 + max(d[f - 1][j - 1], d[i - f][j]));
            }
        }
    }
    printf("%d\n", d[N][K]);
}