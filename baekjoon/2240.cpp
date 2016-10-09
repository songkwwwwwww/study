#include <algorithm>

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_T = 1000;
const int MAX_W = 30;
int T, W;
int a[MAX_T + 1];
int d[MAX_T + 1][MAX_W + 1];

// 처음에는 0번 나무에서 시작한다
// change가 홀수이면 1번나무에 위치하고
// 짝수이면 0번 나무(제자리)에 위치한다.
int solve(int time, int change){
    // base case
    if(time == T && change <= W) return 0;
    if(change > W) return -987654321;

    int& ret = d[time][change];
    if(ret != -1) return ret;

    int cur = (a[time] == (change & 1));
    
    // 움직이지 않는 경우 + 움직이는 경우
    ret = max(solve(time + 1, change), solve(time + 1, change + 1)) + cur;

    return ret;
}

int main(){
    freopen("2240.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &T, &W);
    for(int i = 0; i < T; i++){
        scanf("%d", &a[i]);
        a[i] = a[i] - 1;
    }
    memset(d, -1, sizeof(d));
    printf("%d\n", max(solve(0, 0), solve(0, 1)));
}