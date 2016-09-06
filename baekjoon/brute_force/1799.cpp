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

// id[dir][x][y] = dir 방향 대각선을 따라 인접한 빈 칸 묶음들 중
// (x, y)가 속한 묶음의 번호
int id[2][MAX_N][MAX_N];

// A와 B의 정점 개수
// adj[i][j] A_i 와 B_i가 연결되어 있는가?
bool adj[MAX_N][MAX_N];


// 이분 그래프의 정보
int n, m;

// 각 정점에 매칭된 상대 정점의 번호를 저장한다.
vector<int> a_match, b_match;

// dfs()의 방문 여부
vector<bool> visited;

// A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로를 찾는다.
bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < m; b++){
        if(adj[a][b]){
            if(b_match[b] == -1 || dfs(b_match[b])){
                // 증가 경로 발견. a와 b를 매칭시킨다.
                a_match[a] = b;
                b_match[b] = a;
                return true;
            }
        }
    }
    return false;
}


// a_match, b_match 배열을 계산하고 최대 매칭의 크기를 반환한다.
int bipartite_match(){
    // 처음에는 어떤 정점도 연결되어 있지 않다.
    a_match = vector<int>(n, -1);
    b_match = vector<int>(m, -1);
    int size = 0;
    for(int start = 0; start < n; start++){
        visited = vector<bool>(n, false);
        // dfs를 이영해 start에서 시작하는 증가 경로를 찾는다.
        if(dfs(start))
            ++size;
    }
    return size;
}

int place_bishops(){
    // 각 묶음에 번호를 붙인다.
    memset(id, -1, sizeof(id));
    int count[2] = {0, 0};

    for(int dir = 0; dir < 2; dir++)
        for(int x = 0; x < board_size; x++)
            for(int y = 0; y < board_size; y++)
                if(board[x][y] == 1 && id[dir][x][y] == -1){
                    int cx = x, cy = y;
                    while(0 <= cx && cx < board_size &&
                        0 <= cy && cy < board_size &&
                        board[cx][cy] == 1){
                            id[dir][cx][cy] = count[dir];
                            cx += dx[dir];
                            cy += dy[dir];
                    }
                    count[dir]++;
                }

    // 이분 그래프를 만든다.
    n = count[0];
    m = count[1];
    memset(adj, 0, sizeof(adj));
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