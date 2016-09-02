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
 n*n개의 수가 주어진다(1<=n<=20).

  이때 겹치지 않는 각 열과 각 행에서 수를 하나씩 뽑는다. 
  (즉, 총 n개의 수를 뽑을 것이다. 그리고 각 수는 100 이하의 값이다.) 
  
  이 n개의 수의 합을 구할 때 최솟값을 구하시오.

입력  
    첫 줄에 n이 입력된다. 다음 줄 부터 n+1줄 까지 n개씩의 정수가 입력된다.
    ex)
        3 
        1 2 5 
        2 4 3 
        5 4 3

출력  
    구한 최소 합을 출력한다.
    ex)
        7
*/
const int INF = 0x7fffffff;
int n;
int m[21][21];
int d[1<<20];

/*
    row행이면서 각 열들이 bit처럼 체크되었을 때
    최소 합을 반환한다.
*/
int solve(int row, int bit){
    // base case
    if(row == n) return 0;
    int& ret = d[bit];
    if(ret != -1) return ret;
    ret = INF;
    // row 행에서 모든 열에 놓아 본다.
    for(int i = 0; i < n; i++){
        // 해당 열이 방문된 적이 없다면 선택할 수 있다.
        if((bit & (1 << i)) == 0)
            ret = min(ret, solve(row + 1, bit | (1 << i)) + m[row][i]);
    }
    return ret;
}

int main(){
    freopen("minimum_sum.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
    
    memset(d, -1, sizeof(d));
    
    printf("%d\n", solve(0, 0));
}