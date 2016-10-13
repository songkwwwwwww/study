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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 20;
const int MAX_M = 20;
int N;
int M;
int a[MAX_M];
int d[MAX_N + 1][MAX_N + 1][MAX_N + 1];

int solve(int index, int open_1, int open_2){
    // base case
    if(index == M) return 0;

    int& ret = d[index][open_1][open_2];
    if(ret != -1) return ret;

    ret = INF;
    // 왼쪽 벽장을 이용하여 오픈
    ret = min(ret, solve(index + 1, a[index], open_2) + abs(a[index] - open_1));
    // 오른쪽 벽장을 이용하여 오픈
    ret = min(ret, solve(index + 1, open_1, a[index]) + abs(a[index] - open_2));

    return ret;
}

int main(){
    freopen("2666.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    int open_1, open_2;    
    scanf("%d %d", &open_1, &open_2);
    open_1--; open_2--;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &a[i]);
        a[i]--;
    }
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, open_1, open_2));
}