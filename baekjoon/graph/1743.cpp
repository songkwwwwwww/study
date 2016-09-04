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
입력
첫째줄에 통로의 세로 길이(N<=100)과 가로길이(M<=100)
 그리고 음식물 쓰레기의 개수(K<=10,000)이 주어진다.  
 그리고 다음 K개의 줄에 음식물이 떨어진 좌표가 주어진다.

출력
첫째 줄에 음식물중 가장 큰 음식물의 크기를 출력하라.
*/

int N, M, K;
int m[100][100];

int dx[4] = {0, 0, 1, -1}; // E W S N
int dy[4] = {1, -1, 0, 0}; // E W S N
int size[30];

int cmp(int a, int b){
    if(a > b)
        return true;
    else
        return false;
}

int dfs(int x, int y, int c){
    m[x][y] = c;
    for(int i = 0; i < 4; i++){
        if(0 <= x + dx[i] && x + dx[i] < N && 0 <= y + dy[i] && y + dy[i] < M
            && m[x + dx[i]][y + dy[i]] == 1)
            dfs(x + dx[i], y + dy[i], c);
    }
}

int solve(int x, int y){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(m[i][j] == 1){
                cnt++;
                dfs(i, j, cnt + 1);
            }
        }
    }
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(m[i][j])
                size[m[i][j] - 2]++;

    sort(size, size + cnt, cmp);

    return size[0];
}

int main(){
    freopen("1743.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &K);
    int x, y;
    for(int i = 0; i < K; i++){
        scanf("%d %d", &x, &y);
        x--; y--;
        m[x][y] = 1;
    }

    printf("%d\n", solve(0, 0));
}