#include <cstdio>
#include <limits>
#include <cstring>

typedef long long ll;

const ll MINUS = std::numeric_limits<ll>::min();

int n, m; // 1 <= n, m <= 100
int A[100], B[100];
int dp[101][101];

template<typename T>
T max(T a, T b){
	if(a > b)
		return a;
	else
		return b;
	//return (a) > (b) ? (a) : (b);
}

int jlis(int index_a, int index_b){

	int& ret = dp[index_a + 1][index_b + 1];
	if(ret != -1) return ret;

	ret = 2;
	ll a = (index_a == -1 ? MINUS : A[index_a]);
	ll b = (index_b == -1 ? MINUS : B[index_b]);
	ll max_element = max(a, b);

	for(int next_a = index_a + 1; next_a < n; next_a++)
		if(max_element < A[next_a])
			ret = max(ret, 1 + jlis(next_a, index_b));

	for(int next_b = index_b + 1; next_b < m; next_b++)
		if(max_element < B[next_b])
			ret = max(ret, 1 + jlis(index_a, next_b));
	return ret;
}

int main(){
	freopen("JLIS.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for(int i = 0; i < TC; i++){
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &n, &m);
		for(int j = 0; j < n; j++)
			scanf("%d", &A[j]); 
		for(int j = 0; j < m; j++)
			scanf("%d", &B[j]); 
		printf("%d\n", jlis(-1,-1) - 2 );
	}
}
