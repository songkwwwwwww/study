#include <stdio.h>

const int MAX_N = 123456;

bool is_prime[MAX_N * 2 + 1];
int prime[MAX_N];
int p = 0;

int main(){
    freopen("4948.txt", "r", stdin);
    for(int i = 0; i <= MAX_N * 2 + 1; i++){
	is_prime[i] = true;
    }

    for(int i = 2; i <= MAX_N * 2 + 1; i++){
	if(is_prime[i]){
	    prime[p++] = i;
	    for(int j = i * 2; j <= MAX_N * 2 + 1; j += i){
		is_prime[j] = false;
	    }
	}
    }

    int N;
    while(scanf("%d", &N) && N != 0){
	int count = 0;
	// N보다 크고 2N보다 작거나 같은 소수의 개수
	for(int i = 0; i < p; i++){
	    if(2 * N < prime[i]) break;

	    if(N < prime[i] && prime[i] <= 2 * N)
		count++;
	}
	printf("%d\n", count);
    }
}
