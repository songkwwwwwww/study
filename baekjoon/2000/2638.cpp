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
첫째 줄에는 모눈종이의 크기를 나타내는 두 개의 정수 N, M (5≤N, M≤100)이 주어진다. 
그 다음 N 줄에는 모눈종이 위의 격자에 치즈가 있는 부분은 1로 표시되 고, 치즈가 없는 부분은 0으로 표시된다. 
또한, 각 0과 1은 하나의 공백으로 분리되어 있다.

출력
출력으로는 주어진 치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 정수로 첫 줄에 출력한다.
*/

int N, M;
int a[100][100];

int dx[4] = {0, 0, 1, -1}; // E W S N
int dy[4] = {1, -1, 0, 0}; // E W S N

bool done(){
    int cnt = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(a[i][j] == -1 || a[i][j] > 2) 
                a[i][j] = 0;
            else if(a[i][j] == 2 || a[i][j] == 1){
                a[i][j] = 1;
                cnt++;
            }  
        }
    return cnt == 0;
}

int solve(int x, int y){
    a[x][y] = -1;
    for(int i = 0; i < 4; i++){
        if((x + dx[i] >= 0) && (x + dx[i] < N) && (y + dy[i] >= 0) && (y + dy[i] < M)){
            if(a[x + dx[i]][y + dy[i]] == 0)
                solve(x + dx[i], y + dy[i]);
            else if(a[x + dx[i]][y + dy[i]] > 0)
                a[x + dx[i]][y + dy[i]]++;
        }
    }
}


int main(){
    freopen("2638.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &a[i][j]);
    
    int res;
    for(res = 0; !done(); res++)
        solve(0,0);
    printf("%d\n", res);

}