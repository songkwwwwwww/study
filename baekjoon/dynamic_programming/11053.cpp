#include <cstdio>
#include <cstring>
//#define MAX(a, b) (a) > (b) ? (a) : (b)
int MAX(int a, int b){
	return a > b ? a : b;
}

int n; // 1<= n <= 1,000
int arr[1000];
int dp[1001];


int calc(int index){
	int& ret = dp[index + 1];
	if(ret != -1) return ret;

	ret = 1;
	for(int next = index + 1; next < n; ++next){
		if(index == -1 || arr[index] < arr[next])
			ret = MAX(ret, calc(next) + 1);
	}
	return ret;	
}

int main(){
	freopen("11053.txt", "r", stdin);
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("%d\n", calc(-1) - 1);
}
