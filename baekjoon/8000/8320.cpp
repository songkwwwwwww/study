#include <stdio.h>

const int MAX_N = 10000;
int N;


int main(){
    freopen("8320.txt", "r", stdin);
    scanf("%d", &N);
    int ans = 0;
    // i : 직사각형으 한 변의 길이
    for(int i = 1; i * i <= N; i++){
	ans += N / i - i + 1;
    }
    printf("%d\n", ans);
}
