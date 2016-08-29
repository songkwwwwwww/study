#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

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
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 
각 테스트 케이스의 첫 번째 줄에는 동전의 가지 수 N(1 ≤ N ≤ 20)이 주어지고 

두 번재 줄에는 N가지 동전의 각 금액이 오름차순으로 정렬되어 주어진다. 
각 금액은 정수로서 1원부터 10000원까지 있을 수 있으며 공백으로 구분된다. 

세 번째 줄에는 주어진 N가지 동전으로 만들어야 할 금액 M(1 ≤ M ≤ 10000)이 주어진다.

편의를 위해 방법의 수는 231 - 1 보다 작다고 가정해도 된다.

출력
각 테스트 케이스에 대해 입력으로 주어지는 N가지 동전으로 
금액 M을 만드는 모든 방법의 수를 한 줄에 하나씩 출력한다.
*/
/*
 처리과정
 dp[k] : k금액까지의 경우의 수
 dp[k] += dp[k-coin[j]]
*/
int coins[21]; 
int main(){
    freopen("9084.txt", "r", stdin);
    int TC, N, M; 
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);   
        for(int i = 1; i <= N; i++) scanf("%d", &coins[i]);
        scanf("%d", &M);
        
        int d[10001] = {0};
        d[0] = 1;

        for(int coin = 1; coin <= N; coin++){    
            for(int money = coins[coin]; money <= M; money++){
                d[money] += d[money - coins[coin]];
            }
        }
        printf("%d\n", d[M]);
    }
}