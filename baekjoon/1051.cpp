#include <stdio.h>

const int MAX_N = 50;
const int MAX_M = 50;
int N, M;

char m[MAX_N][MAX_M + 1];

int main(){
    freopen("1051.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
	scanf("%s", m[i]);
    }

    int O = N < M ? N : M;

    int a = 0;
    for(int i = 0; i < N; i++){
	for(int j = 0; j < M; j++){

	    for(int k = 0; i + k < N && j + k < M; k++){

		if(m[i][j] == m[i][j + k] && m[i + k][j] == m[i + k][j + k] && m[i][j] == m[i + k][j]){
		    a = a < k + 1 ? k + 1 : a;
		}
	    }

	}
    }
    printf("%d\n", a * a);
}
