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


const int MAX_N = 5;
int N = 5;
char m[MAX_N][MAX_N + 1];
bool visited[MAX_N][MAX_N];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int solve(int x, int y, int S, int Y){
    if(!is_range(x, y)) return 0;
    
    if(m[x][y] == 'S') S++;
    else Y++;
    
    if(S + Y == 7){
        if(S >= 4)
            return 1;
        else
            return 0;
    }
    visited[x][y] = true;
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret += solve(nx, ny, S, Y);
    }
    visited[x][y] = false;
    
    return ret;
}

int main(){
    freopen("1941.txt", "r", stdin);
    //setbuf(stdout, NULL);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans += solve(i, j, 0, 0);   
        }
    }
    printf("%d\n", ans);
}