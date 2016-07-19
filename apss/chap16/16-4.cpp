#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


#define MAXN 12
#define MAXL 10
#define MAXM 10

const int INF = 987654321;

int n, k, m ,l;

// prerequisite[i] = i 번 째 과목의 선수 과목의 집합
int prerequisite[MAXN];

// classes[i] = i 번 째 학기에 개설되는 과목의 집합
int classes[MAXL];
int cache[MAXM][1<<MAXN];

// n의 이진수 표현에서 켜진 비트의 수를 반환한다.
// __builtin_popcount(toppings)

void setDefault(){
	memset(prerequisite, 0, sizeof(int) * MAXN);
	memset(classes, 0, sizeof(int) * MAXL);
	memset(cache, -1, sizeof(int) * MAXL * (1<<MAXN));
}	

// 이번 학기가 semester이고, 지금까지 들은 과목의 집합이 taken일 때
// k개 이상의 과목을 모두 들으려면 몇 학기나 더 있어야 하는가?
// 불가능한 경우 INF를 반환한다.
int graduate(int semester, int taken){
	// base condition : k 개 이상의 과목을 모두 들은 경우
	if(__builtin_popcount(taken) >= k) return 0;
	// base condition : m 학기가 전부 지난 경우
	if(semester == m) return INF;

	int& ret = cache[semester][taken];
	if(ret != -1) return ret;
	ret = INF;
	// 선수 과목을ㄷ ㅏ 듣지 않은 과목들을 걸러낸다.
	int canTake = (classes[semester] & ~taken);
	for(int i = 0; i < n; i++){
		if((canTake & (1 << i)) &&
			(taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	}
	// 이 집합의 모든 부분 집합을 순회한다.
	for(int take = canTake; take > 0; take = ((take - 1) & canTake)){
		// 한 학기에 l 과목까지만 들을 수 있다.
		if(__builtin_popcount(take) > l) continue;
		ret = std::min(ret, graduate(semester + 1, taken | take) + 1);
	}
	// 이번 학기에 아무 것도 듣지 않은 경우
	ret = std::min(ret, graduate(semester + 1, taken));
	return ret;
}

int add_element(int& prerequisite, int p){
	prerequisite |= (1 << p);
}

int main(){
	int TC;
	if(freopen("./6-14input.txt", "r", stdin) == NULL){
		printf("file open failed");
	}
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for(int i = 0; i < TC; i++){
		setDefault();
		scanf("%d %d %d %d", &n, &k, &m, &l);
		// input n-lines
		for(int j = 0; j < n; j++){
			int r;
			scanf("%d", &r);
			for(int k = 0; k < r; k++){
				int p;
				scanf("%d", &p);
				add_element(prerequisite[j], p);	
			}
		}
		// input m-lines
		for(int j = 0; j < m; j++){
			int c;
			scanf("%d", &c);
			for(int k = 0; k < c; k++){
				int p;
				scanf("%d", &p);
				add_element(classes[j], p);
			}
		}
		int result, semester = 0, taken = 0;
		result = graduate(semester, taken);
		if(result >= INF){
			printf("IMPOSSIBLE\n");
		}
		else{

			printf("%d\n", result);
		}
	}
}
