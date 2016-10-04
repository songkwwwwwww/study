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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫 줄에 체스판의 크기 N이 주어진다. (1 ≤ N ≤ 100)

그리고 다음 N개의 줄에 체스판의 정보가 주어진다. 
'.'은 빈 칸을 의미하고, 'X'는 그 칸에 폰이 있음을 의미한다.

출력
주어진 체스판에 룩을 배치할 때, 최대 몇 개를 배치할 수 있는지 출력한다.
*/

const int MAX_N = 100;

int N;
char m[MAX_N][MAX_N + 1];
vi a_match, b_match;
vb visited;
vi adj[MAX_N * MAX_N / 2];

int dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;

    for(int i = 0; i < adj[a].size(); i++){
        int b = adj[a][i];

        if(b_match[b] == -1 || dfs(b_match[b])){
            a_match[a] = b;
            b_match[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    freopen("9525.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    int m_by_r[MAX_N][MAX_N], m_by_c[MAX_N][MAX_N];
    int r_index = -1, c_index = -1;
    /*
    for(int i = 0; i < N; i++){
        printf("%s\n", m[i]);
    }
    */
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] == 'X') continue;
            if(j == 0 || m[i][j - 1] == 'X') r_index++;
            m_by_r[i][j] = r_index;
        }
    }
    r_index++;
    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            if(m[i][j] == 'X') continue;
            if(i == 0 || m[i - 1][j] == 'X') c_index++;
            m_by_c[i][j] = c_index;
        }
    }
    c_index++;
    int total = r_index + c_index;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(m[i][j] != 'X')
                adj[m_by_r[i][j]].push_back(m_by_c[i][j]);
    
    a_match = vi(total, -1);
    b_match = vi(total, -1);
    int count = 0;
    for(int i = 0; i < r_index; i++){
        visited = vb(total, false);
        if(dfs(i))
            count++;
    }    
    printf("%d\n", count);
}