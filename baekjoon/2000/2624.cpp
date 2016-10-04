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
입력으로 지폐의 금액 T, 동전의 가지 수 k, 각 동전 하나의 금액 pi와 개수 ni가 주어질 때 (i=1, 2,…, k) 
지폐를 동전으로 교환하는 방법의 가지 수를 계산하는 프로그램을 작성하시오. 방법 의 수는 231을 초과하지 않는 것으로 가정한다.

입력
첫째 줄에는 지폐의 금액 T(0＜T≤10,000), 
둘째 줄에는 동전의 가지 수 k(0＜k≤100), 
셋째 줄부터 마지막 줄까지는 각 줄에 동전의 금액 pi(0＜pi≤T)와 개수 ni(0＜ni≤1,000)가 주어진다. 
pi와 ni사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에 동전 교환 방법의 가지 수를 출력한다. 방법이 없을 때는 0을 출력한다.
*/


const int MAX_T = 10000;
const int MAX_K = 100;
int T, K;
vi p, n;

vvi d;

int solve(int index, int money){
    // base case
    if(index == K){
        if(money == 0) return 1;
        else return 0;
    }

    int& ret = d[index][money];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i <= n[index]; i++){
        if(money - i * p[index] >= 0)
            ret += solve(index + 1, money - i * p[index]);
    }

    return ret;
}

int main(){
    freopen("2624.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &T, &K);
    p = vi(K);
    n = vi(K);
    d = vvi(K + 1, vi(T + 1, -1));
    for(int i = 0; i < K; i++){
        scanf("%d %d", &p[i], &n[i]);
    }
    printf("%d\n", solve(0, T));
}