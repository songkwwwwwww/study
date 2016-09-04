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
첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. 
N은 2 이상 100 이하의 정수이다. 
둘째 줄부터 N 개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 순서대로 한 행씩 
높이 정보가 입력된다. 
각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N 개의 높이 정보를 나타내는 
자연수가 빈 칸을 사이에 두고 입력된다. 
높이는 1이상 100 이하의 정수이다. 

출력
첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다. 
*/
int N;
int m[100][100];
bool visited[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

inline bool is_safe(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}

int dfs(int x, int y, int height){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
        if(is_safe(x + dx[i], y + dy[i]) && !visited[x + dx[i]][y + dy[i]] &&
            m[x + dx[i]][y + dy[i]] > height)
            dfs(x + dx[i], y + dy[i], height);
}

int solve(int height){
    int cnt = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!visited[i][j] && m[i][j] > height){
                cnt++;
                dfs(i, j, height);
            }
    return cnt;
}

int main(){
    freopen("2468.txt", "r", stdin);
    scanf("%d", &N);
    int min_height = 987654321;
    int max_height = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%d", &m[i][j]);
            min_height = MIN(m[i][j], min_height);
            max_height = MAX(m[i][j], max_height);
        }

    int result, ans = 0;
    for(int height = 1; height <= max_height; height++){
        result = solve(height);
        ans = MAX(ans, result);
        memset(visited, false, sizeof(visited));
    }
    printf("%d\n", ans);
}