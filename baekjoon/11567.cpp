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


const int MAX_N = 500;
const int MAX_M = 500;
int N, M;
char m[MAX_N][MAX_M + 1];
int s_x, s_y, e_x, e_y;


inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

bool dfs(int x, int y){
    // base case
    if(x == e_x && y == e_y && m[x][y] == 'X')
        return true;
    m[x][y] = 'X';
    


    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny)) {
            if(m[nx][ny] == 'X'){
                if(nx == e_x && ny == e_y && dfs(nx, ny))
                    return true;
            }
            else{ // m[nx][ny] == '.'
                if(dfs(nx, ny))
                    return true;
            }
        }
    }
    return false;
}

int main(){
    freopen("11567.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    
    scanf("%d %d %d %d", &s_x, &s_y, &e_x, &e_y);
    s_x--; s_y--; e_x--; e_y--;
    
    if((s_x == e_x && s_y == e_y) || !dfs(s_x, s_y))
        printf("NO\n");
    else
        printf("YES\n");
}