

#include <cstdio>

int arr[100];

int main(){
	freopen("9550.txt", "r", stdin);

	int TC;
	scanf("%d", &TC);
	for(int tc = 1; tc <= TC; tc++){
		int N, K, count = 0; // 1 <= N, K <= 100
		scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
			count += (arr[i] / K);
		}
		printf("%d\n", count);
	}	
}
