//@author songkwwwwwww

/*

@problem title
Wheel of Numbers
(problem #11504)

@problem  url
( https://www.acmicpc.net/problem/11504 )


*/

#include <iostream>
#include <cstdio>
#include <cstring>

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX_LENGTH 9


int N, M;  // 1 <= N <= 100, 1 <= M <= 9, M <= N
int X[MAX_LENGTH], Y[MAX_LENGTH];
int wheels[100];


// X <= Z <= Y
int my_func() {
	int x = 0, y = 0, count = 0;
	for (int i = 0; i < M; i++) {
		x += x * 10 + X[i];
		y += y * 10 + Y[i];
	}
	for (int i = 0; i < N; i++) {
		int z = 0;
		for (int j = 0; j < M; j++) {
			z += z * 10 + wheels[(i + j) % N];
		}
		if (x <= z && z <= y)
			count++;
	}
	return count;
}

int main() {
	using std::cout;
	using std::endl;

	if (freopen("11504.txt", "r", stdin) == NULL)
		cout << "fileopen failed" << endl;


	int TC;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%d %d", &N, &M);
			// input for X, Y
		for (int k = 0; k < M; k++)
			scanf("%d", &X[k]);

		for (int k = 0; k < M; k++)
			scanf("%d", &Y[k]);

		for (int k = 0; k < N; k++)
			scanf("%d", &wheels[k]);
		printf("%d\n", my_func());
	}
	return 0;
}
