#include <stdio.h>

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int N, M;
char str1[MAX_N + 3], str2[MAX_M + 3];
int d[MAX_N + 3][MAX_M + 3];

int main(){
    freopen("9251.txt", "r", stdin);
    scanf("%s", str1);
    for(N = 0; str1[N]; N++)
	;

    scanf("%s", str2);
    for(M = 0; str2[M]; M++)
	;

    for(int i = 1; i <= N; i++){
	for(int j = 1; j <= M; j++){
	    if(str1[i - 1] == str2[j - 1]){
		d[i][j] = d[i - 1][j - 1] + 1;
	    }
	    else{
		d[i][j] = MAX(d[i - 1][j], d[i][j - 1]);
	    }
	}
    }
    printf("%d\n", d[N][M]);
}
