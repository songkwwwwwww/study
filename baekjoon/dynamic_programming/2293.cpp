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

*/
int coins[101];
int d[10001];
int main(){
    freopen("2293.txt", "r", stdin);
    // 1 <= n <= 100, 1 <= k <= 10,000
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &coins[i]);
    sort(coins + 1, coins + 1 + n);
    d[0] = 1;
    for(int coin = 1; coin <= n; coin++)
        for(int money = coins[coin]; money <= k; money++)
            d[money] += d[money - coins[coin]];
    printf("%d\n", d[k]);
}