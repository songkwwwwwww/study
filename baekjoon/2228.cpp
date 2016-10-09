#include <algorithm>

#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 987654321;

const int MAX_N = 100;
int N, M;
int a[MAX_N + 1];
int ps[MAX_N + 1];
int d[MAX_N + 1][MAX_N + 1];
bool c[MAX_N + 1][MAX_N + 1];

int solve(int index, int group){
    if(group == 0) return 0;
    if(index <= 0) return -INF;

    if(c[index][group]) return d[index][group];
    c[index][group] = true;

    int& ret = d[index][group];
    
    // a[index]가 구간에 포함되지 않는 경우
    ret = solve(index - 1, group);

    // a[index]가 구간에 포함되는 경우
    // 이 떄, 해당 구간의 시작이 i 인가?  [i, index]
    for(int i = 1; i <= index; i++){
        ret = max(ret, solve(i - 2, group - 1) + ps[index] - ps[i - 1]);
    }

    return ret; 
}

int main(){
    freopen("2228.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
        ps[i] = ps[i - 1] + a[i];
    }
    printf("%d\n", solve(N, M));
}