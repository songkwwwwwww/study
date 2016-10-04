#include <cstdio>

int max(int a, int b){
	return (a > b) ? a : b;
}

int n; // 1<= n <= 5,000
int m; // 0.01 <= m <= 100.00 
// -> 1 <= m <= 10,000

int calories[5001];
int prices[5001];
int d[5001][10001];


int main(){
	freopen("4781.txt", "r", stdin);
	int temp, max_count, max_calories;
	double p;
	scanf("%d %lf", &n, &p);
	m =(int)(p * 100);
	while(n && m){
		if(n == 0 && m == 0) break;

		for(int i = 1; i <= n; i++){
			scanf("%d %lf", &calories[i], &p);
			prices[i] = (int)(p * 100);
		}
		for(int j = 0; j <= m; j++) d[0][j] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= m; j++){
				
				

				if(prices[i] <= j){
					max_count = j / prices[i];
					max_calories = d[i-1][j - prices[i]];
					for(int k = 2; k <= max_count; k++){
						if(d[i - 1][j - prices[i] * k] > max_calories)	
							max_calories = d[i - 1][j - prices[i] * k];
					}
					d[i][j] = max(d[i-1][j], calories[i] + max_calories);
				}
				else
					d[i][j] = d[i - 1][j];
			}
		}
		printf("%d\n", d[n][m]);
		scanf("%d %lf", &n, &p);
		m =(int)(p * 100);
	}
}
