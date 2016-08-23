#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


int main(){
    freopen("2110.txt", "r", stdin);

    // N : 집의 개수, C : 공유기의 개수
    // 2 <= N <= 20,0000
    // 2 <= C <= N
    // x_i 집의 좌표의 범위 : 1<= x_i <= 10,0000,0000
    int N, C; 
    int a[200000];

    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);    

 
    int l = 1, r = a[N-1] - a[0], m;
    while(l <= r){
        m = (l + r) / 2;
        int cnt = 1;
        int last = a[0];
        for(int i = 1; cnt <= C && i < N; i++)
            if(a[i] - last >= m){
                cnt++;
                last = a[i];
            }
                
        if(cnt < C)
            r = m - 1;
        else // cnt >= C
            l = m + 1;
    }
    printf("%d\n", l - 1);
}