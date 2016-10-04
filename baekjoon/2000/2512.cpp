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

*/
int N; // 3 <= N <= 10000
int a[10000];
int M;

int check(int mid){
    int total = M;
    for(int i = 0; i < N; i++){
        if(a[i] < mid)
            total -= a[i];
        else // a[i] >> mid
            total -= mid;
    }
    return total >= 0 ? 1 : 0;
}

int main(){
    freopen("2512.txt", "r", stdin);
    scanf("%d", &N);
    int m, l = 0, r = 0, sum = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
        if(a[i] > r) r = a[i];
        sum += a[i];
    }
    
    scanf("%d", &M);
    int ans = 0;
    if(sum > M){
        while(l <= r){
            m = (l + r) / 2;
            if(check(m)){
                ans = MAX(ans, m);
                l = m + 1;
            }
            else{
                r = m - 1; 
            }
        }
    }
    else{
        ans = r;
    }
    printf("%d\n", ans);

}