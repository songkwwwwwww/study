#include <stdio.h>

const int MAX_L = 10;
int map[100][100];
int N;

int main(){
    freopen("2563.txt", "r", stdin);
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
	int x, y;
	scanf("%d %d", &x, &y);
	for(int j = 0; j < 10; j++){
	    for(int k = 0; k < 10; k++){
		map[x + j][y + k] = 1;
	    }
	}
    }
    int sum = 0;
    for(int i = 0; i < 100; i++){
	for(int j = 0; j < 100; j++){
	    sum += map[i][j];
	}

    }
    printf("%d\n", sum);
}
