/*
https://www.acmicpc.net/problem/1977
*/

#include <cstdio>
#include <cmath>

int main(){
	freopen("1977.txt", "r", stdin);

	int M, N; // M <= N <= 10000
	scanf("%d %d", &M, &N);
		
	int root_M = sqrt(M);
	if((root_M * root_M) != M) root_M++;

	int root_N = sqrt(N);

	int sum = 0, count = 0;
	for(int i = root_M; i <= root_N; i++ ){
		sum += (i * i);
		count++;
	}
	if(count == 0) printf("-1\n");
	else printf("%d\n%d\n", sum, root_M * root_M);		
}
