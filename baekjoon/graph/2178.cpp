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
미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 
지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
입력
첫째 줄에 두 정수 N, M(2≤N, M≤100)이 주어진다. 
다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 
각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/
int N, M;
char m[100][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

inline bool is_safe(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int bfs(int start, int end){
    queue<int> q;
    q.push(start);
    vector<int> dist(N * M, -1);
    dist[start] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == end) break;
        for(int i = 0; i < 4; i++){
            int new_x = here / M + dx[i];
            int new_y = here % M + dy[i];
            int there = new_x * M + new_y;
            if(is_safe(new_x, new_y) && m[new_x][new_y] == '1' 
                && dist[there] == -1){
                q.push(there);
                dist[there] = dist[here] + 1;
            }
        }
    }
    return dist[end] - dist[start] + 1;
}

int main(){
    freopen("2178.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    printf("%d\n", bfs(0, (N - 1) * M + (M - 1)));
}