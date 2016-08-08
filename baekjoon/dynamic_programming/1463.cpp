#include <iostream>
#include <cstdio>
#include <cstring>

/*

1�� �����
( https://www.acmicpc.net/problem/1463 )

@problem
���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

X�� 3���� ������ ��������, 3���� ������.
X�� 2�� ������ ��������, 2�� ������.
1�� ����.
���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּҰ��� ����Ͻÿ�.

�Է�
ù° �ٿ� 1���� ũ�ų� ����, 10^6���� �۰ų� ���� �ڿ��� N�� �־�����.

���
ù° �ٿ� ������ �ϴ� Ƚ���� �ּҰ��� ����Ѵ�.

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
