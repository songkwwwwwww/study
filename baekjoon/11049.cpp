#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;

const int MAX_N = 500;
const int MAX_R = 500;
const int MAX_C = 500;
int N, R, C;
int mat[MAX_N][2];
int d[MAX_N + 1][MAX_N + 1];

int solve(int l, int r){
    // base case
    if(l == r) return 0;
    if(l + 1 == r) return mat[l][0] * mat[l][1] * mat[r][1];
    
    int& ret = d[l][r];
    if(ret != -1) return ret;

    ret  = INF;
    for(int k = l; k + 1<= r; k++){
        int left = solve(l, k);
        int right = solve(k + 1, r);
        ret = min(ret, left + right + mat[l][0] * mat[k][1] * mat[r][1]);
    }

    return ret;
}

int main(){
    freopen("11049.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &mat[i][0], &mat[i][1]);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, N - 1));
}