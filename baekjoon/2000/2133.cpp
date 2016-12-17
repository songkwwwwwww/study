#include <cstdio>
#include <cstring>

const int MAX_N = 30;

int N;
int d[MAX_N + 3][8];

int main(){
    freopen("2133.txt", "r", stdin);

    scanf("%d", &N);
    printf("N : %d\n", N); 
    d[0][7] = 1;
    for(int i = 1; i <= N; i++){
	d[i][0] = d[i - 1][7];
	d[i][1] = d[i - 1][5];
	d[i][2] = d[i - 1][6];
	d[i][3] = d[i - 1][4];
	d[i][4] = d[i - 1][3] + d[i - 1][7];
	d[i][5] = d[i - 1][1] + d[i - 1][7];
	d[i][6] = d[i - 1][2];
	d[i][7] = d[i - 1][0] + d[i - 1][4] + d[i - 1][5];
    }
    printf("%d\n", d[N][7]);
}



/*
int n; // 1<= n <= 30
int d[31]; // 
int a[31]; // 



int main(){
	freopen("2133.txt", "r", stdin);
	scanf("%d", &n);
	d[1] = 0;
	d[0] = a[1] = 1;
	
	for(int i = 2; i <= n; i++){
		a[i] = d[i-1] + a[i-2];
		d[i] = d[i-2] + 2 * a[i-1];		
	}
	printf("%d\n", d[n]);
}
*/
