#include <stdio.h>

#define MIN(x, y) ( (x) < (y) ? (x) : (y) )
#define	TWO	0
#define	FIVE	1

typedef long long ll;

const int INF = 1000000007;
const int MAX_N = 100000;
const int MAX_K = 20;
int T, N, K;

int s[MAX_N + 3];
int d[MAX_N + 3][2];

int get_count(int num, int d){
    int ret = 0;
    while(num % d == 0){
	ret++;
	num /= d;
    }
    return ret;
}

int main(){
    freopen("11583.txt", "r", stdin);
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++){
	    scanf("%d", &s[i]);
	}
	d[0][TWO] = get_count(s[0], 2);
	d[0][FIVE] = get_count(s[0], 5);
	for(int i = 1; i < N; i++){
	    d[i][TWO] = d[i][FIVE] = INF;
	    int cur_two = get_count(s[i], 2);
	    int cur_five = get_count(s[i], 5);
	    for(int j = 1; j <= K; j++){
		if(i - j >= 0){
		    d[i][TWO] = MIN(d[i][TWO], d[i - j][TWO] + cur_two);
		    d[i][FIVE] = MIN(d[i][FIVE], d[i - j][FIVE] + cur_five);
		}
	    }
	}
	printf("%d\n", MIN(d[N - 1][TWO], d[N - 1][FIVE]));
    }
}
