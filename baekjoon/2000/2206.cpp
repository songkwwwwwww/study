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
입력
첫째 줄에 N(1≤N≤1,000), M(1≤M≤1,000)이 주어진다. 
다음 N개의 줄에 M개의 숫자로 맵이 주어진다. 
(1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/

const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
bool visited[2][MAX_N][MAX_M];
char m[MAX_N][MAX_M + 1];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}
int main(){
    freopen("2206.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);


    visited[0][0][0] = true;

    qi q;
    q.push(0);
   
    bool flag = false;
    int step = 1;
    while(!q.empty()){
        int q_size = q.size();
        for(int l = 0; l < q_size; l++){
            int here = q.front(); q.pop();

            bool crash = here / (N * M);
            int x = here % (N * M) / M;
            int y = here % M;

            if(x == N - 1 && y == M - 1){
                flag = true;
                break;
            }

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(is_range(nx, ny) && !visited[crash][nx][ny]){
                    if(m[nx][ny] == '1'){
                        if(crash == true) continue;
                        visited[1][nx][ny] = true;
                        q.push(N * M + nx * M + ny);                        
                    }
                    else{
                        visited[crash][nx][ny] = true;
                        q.push(crash * (N * M) + nx * M + ny);
                    }
                }
            }
        }
        if(flag) break;
        step++;
    }
    if(visited[0][N-1][M-1] || visited[1][N-1][M-1]) printf("%d\n", step);
    else printf("-1\n");
}