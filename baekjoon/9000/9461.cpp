#include <cstdio>
#include <cstring>

typedef long long ll;

int main(){
	freopen("9461.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	int n; // 1<= n <=100 
	ll dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

	memset(dp + 11, -1, sizeof(ll) * 90);


	int lastindex = 10;

	for(int i = 0; i < TC; i++){
		scanf("%d", &n);
		if(dp[n] != -1){
			printf("%lld\n", dp[n]);
		}
		else{
			for(int j = lastindex; j <= n; j++, lastindex++){
				dp[j] = dp[j - 1] + dp[j - 5];
			}
			printf("%lld\n", dp[n]);
		}
	}

}
