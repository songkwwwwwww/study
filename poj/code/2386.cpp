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

const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}; // E W S N;
const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
char m[MAX_N][MAX_M + 1];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int dfs(int x, int y){
    m[x][y] = '.';
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && m[nx][ny] == 'W'){
            dfs(nx, ny);
        }
    }
}


int main(){
    freopen("2386.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)  
        scanf("%s", m[i]);

    int cnt = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(m[x][y] == 'W'){
                dfs(x, y);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
}