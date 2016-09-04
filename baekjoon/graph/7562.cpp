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
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 
첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 
체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력
각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.
*/
int l;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

inline bool is_safe(int x, int y){
    if(0 <= x && x < l && 0 <= y && y < l)
        return true;
    else
        return false;
}

int bfs(int start, int end){
    queue<int> q;
    vector<int> dist(l * l, -1);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == end) break;
        for(int i = 0; i < 8; i++){
            int new_x = (here / l) + dx[i];
            int new_y = (here % l) + dy[i];
            int there = new_x * l + new_y;
            if(is_safe(new_x, new_y) && dist[there] == -1){
                q.push(there);
                dist[there] = dist[here] + 1;
            }
        }
    }
    return dist[end] - dist[start];
}

int main(){
    freopen("7562.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        int sx, sy, ex, ey;
        scanf("%d", &l);
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        printf("%d\n", bfs(sx * l + sy, ex * l + ey));
    }
}