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

const int dx[3] = {0, 0, 1}; // E W S;
const int dy[3] = {1, -1, 0}; // E W S;

const int INF = 987654321;

/*

*/


const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
int m[MAX_N][MAX_M];
int d[MAX_N][MAX_M][2];


int solve(int x, int y, int is_right){
    // base case
    if(x >= N) return -INF;
    if(x == N - 1 && y == M - 1) return m[x][y];
    if(x == N - 1 && d == 0) return -INF;
    
    int& ret = d[x][y][is_right];
    if(ret != -1) return ret; 

    ret = -INF;
    
    if(is_right && y < M - 1)
        ret = m[x][y] + solve(x, y + 1, is_right); 
    else if(!is_right && 0 < y) // left
        ret = m[x][y] + solve(x, y - 1, is_right);

    ret = max(ret, m[x][y] + max(solve(x + 1, y, 0), solve(x + 1, y, 1)));

    return ret;
}

int main(){
    freopen("2169.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &m[i][j]);
    
    memset(d, -1, sizeof(d));
    printf("%d\n", max(solve(0, 0, 0), solve(0, 0, 1)));
}