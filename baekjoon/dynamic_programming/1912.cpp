#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

int a[100001];
/*
 처리과정
 dp[n] : n번째 수로 끝나는 가장 큰 연속합
 dp[n] = max(a[n],dp[n-1]+a[n])
 1. 해당 위치까지 연속합을 구한다.
 2. 현재값과 새로운 값(연속합 + 현재값)을 비교한다.
 3. 최대값을 저장한다.
 4. dp배열의 최대값을 찾아 출력한다.
 5. 끝낸다.
*/
int main(){
    freopen("1912.txt", "r", stdin);
    int n, max, dp; // 1 <= n <= 10,0000
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    max = dp = a[1];
    for(int i = 2; i <= n; i++){
        dp = MAX(dp + a[i], a[i]);
        if(max < dp) max = dp;
    }
    printf("%d\n", max);
}