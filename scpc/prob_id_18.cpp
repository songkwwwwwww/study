/*
    https://www.codeground.org/practice/practiceProbView.do?probId=18
*/
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int inf = 1000000000;


int TC, M, N, K;
int a[101][101]; // array
int d[11][101][101]; // dp-array


int abs(int x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}
int go(int water, int i, int j) {
    if (d[water][i][j] != -1) {
        return d[water][i][j];
    }
    if (i == N-1 && j == M-1) {
        if (water == 0) {
            return 0;
        } else {
            return inf;
        }
    }
    int &ans = d[water][i][j];
    ans = inf;
    if (j+1 < M) {
        int cur = abs(a[i][j]);
        int next = abs(a[i][j+1]);
        int diff = abs(next-cur);
        if (a[i][j+1] < 0) {
            if (water-1 >= 0) {
                ans = min(ans, go(water-1, i, j+1) + diff);
            } else {
                ans = min(ans, go(water, i, j+1) + diff);
            }
        } else {
            ans = min(ans, go(water, i, j+1) + diff);
        }
    }
    if (i+1 < N) {
        int cur = abs(a[i][j]);
        int next = abs(a[i+1][j]);
        int diff = abs(next-cur);
        if (a[i+1][j] < 0) {
            if (water-1 >= 0) {
                ans = min(ans, go(water-1, i+1, j) + diff);
            } else {
                ans = min(ans, go(water, i+1, j) + diff);
            }
        } else {
            ans = min(ans, go(water, i+1, j) + diff);
        }
    }
    return ans;
}


int main(){
    freopen("prob_id_18.txt", "r", stdin);
    scanf("%d", &TC);

    for(int tc = 1; tc <= TC; tc++){
        // row = N, col = M;
        scanf("%d %d %d", &M, &N, &K); // 1 <= M, N <= 100, 0 <= K <= 10
        M++; N++;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf("%d", &a[i][j]); // 1<= |a[i][j]| <= 100
            }
        }
        memset(d, -1, sizeof(d));
        printf("Case #%d\n%d\n", tc, go(K, 0, 0));       
    }
}