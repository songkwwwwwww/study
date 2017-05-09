#include <stdio.h>

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )

using namespace std;

const int MAX_N = 1000000;
int N;

int d[MAX_N + 3];

int solve(int n){
    // base case
    if(n == 1)
	return 1;

    int& ret = d[n];
    if(ret != -1)
	return ret;

    int temp;
    if(n & 1){
	temp = solve(n * 3 + 1);
    }
    else{
	temp = solve(n / 2);
    }
    return ret = MAX(n, temp);
}

int main(){
    freopen("3943.txt", "r", stdin);
//    for(int i = 0; i < MAX_N; i++){
//	d[i] = -1;
//    }

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
	int n;
	scanf("%d", &n);
	
	int ans = 1;
	while(n != 1){
	    ans = MAX(ans, n);
	    n = n & 1 ? n * 3 + 1 : n / 2;
	}
	
	printf("%d\n", ans);
//	printf("%d\n", solve(n));
    }
}
