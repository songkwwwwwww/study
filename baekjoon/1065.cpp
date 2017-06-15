#include <stdio.h>

const int MAX_N = 1000;
int N;

int main(){
    freopen("1065.txt", "r", stdin);
    scanf("%d", &N);

    int ans = 99;
    if(N < 100){
	printf("%d\n", N);
	return 0;
    }
    for(int i = 100; i <= N; i++){
	bool flag = true;
	int n = i;
	int a, b, c, d;
	a = (n / 10) % 10;
	d = a - (n % 10);
	n /= 100;
	while(n > 0){ 
	    b = n % 10;
	    c = b - a;
	    if(c != d){
		flag = false;
		break;
	    }
	    a = b;
	    n /= 10;
	}
	if(flag)
	    ans++;
    }
    printf("%d\n", ans);
}
