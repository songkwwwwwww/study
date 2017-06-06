#include <stdio.h>

int A, B;
char C[200];

int main(){
    freopen("14614.txt", "r", stdin);
    scanf("%d %d", &A, &B);
    scanf("%s", C);
    int i = 0, n;
    for(i = 0; C[i]; i++)
	;
    int ans = ( ((C[i - 1] - '0') & 1) == 1 ? A ^ B : A);
    printf("%d\n", ans);
}
