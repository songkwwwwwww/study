#include <cstdio>

using namespace std;

typedef long long ll;

const int MAX_N = 30;



int main(){
    freopen("1720.txt", "r", stdin);
    //setbuf(stdout, NULL);
    ll d[MAX_N + 1];
    ll ans[MAX_N + 1];
    int N;
    scanf("%d", &N);
    d[1] = 1;
    d[2] = 3;
    for(int i = 3; i <= N; i++)
        d[i] = d[i - 1] + d[i - 2] * 2;

    
    ans[1] = 1;
    ans[2] = 3;
    for(int i = 3; i <= N; i++){
        ll t = 0;
        if(N & 1)
            t = d[(N - 1) / 2];
        else
            t = d[N / 2] + d[(N - 2) / 2] * 2;
        ans[i] = (d[i] + t) / 2;
    }

    
    printf("%lld\n", ans[N]);
}