#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAX_N = 200;
const ll MOD = 100000;

int N;
ll d[MAX_N][MAX_N];

char str[MAX_N + 1];
char open[4] = "[{(";
char close[4] = "]})";
bool flag;

ll solve(int i, int j){
    // base case
    if(i > j) return 1;

    ll& ret = d[i][j];
    if(ret != -1) return ret;
    ret = 0;
    for(int k = i + 1; k <= j; k += 2){
        for(int p = 0; p < 3; p++){
            if(str[i] == open[p] || str[i] == '?'){
                if(str[k] == close[p] || str[k] == '?'){
                    ret += (solve(i + 1, k - 1) * solve(k + 1, j));
                    if(ret >= 100000) flag = true;
                    ret %= MOD;
                }
            }
        }
    }
    return ret;
}

int main(){
    freopen("3012.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    scanf("%s", str);
    memset(d, -1, sizeof(d));
    ll ans = solve(0, N - 1);
    if(flag)
        printf("%05lld\n", ans);
    else
        printf("%lld\n", ans);
}