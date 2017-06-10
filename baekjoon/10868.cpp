#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

const int INF = 987654321;
const int MAX_N = 100000;
const int MAX_M = 100000;
int N, M;

int a[MAX_N + 3];
int tree[1 << 20 + 3];

void init(int node, int start, int end){
    if(start == end){
	tree[node] = a[start];
    }
    else{
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = MIN(tree[node * 2], tree[node * 2 + 1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
	return -1;
    }
    if(l <= start && end <= r){
	return tree[node];
    }
    int m1 = query(node * 2, start, (start + end) / 2, l, r);
    int m2 = query(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
    if(m1 == -1) return m2;
    else if(m2 == -1) return m1;
    else return MIN(m1, m2);
}

int main(){
    freopen("10868.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
	scanf("%d", &a[i]);
    }
    init(1, 0, N - 1);

    for(int i = 0; i < M; i++){
	int a, b;
	scanf("%d %d", &a, &b);
	a--; b--;
	int ans = query(1, 0, N - 1, a, MIN(b, N));
	printf("%d\n", ans);
    }
}
