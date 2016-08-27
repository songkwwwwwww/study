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

int h[100000]; // heights
int n; // 1<= n <= 100000


int solve(int left, int right){
    // base case
    if(left == right) return h[left];

    int mid = (left + right) / 2;
    int ret = MAX(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;
    int height = MIN(h[lo], h[hi]);
    ret = MAX(ret, height * 2);

    while(left < lo || hi < right){
        if(hi < right && (lo == left || h[lo - 1] < h[hi + 1]) ){
            ++hi;
            height = MIN(height, h[hi]);
        }
        else{
            --lo;
            height = MIN(height, h[lo]);
        }
        ret = MAX(ret, height * (hi - lo + 1));
    }
    return ret;

}

int main(){
    freopen("6549.txt", "r", stdin);
    while(true){
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++) scanf("%d", &h[i]);
        printf("%d\n", solve(0, n - 1));
    }
    return 0;
}