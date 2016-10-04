#include <cstdio>
#include <cstring>
//#define MAX(a, b) (a) > (b) ? (a) : (b)
int MAX(int a, int b){
	return a > b ? a : b;
}

int n; // 1<= n <= 1,000
int a[1000];
int d[1001];

/*
int calc(int index){
	int& ret = d[index + 1];
	if(ret != -1) return ret;

	ret = 1;
	for(int next = index + 1; next < n; ++next){
		if(index == -1 || arr[index] < arr[next])
			ret = MAX(ret, calc(next) + 1);
	}
	return ret;	
}*/
/*
 처리과정
 dp[n] = n번째 까지의 가장긴 증가하는 부분수열의 길이
 1. 위치의 배열 값을 비교한다.
 2. 현재위치의 값이 더 크다면
    2.1 수열의 크기가 더 큰 경우에만 갱신시킨다.
 3. 가장 큰 값을 출력한다
 4. 끝낸다
*/
int main(){
	freopen("11053.txt", "r", stdin);
	scanf("%d", &n);
	//memset(d, -1, sizeof(d));
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
        d[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
    }
	int ans = 0;
    for(int i = 0; i< n; i++)
        ans = MAX(ans, d[i]);
    
    printf("%d\n", ans);
	//printf("%d\n", calc(-1) - 1);
}
