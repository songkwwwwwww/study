#include <stdio.h>

int main(){
    freopen("10797.txt", "r", stdin);
    int N, ans = 0;
    scanf("%d", &N);
    for(int i = 0; i < 5; i++){
	int n;
	scanf("%d", &n);
	if(n == N)
	    ans++;
    }
    printf("%d\n", ans);
}
