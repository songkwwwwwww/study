#include <stdio.h>

int main(){
    freopen("5596.txt", "r", stdin);
    int a = 0;
    for(int i = 0; i < 2; i++){
	int t = 0;
	for(int j = 0; j < 4; j++){
	    int n;
	    scanf("%d", &n);
	    t += n;
	}
	a = a < t ? t : a;
    }
    printf("%d\n", a);
}
