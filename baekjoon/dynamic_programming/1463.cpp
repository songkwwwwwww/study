#include <iostream>
#include <cstdio>
#include <cstring>

/*

1로 만들기
( https://www.acmicpc.net/problem/1463 )

@problem
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만드려고 한다. 연산을 사용하는 횟수의 최소값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최소값을 출력한다.

@input
10
@output
3

*/

#define INFINITE 987654321

int min(int x, int y) {
	return x < y ? x : y;
}



int cache[1000001];
/*
	Memoization (Top Down):
	assume that a cache array is initialized to -1
*/
int calc(int n) {

	// base case
	if (n == 1)	return 0;


	int& ret = cache[n];
	// is it cached?
	if (ret != -1) return ret;

	int result = INFINITE;

	if ((n % 3) == 0 ) 
		result = min(result, 1 + calc(n / 3));
	

	if ( (n % 2) == 0 ) 
		result = min(result, 1 + calc(n / 2));
	

	ret = min(result, 1 + calc(n - 1));
	return ret;
}

int main() {
	using std::cout;
	using std::endl;

	if (freopen("1463.txt", "r", stdin) == NULL)
		cout << "fileopen failed" << endl;
	
	int N;
	scanf("%d", &N);// 1 <= N <= 1,000,000
	memset(cache, -1, sizeof(cache));

	printf("%d\n", calc(N));
	return 0;
}
