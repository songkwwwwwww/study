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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 N, 
동쪽으로 이동할 확률, 
서쪽으로 이동할 확률, 
남쪽으로 이동할 확률, 
북쪽으로 이동할 확률이 주어진다. N은 14보다 작거나 같은 자연수이고,  
모든 확률은 100보다 작거나 같은 자연수이다. 
그리고, 동서남북으로 이동할 확률을 모두 더하면 100이다.

출력
첫재 줄에 로봇의 이동 경로가 단순할 확률을 출력한다. 
절대/상대 오차는 10-9 까지 허용한다.
*/
int N;
double p[4];
bool visited[40][40];

double solve(int x, int y, int index){
    double result = 0.0;
    // base case
    if(index == N){
        return 1.0;
    }
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[nx][ny])
            result += p[i] * solve(nx, ny, index + 1);
    }
    visited[x][y] = false;
    return result;
}

int main(){
    freopen("1405.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < 4; i++){
        int prob;
        scanf("%d", &prob);
        p[i] = prob/100.0;
    }
    printf("%.10lf\n", solve(15, 15, 0));
}