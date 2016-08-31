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
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
int M, N;
int a[501][501];
int d[501][501];

// E W S N
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int go(int x, int y){
    // base case
    if(x == M - 1 && y == N - 1) 
        return 1;
    
    int& ret = d[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(a[x][y] > a[next_x][next_y] && 0 <= next_x && next_x <= M - 1 && 0 <= next_y && next_y <= N - 1)
            ret += go(next_x, next_y);    
    }
    return ret;
}

int main(){
    freopen("1520.txt", "r", stdin);
    scanf("%d %d", &M, &N);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    
    memset(d, -1, sizeof(d));
    
    printf("%d\n", go(0, 0));
}