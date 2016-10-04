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

typedef queue<int> qi;

const int dx[4] = {1, 0, -1, 0}; // E W S N;
const int dy[4] = {0, 1, 0, -1}; // E W S N;

const int INF = 987654321;

/*

*/

int N, target, target_x, target_y;
int x, y, nx, ny, d;
int a[999][999];
inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}

int main(){
    freopen("1913.txt", "r", stdin);
    scanf("%d %d", &N, &target);
    
    for(int i = N * N; i > 0; i--){
        if(i == target){
            target_x = x;
            target_y = y;
        }
        a[x][y] = i;

        nx = x + dx[d];
        ny = y + dy[d];
        if(!is_range(nx, ny) || a[nx][ny]){
            d = (d + 1) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }        
        x = nx;
        y = ny;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("%d %d\n", target_x + 1, target_y + 1);
}