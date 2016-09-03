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
첫째 줄에 n, m(1 ≤ n, m ≤ 1,000)이 주어진다. 
다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.

출력
첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.
*/
int N, M;
char m[1001][1001];
int d[1001][1001];
int main(){
    freopen("1915.txt", "r", stdin);
    scanf("%d %d", &N, &M);
  
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    
    int max = 0;    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(m[i - 1][j - 1] == '1'){
                d[i][j] = 1 + MIN( MIN(d[i - 1][j], d[i - 1][j - 1]), d[i][j - 1] );
                max = MAX(max, d[i][j]);
            }
        }
    }
    printf("%d\n", max * max);
}

/*
//koosaga's code
int dp[1005][1005];
 
int n, m;
char str[1005];
int main(){
    scanf("%d %d",&n,&m);
    int ret = 0;
    for(int i=1; i<=n; i++){
        scanf("%s",str+1);
        for(int j=1; j<=m; j++){
            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            if(str[j] == '1') dp[i][j]++;
            else dp[i][j] = 0;
            ret = max(ret, dp[i][j]);
        }
    }
    printf("%d",ret * ret);
}
*/
/*
int N, M;
int m[1001][1001];
int d[1001][1001];
int main(){
    freopen("1915.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    int max = 0;
    
    // 너무 느린 입출력과 많은 메모리
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            scanf("%1d", &m[i][j]);
            max = max | m[i][j];
        }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(m[i][j] == 1){
                d[i][j] = 1 + MIN( MIN(d[i - 1][j], d[i - 1][j - 1]), d[i][j - 1] );
                max = MAX(max, d[i][j]);
            }
        }
    }
    printf("%d\n", max * max);
}
*/