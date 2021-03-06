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

*/


const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
int a[MAX_N][MAX_M];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

bool done(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == -1 || a[i][j] > 2)
                a[i][j] = 0;
            else if(a[i][j] == 1 || a[i][j] == 2){
                a[i][j] = 1;
                cnt++;
            }
        }
    }

    return cnt == 0;
}

int solve(int x, int y){
    a[x][y] = -1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny)){
            // 비어있으면 간다
            if(a[nx][ny] == 0){
                solve(nx, ny);
            }
            // 비어있지 않으면
            else if(a[nx][ny] > 0){
                a[nx][ny]++;
            }
        }
    }
}
/*
int solve(int x, int y){
    a[x][y] = -1;
    for(int i = 0; i < 4; i++){
        if((x + dx[i] >= 0) && (x + dx[i] < N) && (y + dy[i] >= 0) && (y + dy[i] < M)){
            if(a[x + dx[i]][y + dy[i]] == 0)
                solve(x + dx[i], y + dy[i]);
            else if(a[x + dx[i]][y + dy[i]] > 0)
                a[x + dx[i]][y + dy[i]]++;
        }
    }
}
*/

int main(){
    freopen("2638.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &a[i][j]);
    
    int ans = 0;
    for(ans = 0; !done(); ans++)
        solve(0, 0);

    printf("%d\n", ans);
}