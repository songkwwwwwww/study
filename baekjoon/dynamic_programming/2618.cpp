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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 1000;
const int MAX_M = 15;

int N, W, ans = INF;
int back_track[1010];
int d[MAX_N + 10][MAX_N + 10];

struct location{
    int x, y;
    location(){}
    location(int nx, int ny): x(nx), y(ny) {}
} E[1010];


inline int dis(int a, int b){
    return abs(E[a].x - E[b].x) + abs(E[a].y - E[b].y);
}

int solve(int a, int b){
    int& ret = d[a][b];
    if(ret != -1) return ret;
    
    int next = (a > b ? a : b) + 1;
    if(next >= W + 2) 
        return 0;
    ret = INF;
    if(ret > solve(next, b) + dis(a, next)){
        ret = solve(next, b) + dis(a, next);
        back_track[next] = 1;
    }

    if(ret > solve(a, next) + dis(b, next)){
        ret = solve(a, next) + dis(b, next);
        back_track[next] = 2;
    }
    return ret;
}


int main(){
    freopen("2618.txt", "r", stdin);
    scanf("%d %d", &N, &W);
    E[0].x = 1; E[0].y = 1;
    E[1].x = N; E[1].y = N;
    memset(d, -1, sizeof(d));
    for(int i = 2; i < W + 2; i++)
        scanf("%d %d", &E[i].x, &E[i].y);
    printf("%d\n", solve(0, 1));
    for(int i = 2; i < W + 2; i++)
        printf("%d\n", back_track[i]);
}