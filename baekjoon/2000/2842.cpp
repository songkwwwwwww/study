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

const int dx[8] = {0, 0, 1, -1, -1, 1, 1, -1}; // E W S N EN ES SW NW;
const int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1}; // E W S N EN ES SW NW;

const int INF = 987654321;

/*

*/


const int MAX_N = 50;
int N, K;
char m[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

// 방문한 집의 개수를 반환한다.
int dfs(int x, int y, int lo, int hi, vvb& visited){
    if(a[x][y] < lo || hi < a[x][y]) return 0;
    int ret = 0;
    visited[x][y] = true;
    if(m[x][y] == 'K')
        ret++;

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && !visited[nx][ny]){

            ret += dfs(nx, ny, lo, hi, visited);
        }
    }
    return ret;
}

bool check(int x, int y, int lo, int hi){
    vvb visited(N, vb(N));
    return (dfs(x, y, lo, hi, visited) == K);
}

int main(){
    freopen("2842.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int s_x, s_y;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf(" %c", &m[i][j]);
            if(m[i][j] == 'P'){
                s_x = i;
                s_y = j;
            }
            else if(m[i][j] == 'K')
                K++;
        }
    }
    vi height; height.reserve(N * N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
            height.push_back(a[i][j]);
        }
    }
    sort(height.begin(), height.end());
    height.erase(unique(height.begin(), height.end()), height.end());

    int cnt = height.size();
    int left = 0, right = 0;
    int result = INF;

    for(int i = 0; i < cnt; i++){
        int l = i;

        int r = cnt;
        while(l <= r){
            int m = (l + r) / 2;
            if(check(s_x, s_y, height[i], height[m])){
                result = min(result, height[m] - height[i]);
                r = m - 1;
            }
            else
                l = m + 1;
        }
    }
    printf("%d\n", result);
    
    /*
    while(left <= right && right < cnt){
        vvb visited(N, vb(N));
        int cur = dfs(s_x, s_y, height[left], height[right], visited);
        
        if(cur == K){
            result = min(result, height[right] - height[left]);            
            left++;
        }
        else // cur < K
            right++;
    }
    printf("%d\n", result);
    */
}