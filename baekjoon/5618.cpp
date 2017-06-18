#include <stdio.h>

int N;
int a[3];
int b, c, d;
void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int gcd(int a, int b){
    if(a < b)
	swap(a, b);

    while(b){
	int r = a % b;
	a = b;
	b = r;
    }
    return a;
}

int main(){
    freopen("5618.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
	scanf("%d", &a[i]);
    }
    if(N == 2){
	d = gcd(a[0], a[1]);	
    }
    else{
	b = gcd(a[0], a[1]);
	c = gcd(a[0], a[2]);
	d = gcd(b, c);
    }
    for(int i = 1; i <= d; i++){
	if(d % i == 0)
	    printf("%d\n", i);
    }
}
