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

const int dx[12] = {0, 0, 1, -1, -2, -1, 1, 2, 2, 1, -1, -2}; // E W S N;
const int dy[12] = {1, -1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 200;
const int MAX_M = 200;
const int MAX_K = 30;
int N, M, K;
int m[MAX_N + 3][MAX_M + 3];
bool visited[MAX_N + 3][MAX_M + 3][MAX_K + 3];

struct point{
    int x, y, cnt;
};

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

int main(){
    freopen("1600.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &K);
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &m[i][j]);
    
    // x, y, count;
    queue<point> q;
    q.push((point){0, 0, 0});
    visited[0][0][0] = true;
    int ans = 0;
    bool flag = false;    
    while(!q.empty()){
        int size = q.size();
        for(int s = 0; s < size; s++){
            int x = q.front().x;
            int y = q.front().y;
            int cnt = q.front().cnt;
            q.pop();

            if(x == N - 1 && y == M - 1){
                flag = true;
                break;
            }

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(is_range(nx, ny) && !visited[nx][ny][cnt] && m[nx][ny] == 0){
                    q.push((point){nx, ny, cnt});
                    visited[nx][ny][cnt] = true;
                }
            }
            if(cnt < K){
                for(int i = 4; i < 12; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(is_range(nx, ny) && !visited[nx][ny][cnt + 1] && m[nx][ny] == 0){
                        q.push((point){nx, ny, cnt + 1});
                        visited[nx][ny][cnt + 1] = true;
                    }
                }
            }
        }
        if(flag) break;
        ans++;
    }
    if(flag) printf("%d\n", ans);
    else printf("-1\n");
    
}