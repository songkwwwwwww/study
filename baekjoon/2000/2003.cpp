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
첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다. 
다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 
각각의 A[x]는 30,000을 넘지 않는 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다.
*/

int N, M;
int A[10000];
int main(){
    freopen("2003.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    int result = 0, sum = 0, s = 0, e = 0;
    while(true){
        if(e == N) break;

        if(sum >= M) sum -= A[s++];
        else sum += A[e++];
        if(sum == M) result++;
    }
    printf("%d\n", result);
}