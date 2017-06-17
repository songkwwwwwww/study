#include <stdio.h>

const int MAX_N = 50;
const int MAX_M = 50;
int N, M;

char m[MAX_N][MAX_M + 1];

int main(){
    freopen("1018.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
	scanf("%s", m[i]);
    }
    int a = 1000000007;
    for(int i = 0; i <= N - 8; i++){
	for(int j = 0; j <= M - 8; j++){
	    int b = 0, c = 0;
	    int count = 0;
	    for(int k = 0; k < 8; k++){
		for(int l = 0; l < 8; l++){

		    int d = (i + k) + j + l;
		    char e = m[i + k][j + l];
		    //
		    if(d & 1){
			// b
			b += (e == 'W' ? 1 : 0);

			// w
			c += (e == 'B' ? 1 : 0);
		    }
		    else{
			// w
			b += (e == 'B' ? 1 : 0);

			// b
			c += (e == 'W' ? 1 : 0);
		    }
		}
	    }
	    b = b < c ? b : c;
	    a = a < b ? a : b;
	}
    }
    printf("%d\n", a);
}
