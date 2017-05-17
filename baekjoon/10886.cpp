#include <stdio.h>


int main(){
    freopen("10886.txt", "r", stdin);

    int N, sum = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
	int n;
	scanf("%d", &n);
	sum += n;
    }
    if(sum > N / 2)
	printf("Junhee is cute!\n");
    else
	printf("Junhee is not cute!\n");

}
