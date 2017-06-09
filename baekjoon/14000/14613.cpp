#include <stdio.h>

typedef long long ll;

const int MAX_N = 20;
ll d[MAX_N + 3][MAX_N + 3];

ll factorials[MAX_N + 3];
double p, q, r;
double ps[MAX_N + 3], qs[MAX_N + 3], rs[MAX_N + 3];
double ans[5];


int main(){
    freopen("14613.txt", "r", stdin);
    scanf("%lf %lf %lf", &p, &q, &r);
    factorials[0] = 1;
    for(int i = 1; i <= MAX_N; i++){
	factorials[i] = factorials[i - 1] * i;
    }

    ps[0] = qs[0] = rs[0] = 1;
    for(int i = 1; i <= MAX_N; i++){
	ps[i] = ps[i - 1] * p;
	qs[i] = qs[i - 1] * q;
	rs[i] = rs[i - 1] * r;
    }
    for(int w = 0; w <= 20; w++){
	for(int l = 0; l <= 20; l++){
	    for(int d = 0; d <= 20; d++){
		if(w + l + d == 20){
		    int base = 2000 + 50 * w - 50 * l;
		    // nCr p^r q^(n - r)
		    double temp = (double)factorials[20] / (double)(factorials[w] * factorials [l] * factorials[d])
			* ps[w] * qs[l] * rs[d];
		    ans[(base - 1000) / 500] += temp;
		}
	    }
	}
    }
    for(int i = 0; i < 5; i++){
	printf("%.8lf\n", ans[i]);
    }
}
