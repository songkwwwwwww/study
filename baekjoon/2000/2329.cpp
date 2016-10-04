/*
	https://www.acmicpc.net/problem/2329
*/

#include <cstdio>


int m, k; // 0 <= m <= 50, 0 <= k <= 128

// D[M][K] = D[M-1][K] * K + D[M-1][K-1] * (2*M - K)
int d[51][129];

int main(){
	freopen("2329.txt", "r", stdin);
	scanf("%d %d", &m, &k);

	d[1][1] = 1;
	d[1][2] = 0;
	d[2][1] = 1;


	for(int i = 2; i <= m; i++){
		for(int j = 1; j <= k; j++ ){
			d[i][j] = d[i-1][j] * j + d[i-1][j-1] * (2*i - j);
		}
	}
	printf("%d", d[m][k]);
}
