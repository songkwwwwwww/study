#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;


int main(){
    freopen("2805.txt", "r", stdin);
    // N : 나무의 수, M : 상근이가 집으로 가져가려고 하는 나무의 길이
    int N, M; // 1 <= N <= 100,0000,    1 <= M <= 20,0000,0000
    scanf("%d %d", &N, &M);
    int a[1000000];

    for(int i = 0; i < N; i++) scanf("%d", &a[i]);    
    int l = 0, r = 1000000000, mid;
    while(l <= r){
        ll result = 0;
        mid = (l + r)/2;
        for(int i = 0; i < N; i++)
            if( a[i] > mid) 
                result += (a[i] - mid);
        
        if(result < M)
            r = mid -1;
        else // result >= M
            l = mid + 1;
    }
    printf("%d\n", l - 1);

}