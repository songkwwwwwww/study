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
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. 
M, N, K는 모두 100 이하의 자연수이다. 
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과
오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 
모눈종이의 왼쪽 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 
입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.
*/
int M, N, K;
int m[100][100];
int size[30];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

inline bool is_safe(int x, int y){
    if(0 <= x && x < M && 0 <= y && y < N)
        return true;
    else
        return false;
}

int dfs(int x, int y, int c){
    m[x][y] = c;
    for(int i = 0; i < 4; i++){
        if(is_safe(x + dx[i], y + dy[i]) && m[x + dx[i]][y + dy[i]] == 1)
            dfs(x + dx[i], y + dy[i], c);
    }
}

int cmp(int a, int b){
    if(a > b)
        return true;
    else 
        return false;
}
int solve(){
    int cnt = 0;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(m[i][j] == 1){
                cnt++;
                dfs(i, j, cnt + 1);
            }
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++){
            size[m[i][j] - 2]++;            
        }
    sort(size, size + cnt);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%d ", size[i]);
    printf("\n");
}

int main(){
    freopen("2583.txt", "r", stdin);
    memset(m, 0, sizeof(m));
    scanf("%d %d %d", &M, &N, &K);
    int x1, y1, x2, y2;
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            m[i][j] = 1;

    for(int i = 0; i < K; i++){
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        y2--; x2--;
        for(int k = x1; k <= x2; k++)
            for(int l = y1; l <= y2; l++)
                m[k][l] = 0;
    }

    solve();
}