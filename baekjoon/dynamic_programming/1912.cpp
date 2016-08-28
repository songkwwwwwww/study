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