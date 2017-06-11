#include <stdio.h>

typedef long long ll;
const int MAX_N = 1000000;
const int MAX_M = 10000;
const int MAX_K = 10000;
int N, M, K;

int b = 1;

ll tree[4 * MAX_N + 3];

void update(int x, ll diff) {
	x += b;
	tree[x] += diff;
	while (x > 1) {
		tree[x / 2] += diff;
		x >>= 1;
	}
}

ll sum(int l, int r) {
	l += b;
	r += b;
	ll ret = 0;

	while (l < r) {
		if (l & 1) {
			ret += tree[l];
			l++;
			l >>= 1;
		}
		else {
			l >>= 1;
		}

		if (r & 1) {
			r >>= 1;
		}
		else {
			ret += tree[r];
			r--;
			r >>= 1;
		}
	}
	if (l == r) {
		ret += tree[l];
	}
	return ret;
}

int main() {
	freopen("2042.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	while (b < N) {
		b <<= 1;
	}
	b--;
	for (int i = 1; i <= N; i++) {
		ll x;
		scanf("%lld", &x);
		update(i, x);
	}
	for (int i = 0; i < M + K; i++) {
		int c, d;
		ll e;
		scanf("%d %d %lld", &c, &d, &e);
		if (c == 1) {
			update(d, e - tree[d + b]);
		}
		else { // a == 2
			printf("%lld\n", sum(d, e));
		}
	}
}
