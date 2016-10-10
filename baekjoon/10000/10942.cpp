#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 2000;
const int MAX_M = 1000000;
int N, M;
int S, E;
int a[MAX_N];
//int d[MAX_N][MAX_N];
bool d[MAX_N][MAX_N];

/*
    d[i][j] : [i, j] 까지의 수열이 팰린드롬인지
*/
/*
int solve(int i, int j){
    // base case
    // 길이가 1이면 팰린드롬
    if(i == j) return 1;
    // 길이가 2이면 같은지 확인
    if(i + 1 == j) return a[i] == a[j];

    int& ret = d[i][j];
    if(ret != -1) return ret;

    // 길이가 3이상인 경우
    if(a[i] != a[j]) return ret = 0;

    return ret = solve(i + 1, j - 1);
}
*/

int main(){
    freopen("10942.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    //memset(d, -1, sizeof(d));
        // 길이가 1인 경우
    for(int i = 0; i < N; i++)
        d[i][i] = true;
    
    
    // 길이가 2인 경우
    for(int i = 1; i < N; i++)
        if(a[i - 1] == a[i])
            d[i - 1][i] = true;
    
    // 길이가 3인 경우 ~
    for(int k = 3; k <= N; k++){
        for(int i = 0; i + k - 1 < N; i++){
            if(a[i] == a[i + k - 1] && d[i + 1][i + k - 2])
                d[i][i + k - 1] = true;
        }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &S, &E);
        //printf("%d\n", solve(S - 1, E - 1));
        printf("%d\n", d[S - 1][E - 1]);
    }

}