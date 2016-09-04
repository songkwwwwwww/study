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
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)

둘째 줄부터 N개 줄에는 그림이 주어진다.

출력
적록색약이 아닌 사람이 봤을 때의 구역의 개수와
적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
*/
int N;
char m[100][101];
char m_cpy[100][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

inline bool is_safe(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}

int dfs(int x, int y){
    char cur = m[x][y];
    m[x][y] = '0';
    for(int i = 0; i < 4; i++)
        if(is_safe(x + dx[i], y + dy[i]) 
            && ( m[x + dx[i]][y + dy[i]] == cur ))
            dfs(x + dx[i], y + dy[i]);
}

int solve(){
    int cnt = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(m[i][j] != '0'){
                cnt++;
                dfs(i, j);
            }
        }
    return cnt;
}

int main(){
    freopen("10026.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    memcpy(m_cpy, m, sizeof(m));
    printf("%d ", solve());
    memcpy(m, m_cpy, sizeof(m_cpy));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(m[i][j] == 'G')
                m[i][j] = 'R';
    printf("%d\n", solve());
}