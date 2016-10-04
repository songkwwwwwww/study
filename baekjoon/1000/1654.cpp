#include <cstdio>

typedef long long ll;

using namespace std;

int main(){
    freopen("1654.txt", "r", stdin);
    // 이미 가지고 있는 랜선의 개수 K, 필요한 랜선의 개수 N
    int K, N, a[10000]; // 1 <= K <= 10000,   1 <= N <= 100,0000,     K <= N
    scanf("%d %d", &K, &N);
    int max_size = 0;
    for(int i = 0; i < K; i++){
        scanf("%d", &a[i]);
    }
    ll l = 1, r = (1ll << 31) - 1, mid;
    ll ans = 0;
    while( l <= r ){
        mid = (l + r) / 2;
        int cnt = 0;
        for(int i = 0; i < K; i++) cnt += a[i] / mid;

        if(cnt < N) r = mid -1;
        else l = mid + 1;
    }
    printf("%lld\n", l - 1);
}