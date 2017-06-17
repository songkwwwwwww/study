#include <stdio.h>

#define MIN(x, y) ( x < y ? x : y )

const int MAX_N = 50;
int N;

char a[MAX_N + 3], b[MAX_N + 3];
int c, d;

int main(){
    freopen("1120.txt", "r", stdin);
    scanf("%s %s", a, b);
    for(c = 0; a[c]; c++);
    for(d = 0; b[d]; d++);
    int s = 1000000007;
    for(int i = 0; i <= d - c; i++){
	int t = 0;
	for(int j = 0; j < c; j++){
	    if(a[j] != b[i + j]){
		t++;
	    }
	}
	s = s < t ? s : t;
    }
    printf("%d\n", s);
}
