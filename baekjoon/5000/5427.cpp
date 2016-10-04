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
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.

각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)

다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
각 지도에 @의 개수는 하나이다.

출력
각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 
빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.
*/
int W, H;
char m[1000][1001];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

inline bool is_safe(int x, int y){
    if(0 <= x && x < H && 0 <= y && y < W)
        return true;
    else
        return false;
}

int dfs(queue<int>& q, queue<int>& fire_q){
    vector<bool> visited(H * W, false);
    visited[q.front()] = true;
    int time_count = 0;

    while(!q.empty()){
        time_count++;
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            int x = q.front() / W;
            int y = q.front() % W;
            q.pop();
            if(m[x][y] == '*') continue;
            for(int j = 0; j < 4; j++){
                int new_x = x + dx[j];
                int new_y = y + dy[j];
                if(!is_safe(new_x, new_y))
                    return time_count;
                
                if(m[new_x][new_y] == '.' && !visited[new_x * W + new_y]){
                    visited[new_x * W + new_y] = true;
                    q.push(new_x * W + new_y);
                }
            }
        }
        
        q_size = fire_q.size();
        for(int i = 0; i < q_size; i++){
            int x = fire_q.front() / W;
            int y = fire_q.front() % W;
            fire_q.pop();
            
            for(int j = 0; j < 4; j++){
                int new_x = x + dx[j];
                int new_y = y + dy[j];
                if(is_safe(new_x, new_y) && m[new_x][new_y] == '.'){
                    m[new_x][new_y] = '*';
                    fire_q.push(new_x * W + new_y);
                }
                
            }
        }
    }
    return -1;
}

int main(){
    freopen("5427.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        queue<int> q, fire_q;
        scanf("%d %d", &W, &H);
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                scanf(" %1c", &m[i][j]);
                if(m[i][j] == '@'){
                    q.push(i * W + j);
                }
                else if(m[i][j] == '*')
                    fire_q.push(i * W + j);
            }
        }
        int ans = dfs(q, fire_q);
        if(ans != -1) printf("%d\n", ans);
        else printf("IMPOSSIBLE\n");
    }    
    
}