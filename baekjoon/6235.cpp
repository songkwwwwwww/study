#include <stdio.h>


const int MAX_Q = 3000;
const int MAX_P = 3000;

struct node {
	int q, p;
};

node aa[MAX_Q + 3];

char s[10];

template <typename T>
void swap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

bool cmp(const node& a, const node& b) {
	return a.q < b.q;
}

int partition(int l, int r) {
	int i = l - 1;
	for (int j = l; j <= r - 1; j++) {
		if (cmp(aa[j], aa[r])) {
			i++;
			swap(aa[i], aa[j]);
		}
	}
	swap(aa[i + 1], aa[r]);
	return i + 1;
}

void quick_sort(int l, int r) {
	if (l < r) {
		int p = partition(l, r);
		quick_sort(l, p - 1);
		quick_sort(p + 1, r);
	}
}

int main() {
	freopen("6235.txt", "r", stdin);
	int n = 0;
	while (scanf("%s", s)) {
		if (s[0] == '#')
			break;
		int p, q;
		scanf("%d %d", &q, &p);
		aa[n++] = (node) { q, p };
	}
	int K, k = 0;
	scanf("%d", &K);

	quick_sort(0, n - 1);
	int c = 1;
	while (true) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (c % aa[i].p == 0) {
				printf("%d\n", aa[i].q);
				k++;
				if (k == K) {
					flag = true;
					break;
				}
			}
		}
		if (flag)
			break;
		c++;
	}
}
