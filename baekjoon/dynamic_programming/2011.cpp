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

/*
입력
첫째 줄에 5000자리 이하의 암호가 주어진다.

출력
나올 수 있는 해석의 가짓수를 구하시오. 
정답이 매우 클 수 있으므로, 1000000으로 나눈 나머지를 출력한다.
*/
/*
 처리과정
 dp[n] : n번째까지 나오는 경우의 수
 dp[n] += dp[n-1]  (1<= k <= 9)
          dp[n-2]  (10 <= k <= 26)
*/
const int MOD = 1000000;

char a[5002];
int d[5001];
int main(){
    freopen("2011.txt", "r", stdin);
    scanf("%s ", a + 1);
    int n;
    for(n = 1; a[n]; n++);
    n--;
    //printf("n : %d\n", n);
    d[0] = d[1] = 1;
    for(int i = 2; i <= n; i++){
        int t = a[i] -'0';
        if( 0 < t && t <= 9){
            d[i] += d[i - 1];
            d[i] %= MOD;
        }
        if(a[i - 1] == 0) continue;
        t = (a[i - 1] - '0') * 10 + a[i] - '0';
        if(10 <= t && t <= 26){
            d[i] += d[i - 2];
            d[i] %= MOD;
        }
        
    }
    printf("%d\n", d[n]);
    
}