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
문제
1과 0으로 이루어진 NxM크기의 행렬이 주어졌을 때, 1로만 이루어진 가장 큰 정사각형 부분 행렬 찾는 프로그램을 작성하시오. 

입력
입력은 여러 테스트 케이스로 이루어져 있다. 
각 테스트 케이스의 첫째 줄에는 N과 M이 주어진다. (1 ≤ N,M ≤ 1,000) 
다음 N개의 줄에는 공백으로 구분된 M개의 수가 주어진다. 
마지막 줄에는 0이 두 개가 주어진다.

출력
각 테스트 케이스에 대해서 가장 큰 정사각형의 너비 또는 높이를 출력한다. 
만약 그런 정사각형이 없을 때는 0을 출력한다.
*/
int N, M;
int m[1001][1001];
int d[1001][1001];
int main(){
    freopen("4095.txt", "r", stdin);
    while(true){
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                scanf("%d", &m[i][j]);
        int max = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(m[i][j] == 1){
                    d[i][j] = 1 + MIN( MIN(d[i][j - 1], d[i - 1][j - 1]), d[i - 1][j]);
                    max = MAX(max, d[i][j]);
                }
            }
        }
        printf("%d\n", max);
        memset(d, 0, sizeof(d));
    }
}