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
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
그 다음 줄부터 각각의 테스트 케이스에 대해 
첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50),
 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 
 
 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 
 예제의 경우 M은 10, N은 8, K는 17이다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.
*/

int TC;
int M, N, K;
int m[50][50];

const int dx[4] = {0, 0, 1, -1}; // E W S N
const int dy[4] = {1, -1, 0, 0}; // E W S N

int dfs(int x, int y, int c){
    m[x][y] = c;
    for(int i = 0; i < 4; i++){
        if(0 <= x + dx[i] && x + dx[i] < M && 0 <= y + dy[i] && y + dy[i] < N
            && m[x + dx[i]][y + dy[i]] == 1){
            dfs(x + dx[i], y + dy[i], c);
        }
    }
}

int solve(int x, int y){
    int count = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] == 1){
                count++;
                dfs(i, j, count + 1);
            }
        }
    }
    return count;
}

int main(){
    freopen("1012.txt", "r", stdin);
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d", &M, &N, &K);
        int x, y;
        for(int i = 0; i < K; i++){
            scanf("%d %d", &x, &y);
            m[x][y] = 1;
        }
        printf("%d\n", solve(0, 0));
        memset(m, 0, sizeof(m));
    }
}