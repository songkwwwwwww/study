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


const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
int m[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M][4];

struct point{
    int x, y, d, step;
    //point(){}
};

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

int turn(int dir, int is_left){
    if(is_left){ // turn left
        if(dir == 0)
            return 3;
        else if(dir == 1)
            return 2;
        else if(dir == 2)
            return 0;
        else if(dir == 3)
            return 1;
    }
    else{ // turn right
        if(dir == 0)
            return 2;
        else if(dir == 1)
            return 3;
        else if(dir == 2)
            return 1;
        else if(dir == 3)
            return 0;
    }
}

int main(){
    freopen("1726.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &m[i][j]);
    int s_x, s_y, s_d;
    int e_x, e_y, e_d;
    scanf("%d %d %d", &s_x, &s_y, &s_d);
    scanf("%d %d %d", &e_x, &e_y, &e_d);
    s_x--; s_y--; e_x--; e_y--; s_d--; e_d--;
    queue<point> q;
    q.push((point){s_x, s_y, s_d, 0});
    visited[s_x][s_y][s_d] = true;
    int ans = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        int step = q.front().step;
        q.pop();

        // 종료 지점에 도달했는가?
        if(x == e_x && y == e_y && d == e_d){
            ans = step;
            break;
        }
        // 1, 2, 3 만큼 전진 이동할 수 있다.
        for(int i = 1; i <= 3; i++){
            int nx = x + dx[d] * i;
            int ny = y + dy[d] * i;
            if(!is_range(nx, ny) || visited[nx][ny][d]) continue;
            // 해당 블럭이 1이라면 더 이상 전진할 수 없다.
            if(m[nx][ny] == 1) break;
            visited[nx][ny][d] = true;
            q.push((point){nx, ny, d, step + 1});
        }

        // turn right or turn left
        for(int i = 0; i < 2; i++){
            int nd = turn(d, i);
            if(!visited[x][y][nd]){
                visited[x][y][nd] = true;                
                q.push((point){x, y, nd, step + 1});
            }
        }
    } // end of while
    printf("%d\n", ans);
}