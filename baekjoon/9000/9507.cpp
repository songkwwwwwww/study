//@author songkwwwwwww
/*

@problem title
Generations of Tribbles
(problem #9507)

@problem  url
https://www.acmicpc.net/problem/9507

@reference

*/

#include <iostream>
#include <cstdio>
#include <cstring>

//#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MAX_LENGTH 4001
#define ll long long int

ll cache[69];
ll koong(int n) { // 0 <= n <= 67
	ll& ret = cache[n];
	if (ret != -1) return ret;

	if (n < 2) {
		ret = 1;
	}
	else if (n == 2) {
		ret = 2;
	}
	else if (n == 3) {
		ret = 4;
	}
	else if (n > 3) {
		ret=koong(n - 1)+koong(n - 2)+koong(n - 3)+koong(n - 4);
	}
	return ret;
}

int main() {
	if (freopen("9507.txt", "r", stdin) == NULL)
		printf("fileopen failed!\n");

	
	int TC, n;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		printf("%lld\n", koong(n));
	}
	return 0;
}