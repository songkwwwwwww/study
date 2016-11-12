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

const int dx[3] = {-1, 0, 1}; // EN E ES;
const int dy[3] = {1, 1, 1}; // EN E ES;

const int INF = 987654321;

/*

*/


const int MAX_N = 10000;
const int MAX_M = 500;
int N, M;
char m[MAX_N][MAX_M + 1];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

bool solve(int x, int y){
    if(m[x][y] == 'x' || x == N || x < 0) return false;

    m[x][y] = 'x';
    if(y == M - 1){
        return true;
    }

    return solve(x - 1, y + 1) || solve(x, y + 1) || solve(x + 1, y + 1);
}

int main(){
    freopen("3109.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(solve(i, 0))
            ans++;
    }
    printf("%d\n", ans);
}