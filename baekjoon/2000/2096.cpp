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

#include <functional> // greater, less
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
첫째 줄에 N(1<=N<=100,000)이 주어진다. 
다음 N개의 줄에는 숫자가 세 개씩 주어진다. 
숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나가 된다.

출력
첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.
*/

int N;

// min/max][2 * 3];
int d[2][2][3]; 

int main(){
    freopen("2096.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        d[1][i % 2][0] = MAX(d[1][(i - 1) % 2][0], d[1][(i - 1) % 2][1]) + a;
        d[1][i % 2][1] = MAX( MAX(d[1][(i - 1) % 2][0], d[1][(i - 1) % 2][1]) , d[1][(i - 1) % 2][2] ) + b;
        d[1][i % 2][2] = MAX(d[1][(i - 1) % 2][1], d[1][(i - 1) % 2][2]) + c;
        
        d[0][i % 2][0] = MIN(d[0][(i - 1) % 2][0], d[0][(i - 1) % 2][1]) + a;
        d[0][i % 2][1] = MIN( MIN(d[0][(i - 1) % 2][0], d[0][(i - 1) % 2][1]) , d[0][(i - 1) % 2][2] ) + b;
        d[0][i % 2][2] = MIN(d[0][(i - 1) % 2][1], d[0][(i - 1) % 2][2]) + c;
    }
    int max = -987654321;
    int min = 987654321;
    for(int i = 0; i < 3; i++){
        max = MAX(max, d[1][N % 2][i]);
        min = MIN(min, d[0][N % 2][i]);
    }
    printf("%d %d\n", max, min);
}