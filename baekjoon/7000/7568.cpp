#include <stdio.h>

const int MAX_N = 50;
int N;

struct point{
    int x, y;
};

point a[MAX_N + 3];

int main(){
    freopen("7568.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
	scanf("%d %d", &a[i].x, &a[i].y);
    }
    for(int i = 0; i < N; i++){
	int count = 0;
	for(int j = 0; j < N; j++){
	    if(i == j)
		continue;

	    if(a[i].x < a[j].x && a[i].y < a[j].y)
		count++;
	}
	printf("%d%c", count + 1, i == N - 1 ? '\n' : ' ');
    }
}
