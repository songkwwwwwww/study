#include <stdio.h>

const int MAX_N = 100;

char A[MAX_N +3];
char B[MAX_N +3];

int main(){
    freopen("2935.txt", "r", stdin);
    char c;
    int a = 0, b = 0;

    scanf("%s", A);
    for(a = 0; A[a]; a++)
	;

    scanf(" %c", &c);
    scanf("%s", B);
    for(b = 0; B[b]; b++)
	;


    if(c == '+'){
	int gap = a - b < 0 ? b - a : a - b;
	for(int i = 0; i < (a > b ? a : b); i++){
	    printf("%d", (i == 0 ? 1 : 0) + (i == gap));
	}
	printf("\n");
    }
    else{ // C == '*'
	printf("1");
	for(int i = 0; i < a + b - 2; i++){
	    printf("0");
	}
	printf("\n");
    }

}
