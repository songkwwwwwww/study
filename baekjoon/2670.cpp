#include <stdio.h>

#define MAX(x, y) (x < y ? y : x)

const int MAX_N = 10000;
int N;

double a[MAX_N + 3];

int main(){
    freopen("2670.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
	scanf("%lf", &a[i]);
    }
    double c = 0, d = a[1];
    for(int i = 2; i <= N; i++){
	d = MAX(a[i], d * a[i]);
	c = c < d ? d : c;
    }
    printf("%lf\n", c);
}
