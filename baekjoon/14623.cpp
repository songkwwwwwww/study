#include <stdio.h>

const int MAX_N = 30;

typedef unsigned long long ull;


char a[MAX_N + 3], b[MAX_N + 3];
int c, d;
int e[MAX_N * 2 + 3];

int main(){
    freopen("14623.txt", "r", stdin);
    scanf("%s", a);
    scanf("%s", b);
    for(c = 0; a[c]; c++);
    for(d = 0; b[d]; d++);
    for(int i = 0; i < d; i++){
	int j = d - i - 1;
	for(int k = 0; k < c; k++){
	    e[i + k] += (a[c - 1 - k] - '0') * (b[j] - '0');
	}
    }
    for(int i = 0; i < MAX_N * 2 + 1; i++){
	if(e[i] >= 2){
	    e[i + 1] += (e[i] / 2);
	    e[i] = e[i] % 2;
	}
    }
    int l;
    for(l = MAX_N * 2 + 1; l >= 0; l--){
	if(e[l] == 1)
	    break;
    }
    for(; l >= 0; l--){
	printf("%d", e[l]);
    }
    printf("\n");
}
