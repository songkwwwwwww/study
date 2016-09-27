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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
민식이가 한 블록 동서남북으로 이동하는데는 1분이 걸린다. 
민식이는 네가지 방향 중 하나로 이동할 수 있으며, 교실을 벗어날 수 없다. 
민식이가 선물을 배달해야 하는 곳에 들어갈 때, 민식이는 그 곳에 있는 사람 모두에게 선물을 전달해야 한다. 
이 상황은 동시에 일어나며, 추가적인 시간이 소요되지 않는다.

민식이는 어느 누구도 자신을 보지 않았으면 하기 때문에, 멈추지 않고 매 시간마다 방향을 바꿔야 한다.
이 말은 같은 방향으로 두 번 연속으로 이동할 수 없다는 말이다. 
민식이가 선물을 모두 배달하는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 교실의 세로 크기 N과 가로 크기 M이 주어진다. 
N과 M은 50보다 작거나 같은 자연수이다. 

둘째 줄부터 N개의 줄에 교실의 지도가 주어진다.

출력
첫째 줄에 민식이가 선물을 모두 배달하는데 걸리는 시간의 최솟값을 출력한다. 만약 불가능 할 때는 -1을 출력한다.
*/


const int MAX_N = 50;
const int MAX_M = 50;
int N, M;
char m[MAX_N + 1][MAX_M + 1];

struct point{
    int x, y;
    int prev;
    int time;
    int state;
    point(){
        x = 0;
        y = 0;
        prev = -1;
        time = 0;
        state = 0;
    }
    point(int nx, int ny):x(nx), y(ny){}

    bool operator == (const point& rhs){
        if(x == rhs.x && y == rhs.y)
            return true;
        else
            return false;
    }
};

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int main(){
    freopen("1175.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    point C[2], S;
    int p = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &m[i][j]);
            if(m[i][j] == 'S'){
                S.x = i;
                S.y = j;
            }
            else if(m[i][j] == 'C'){
                C[p].x = i;
                C[p].y = j;
                p++;
            }
        }
    }

    int d[MAX_N][MAX_M][4][4];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < 4; k++)
                for(int l = 0; l < 4; l++)
                    d[i][j][k][l] = INF;

    int ans = INF;
    queue<point> q;
    q.push(S);
    while(!q.empty()){
        point here = q.front(); q.pop();
        //printf("here : ( %d, %d) , time : %d, state : %d\n", here.x, here.y, here.time, here.state);
        if(here.state == 3){
            ans = min(ans, here.time);
            //printf("finish!!\n");
            continue;
        }

        for(int i = 0; i < 4; i++){
            // 이전 방향과 같다면, 건너뛴다
            if(i == here.prev) continue;
            point there;
            there.x = here.x + dx[i];
            there.y = here.y + dy[i];
            // 새로 이동하려고 하는 장소가 범위를 벗어났거나 벽이면, 건너뛴다
            if(!is_range(there.x, there.y) || m[there.x][there.y] == '#') continue;

            there.time = here.time + 1;
            // 새로 이동하려는 장소까지의 시간이 이미 기록된 시간보다 늦다면, 건너뛴다.
            if(there.time >= d[there.x][there.y][i][here.state]) continue;
            there.state = here.state;
            if(there == C[0]){
                if(here.state & (1 << 0)) 
                    continue;
                else 
                    there.state |= (1 << 0);
            }
            else if(there == C[1]){
                if(here.state & (1 << 1)) 
                    continue;
                else 
                    there.state |= (1 << 1);
            }
            there.prev = i;
            q.push(there);
            d[there.x][there.y][i][here.state] = there.time;
        }
    }
    if(ans == INF) 
        printf("-1\n");
    else 
        printf("%d\n", ans);
}