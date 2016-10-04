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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

int N, M, D;
inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

const int MAX_N = 2000;
const int MAX_M = 200;
const int MAX_D = 200000;
int main(){
    freopen("2939.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    vvi m(N, vi(M)), adj(N, vi(M, INF));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &m[i][j]);
    
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(y == 0 || y == M - 1){
                for(int i = 0; i < 2; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(is_range(nx, ny)){
                        adj[x][y]
                    }
                }
            }
            else{

            }
        }
    }
}