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
첫째 줄에 n, m(1≤n, m≤1,000)이 주어진다. 
다음 줄에는 n명의 남자들의 성격이 주어진다.
그 다음 줄에는 m명의 여자들의 성격이 주어진다. 
성격은 1,000,000이하의 자연수이다.

출력
첫째 줄에 성격의 차이의 합의 최솟값을 출력한다.
*/


const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
int man[MAX_N], woman[MAX_M];
int d[MAX_N][MAX_M];

int solve(int index_m, int index_w){
    if(index_w == M) return 0;
    if(index_m == N) return INF;
         

    int& ret = d[index_m][index_w];
    if(ret != -1) return ret;

    ret = min(solve(index_m + 1, index_w), 
        solve(index_m + 1, index_w + 1) + abs(man[index_m] - woman[index_w]));

    return ret;
}

int main(){
    freopen("1727.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &man[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &woman[i]);
    
    sort(man, man + N);
    sort(woman, woman + M);
    if(N < M){
        swap(N, M);
        swap(man, woman);
    }

    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0));
}