#include <stdio.h>

#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

const int INF = 1000000007;
const int MAX_N = 5000;
int N;

int a[2] = {3, 5};
int d[MAX_N + 3];

int main(){
    freopen("2839.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i <= N; i++)
	d[i] = INF;
    d[0] = 0;
    for(int i = 0; i < 2; i++){
	for(int j = a[i]; j <= N; j++){
	    d[j] = MIN( d[j], d[j - a[i]] + 1 );
	}
    }
    
    int ans = d[N];
    if(ans == INF)
	ans = -1;
    printf("%d\n", ans);
}
