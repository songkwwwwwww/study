#include <stdio.h>


const int MAX_N = 15;

char str[5][MAX_N + 1];
int len[5];

int main(){
    freopen("10798.txt", "r", stdin);
    
    for(int i = 0; i < 5; i++){
	scanf("%s", str[i]);
	for(len[i] = 0; str[i][ len[i] ]; len[i]++)
	    ;
    }
    for(int j = 0; j < 15; j++){
	
	for(int i = 0; i < 5; i++){
	    if(j < len[i])
		printf("%c", str[i][j]);
	}
    }
    printf("\n");
}
