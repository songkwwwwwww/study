#include <stdio.h>

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )

const int MAX_N = 200;
int N;

int a[MAX_N + 3];
int d[MAX_N + 3];

int main(){
    freopen("2631.txt", "r", stdin);

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
	scanf("%d", &a[i]);
    }
    int ans = 1;
    for(int i = 0; i < N; i++){
	d[i] = 1;
	
	for(int j = 0; j < i; j++){
	    if(a[j] < a[i] && d[j] + 1 > d[i])
		d[i] = d[j] + 1;
	}
	ans = MAX(ans, d[i]);
    }
    printf("%d\n", N - ans);
}
