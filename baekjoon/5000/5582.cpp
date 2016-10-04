//@author songkwwwwwww
/*

@problem title
Longest Common Subsequence
(problem #5582)

@problem  url
https://www.acmicpc.net/problem/5582

@reference
http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/

*/

#include <iostream>
#include <cstdio>
#include <cstring>

//#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MAX_LENGTH 4001

char s1[MAX_LENGTH + 1], s2[MAX_LENGTH + 1];
int dp[MAX_LENGTH][MAX_LENGTH];

int main() {
	if (freopen("5582.txt", "r", stdin) == NULL)
		printf("fileopen failed!\n");

	
	scanf("%s %s", s1 + 1, s2 + 1);
	int m, n, result = 0;
	m = strlen(s1 + 1);
	n = strlen(s2 + 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) 
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				
				if (dp[i][j] > result) 
					result = dp[i][j];
		}
	}
	printf("%d\n", result);
	return 0;
}