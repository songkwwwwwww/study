#include <stdio.h>


int main(){
    freopen("10984.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++){
	int N, sum = 0;
	double ans = 0;
	scanf("%d", &N);
	for(int n = 1; n <= N; n++){
	    int c;
	    double g;
	    scanf("%d %lf", &c, &g);
	    sum += c;
	    ans += (c * g);
	}
	printf("%d %.1lf\n", sum, ans / sum);
    }
}
