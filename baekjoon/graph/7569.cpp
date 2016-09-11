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

const int dh[6] = {0, 0, 0, 0, 1, -1}; // E W S N;
const int dx[6] = {0, 0, 1, -1, 0, 0}; // E W S N;
const int dy[6] = {1, -1, 0, 0, 0, 0}; // E W S N;


const int INF = 987654321;

/*

*/

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_H = 100;

int N, M, H;
int m[MAX_H][MAX_N][MAX_M];

struct location{
    int x, y, h;
    location(int nh, int nx, int ny):h(nh), x(nx), y(ny) {}
};

inline bool is_range(int x, int y, int h){
    if(0 <= x && x < N && 0 <= y && y < M && 0 <= h && h < H)
        return true;
    else
        return false;
}

int main(){
    freopen("7569.txt", "r", stdin);
    scanf("%d %d %d", &M, &N, &H);
    
    queue< location > q;
    bool flag = false;
    for(int k = 0; k < H; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                scanf("%d", &m[k][i][j]);
                if(m[k][i][j] == 1)
                    q.push(location(k, i, j));
            }
    int count = 0;
    while(!q.empty()){
        count++;
        int size = q.size();
    
        for(int i = 0; i < size; i++){
            int h = q.front().h;
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for(int j = 0; j < 6; j++){
                int nh = h + dh[j];
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(is_range(nh, nx, ny) && m[nh][nx][ny] == 0){
                    q.push(location(nh, nx, ny));
                    m[nh][nx][ny] = 1;
                }
            }
        }
    }
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(m[k][i][j] == 0){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    printf("%d\n", count - 1);
}