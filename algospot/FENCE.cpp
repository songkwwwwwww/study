#include <iostream>
#include <cstdio>

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)

int h[20000]; // heights
int n; // 1<= n <= 20000
// [left, right] 구간에서 찾아낼 수 있는 가장 큰 사각형의 넓이를 반환한다.
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
    freopen("FENCE.txt", "r", stdin);

    int TC; // TC <= 50
    scanf("%d", &TC);  
    for(int i = 0; i < TC; i++){
        scanf(" %d", &n);
        for(int j = 0; j < n; j++){
            scanf("%d", &h[j]);
        }
        printf("%d\n", solve(0, n - 1));
    }
}

