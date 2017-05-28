#include <stdio.h>

const int MAX_N = 30;

bool a[MAX_N +1];

int main(){
    freopen("5597.txt", "r", stdin);

    for(int i = 0; i < 28; i++){
	int n;
	scanf("%d", &n);
	a[n] = true;
    }
    for(int i = 1; i <= 30; i++){
	if(!a[i])
	    printf("%d\n", i);
    }
}
