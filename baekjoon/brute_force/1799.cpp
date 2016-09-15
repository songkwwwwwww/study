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
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
입력
첫째 줄에 체스판의 크기가 주어진다. 
체스판의 크기는 10이하의 자연수이다. 
둘째 줄부터 아래의 예와 같이 체스판의 각 칸에 
비숍을 놓을 수 있는지 없는지에 대한 정보가 체스판 한 줄 단위로 한 줄씩 주어진다. 
비숍을 놓을 수 있는 곳에는 1, 비숍을 놓을 수 없는 곳에는 0이 빈칸을 사이에 두고 주어진다.

출력
첫째 줄에 주어진 체스판 위에 놓을 수 있는 비숍의 최대 개수를 출력한다.
*/
const int MAX_N = 10;

// / 대각선, \ 대각선
const int dx[2] = {1, 1}; // ;
const int dy[2] = {-1, 1}; // ;

// 체스판의 정보
int board_size;
int board[MAX_N][MAX_N];

int id[2][MAX_N][MAX_N];

bool adj[MAX_N][MAX_N];

int n, m;

vector<int> a_match, b_match;

vector<bool> visited;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < m; b++){
        if(adj[a][b]){
            if(b_match[b] == -1 || dfs(b_match[b])){
                a_match[a] = b;
                b_match[b] = a;
                return true;
            }
        }
    }
    return false;
}


int bipartite_match(){
    a_match = vector<int>(n, -1);
    b_match = vector<int>(m, -1);
    int size = 0;
    for(int start = 0; start < n; start++){
        visited = vector<bool>(n, false);
        if(dfs(start))
            ++size;
    }
    return size;
}

inline bool is_range(int x, int y){
    if(0 <= x && x < board_size && 0 <= y && y < board_size)
        return true;
    else
        return false;
} 

int place_bishops(){
    memset(id, -1, sizeof(id));
    int count[2] = {0, 0};

    for(int dir = 0; dir < 2; dir++)
        for(int x = 0; x < board_size; x++)
            for(int y = 0; y < board_size; y++)
                if(id[dir][x][y] == -1){
                    int nx = x, ny = y;
                    while(is_range(nx, ny)){
                            id[dir][nx][ny] = count[dir];
                            nx += dx[dir];
                            ny += dy[dir];
                    }
                    count[dir]++;
                }
    n = count[0];
    m = count[1];
    //memset(adj, 0, sizeof(adj));
    for(int x = 0; x < board_size; x++)
        for(int y = 0; y < board_size; y++)
            if(board[x][y] == 1)
                adj[id[0][x][y]][id[1][x][y]] = 1;
    
    return bipartite_match();
}
int main(){
    freopen("1799.txt", "r", stdin);
    scanf("%d", &board_size);
    
    for(int i = 0; i < board_size; i++)
        for(int j = 0; j < board_size; j++)
            scanf("%d", &board[i][j]);
    
    printf("%d\n", place_bishops());
}