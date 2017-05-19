#include <stdio.h>

#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

int main(){
    freopen("5543.txt", "r", stdin);
    int a[3], b[2];
    for(int i = 0; i < 3; i++){
	scanf("%d", &a[i]);
    }
    for(int i = 0; i < 2; i++){
	scanf("%d", &b[i]);
    }

    int min = 1000000007;
    for(int i = 0; i < 3; i++){
	for(int j = 0; j < 2; j++){
	    int temp = a[i] + b[j] - 50;
	    min = MIN(min, temp);
	}
    }
    printf("%d\n", min);
}
