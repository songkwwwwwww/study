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
int N;
int a[MAX_N][MAX_N];
int max_h, min_h;

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

bool check(int lo, int hi){
    if(a[0][0] < lo || hi < a[0][0]) return false;

    queue< pair<int, int> > q;
    q.push(make_pair(0, 0));
    vvb visited(N, vb(N));
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == N - 1 && y == N - 1)
            break;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(is_range(nx, ny) && !visited[nx][ny]
                && lo <= a[nx][ny] && a[nx][ny] <= hi){
                
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

    return visited[N - 1][N - 1];
}

int main(){
    freopen("1981.txt", "r", stdin);
    //setbuf(stdout, NULL);
    max_h = 0; min_h = INF;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] > max_h) max_h = a[i][j];
            if(a[i][j] < min_h) min_h = a[i][j];
        }
    int l, r, m;
    int ans = INF;
    for(int i = min_h; i <= max_h; i++){
        l = i;
        r = max_h;

        while(l <= r){
            int m = (l + r) / 2;
            if(check(i, m)){
                ans = min(ans, m - i);
                r = m - 1;
            }
            else
                l = m + 1;
        }
    }
    printf("%d\n", ans);
}