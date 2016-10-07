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

*/


const int MAX_N = 2000;
int N;
int A[MAX_N], B[MAX_N];
int d[MAX_N][MAX_N];

int solve(int index_a, int index_b){
    // base case
    if(index_a == N || index_b == N) 
        return 0;
    
    int& ret = d[index_a][index_b];
    if(ret != -1) return ret;

    // 규칙 1
    ret = max(solve(index_a + 1, index_b + 1), solve(index_a + 1, index_b));
    
    // 규칙 2
    if(A[index_a] > B[index_b])
        ret = max(ret, solve(index_a, index_b + 1) + B[index_b]);
    
    return ret;
}

int main(){
    freopen("10835.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &B[i]);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0));
}