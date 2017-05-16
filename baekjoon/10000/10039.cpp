#include <stdio.h>


int main(){
    freopen("10039.txt", "r", stdin);
    int sum = 0;
    for(int i = 0; i < 5; i++){
	int n;
	scanf("%d", &n);
	n = n < 40 ? 40 : n;
	sum += n;
    }
    printf("%d\n", sum / 5);
}
