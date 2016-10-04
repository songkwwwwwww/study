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

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
ll a[1000000];
int main(){
    freopen("11652.txt", "r", stdin);
    int N; // 1 <= N <= 100,0000
    ll num; //
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%lld", &a[i]);
    sort(a, a + N);
    ll ans = a[0];
    int ans_cnt = 1;
    int cnt = 1;
    for(int i = 1; i < N; i++){
        if(a[i] == a[i - 1])
            cnt++;
        else
            cnt = 1;
        
        if(ans_cnt < cnt){
            ans = a[i];
            ans_cnt = cnt;
        }
    }
    printf("%lld\n", ans);
}