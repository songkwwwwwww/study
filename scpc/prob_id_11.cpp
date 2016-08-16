/*
	boj problem #

11060

*/

#include <cstdio>

int N; // 1 <= N <= 1,000,000
int arr[1000000]; // 1 <= arr[i] <= 10 0000 0000
int K; // 10 0000 0000

int main(){
	freopen("prob_id_11.txt", "r", stdin);

	int TC; // 1 <= TC <= 5
	scanf("%d", &TC);

	for(int i = 0; i < TC; i++){
		scanf("%d", &N);
		for(int j = 0; j < N; j++){
			scanf("%d", &arr[j]);
		}
		scanf("%d", &K);

		int cur = arr[0];
		int solution = 0;
		for(int j = 1; j < N; j++){
			if(arr[j] - arr[j-1] > K){
				solution = -2;
				break;
			}
			if(cur + K < arr[j]){
				cur = arr[j - 1];
				solution += 1;
			}
		}
		solution += 1;
		printf("Case #%d\n%d\n", i + 1, solution);
	}
}
