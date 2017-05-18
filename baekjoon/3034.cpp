#include <stdio.h>

int main(){
    freopen("3034.txt", "r", stdin);
    int N, W, H;
    scanf("%d %d %d", &N, &W, &H);
    for(int i = 0; i < N; i++){
	int n;
	scanf("%d", &n);
	if( n * n <= W * W + H * H ){
	    printf("DA\n");

	}
	else{
	    printf("NE\n");
	}
    }
}
