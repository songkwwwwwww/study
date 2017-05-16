#include <stdio.h>

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )

using namespace std;

const int MAX_N = 300;
const int MAX_M = 300;

int N, M;
int d[MAX_N + 3][MAX_M + 3];

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int solve(int n, int m){
    // base case
    if(n == 1)
	return m - 1;
    
    int& ret = d[n][m];
    if(ret != -1)
	return ret;

    return ret = 1 + solve(1, m) + solve(n - 1, m);
}

int main(){
    freopen("2163.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    if(N < M)
	swap(N, M);

    for(int i = 0; i <= N; i++){
	for(int j = 0; j <= M; j++){
	    d[i][j] = -1;
	}
    }
    printf("%d\n", solve(N, M));
}
