#include <stdio.h>

int main(){
    freopen("2884.txt", "r", stdin);

    int H, W;
    scanf("%d %d", &H, &W);
    int n = 0;
    if(W < 45)
	n = 1;
    W = (W + 15) % 60;
    H = (H + 24 - n) % 24;
    printf("%d %d\n", H, W);
}

