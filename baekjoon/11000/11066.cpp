#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 987654321;
const int MAX_K = 500;
int K;
int a[MAX_K + 1];
int ps[MAX_K + 1];
vvi d;

int solve(int l, int r){
    //base case
    if(r <= l) return 0;

    int& ret = d[l][r];
    if(ret != -1) return ret;
    ret = INF;
    for(int k = l; k + 1 <= r; k++){
        ret = min(ret, solve(l, k) + solve(k + 1, r) + ps[r] - ps[l - 1]);
    }
    return ret;
}

int main(){
    freopen("11066.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d", &K);
        for(int i = 1; i <= K; i++){
            scanf("%d", &a[i]);
            ps[i] = ps[i - 1] + a[i];
        }
        d = vvi(K + 1, vi(K + 1, -1));
        printf("%d\n", solve(1, K));
    }
}