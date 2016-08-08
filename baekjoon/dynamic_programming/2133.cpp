#include <cstdio>

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
