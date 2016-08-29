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
int d[100001];

int main(){
    freopen("2294.txt", "r", stdin);
    int n, k; // (1 ≤ n ≤ 100, 1 ≤ k ≤ 100,000)
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &coins[i]);
    
    for(int money = 1; money <= k; money++){
        d[money] = 0x7fffffff;
        for(int coin_type = 1; coin_type <= n; coin_type++){
            if(money >= coins[coin_type])
                d[money] = MIN( d[money], d[money - coins[coin_type]] + 1);
        }
    }
    printf("%d\n", d[k]);
}