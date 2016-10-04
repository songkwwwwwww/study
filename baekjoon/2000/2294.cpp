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
문제
n가지 종류의 동전이 있다. 
각각의 동전이 나타내는 가치는 다르다. 
이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
그러면서 동전의 개수가 최소가 되도록 하려고 한다. (각각의 동전은 몇개라도 사용할 수 있다.)

입력
첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 
다음 n개의 줄에는 각각의 동전의 가치가 주어진다.

출력
첫째줄에 사용한 동전의 최소 개수를 출력한다. 
불가능한 경우에는 -1을 출력한다.
*/

const int IMPOSSIBLE = 987654321;
int N, K; // (1 ≤ n ≤ 100, 1 ≤ k ≤ 100,000)

int coins[101];
int d[101][100001];

/*
start 번째 동전부터 사용하여 money원을 만드는 최소 횟수를 반환.
*/
int solve(int start, int money){
    // base case
    if(start == N) return (money == 0 ? 0 : IMPOSSIBLE);

    int& ret = d[start][money];
    if(ret != -1) return ret;

    ret = solve(start + 1, money);
    if(money >= coins[start]) ret = MIN(ret, solve(start, money - coins[start]) + 1);
    return ret;
}

int main(){
    freopen("2294.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d", &coins[i]);
    
    memset(d, -1, sizeof(d));

    int result = solve(0, K);
    if(result == IMPOSSIBLE) printf("-1\n");
    else printf("%d\n", result);
}