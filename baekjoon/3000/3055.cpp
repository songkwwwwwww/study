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
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 
'D'와 'S'는 하나씩만 주어진다.

출력
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 
만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.
*/

int H, W;
char m[50][50];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};


inline bool is_safe(int x, int y){
    if(0 <= x && x < H && 0 <= y && y < W)
        return true;
    else
        return false;
}

int dfs(int start, int end, queue<int>& water_q){
    queue<int> q;
    q.push(start);
    vector<bool> visited(H * W, false);
    visited[start] = true;
    int time_count = 0;

    while(!q.empty()){
        time_count++;

        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            int x = q.front() / W; 
            int y = q.front() % W;
            q.pop();

            if((x * W + y) == end) return time_count-1;
            if(m[x][y] == '*') continue;
            for(int j = 0; j < 4; j++){
                int new_x = x + dx[j];
                int new_y = y + dy[j];
                int there = new_x * W + new_y;
                if(is_safe(new_x, new_y) && (m[new_x][new_y] == '.' || m[new_x][new_y] == 'D') 
                    && !visited[there]){
                    q.push(there);
                    visited[there] = true;
                }
            }
        }

        q_size = water_q.size();
        for(int i = 0; i < q_size; i++){
            int x = water_q.front() / W; 
            int y = water_q.front() % W;
            water_q.pop();
            
            for(int j = 0; j < 4; j++){
                int new_x = x + dx[j];
                int new_y = y + dy[j];
                int there = new_x * W + new_y;
                if(is_safe(new_x, new_y) && m[new_x][new_y] == '.'){
                    m[new_x][new_y] = '*';
                    water_q.push(there);
                }
            }
        }

       
    }
    return -1;
}

int main(){
    freopen("3055.txt", "r", stdin);
    scanf("%d %d", &H, &W);
    int start, end;
    queue<int> water_q;
    for(int i = 0; i < H; i++){
        for(int j = 0 ; j < W; j++){
            scanf(" %c", &m[i][j]);
            if(m[i][j] == 'S') start = i * W + j;
            else if(m[i][j] == 'D') end = i * W + j;
            else if(m[i][j] == '*') water_q.push(i * W + j);
        }
    }

    int ans = dfs(start, end, water_q);
    if(ans != -1) printf("%d\n", ans);
    else printf("KAKTUS\n");
    /*
    for(int i = 0; i < H; i++){
        for(int j = 0 ; j < W; j++){
            printf("%c", m[i][j]);
        }
        printf("\n");
    }*/
}