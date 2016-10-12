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

int done(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // 치즈가 남아있는 경우
            if(a[i][j] == 1){
                cnt++;
            }
            // 치즈가 없어진 경우
            else if(a[i][j] > 1 || a[i][j] == -1){
                a[i][j] = 0;
            }
        }
    }
    return cnt;
}

int solve(int x, int y){
    a[x][y] = -1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M){
            // 다음 칸이 비어있다면 이동
            if(a[nx][ny] == 0){
                solve(nx, ny);
            }
            // 치즈가 있다면 ++ 한다.
            // 해당 칸이 >= 2 라면, 치즈가 없어졌다는 뜻이다.
            else if(a[nx][ny] == 1){
                a[nx][ny]++;
            }
        }
    }
}

int main(){
    freopen("2636.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &a[i][j]);
    int ans = 0, count;
    while(true){
        int cur = done();
        if(cur == 0) break;
        solve(0, 0);
        count = cur;
        ans++;
    }
    printf("%d\n%d\n", ans, count);
}