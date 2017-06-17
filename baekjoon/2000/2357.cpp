#include <stdio.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

const int INF = 1000000007;
const int MAX_N = 100000;
const int MAX_M = 100000;
int N, M;

int a[MAX_N + 3];
int min_tree[1 << 20 + 3];
int max_tree[1 << 20 + 3];

void init(int node, int start, int end){
    if(start == end){
	min_tree[node] = a[start];
	max_tree[node] = a[start];
    }
    else{
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	min_tree[node] = MIN(min_tree[node * 2], min_tree[node * 2 + 1]);
	max_tree[node] = MAX(max_tree[node * 2], max_tree[node * 2 + 1]);
    }
}

int min_query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
	return INF;
    }
    if(l <= start && end <= r){
	return min_tree[node];
    }
    int m1 = min_query(node * 2, start, (start + end) / 2 , l, r);
    int m2 = min_query(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
    return MIN(m1, m2);
}

int max_query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
	return -INF;
    }
    if(l <= start && end <= r){
	return max_tree[node];
    }
    int m1 = max_query(node * 2, start, (start + end) / 2 , l, r);
    int m2 = max_query(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
    return MAX(m1, m2);
}
int main(){
    freopen("2357.txt", "r", stdin);
    //
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
	scanf("%d", &a[i]);
    }
    init(1, 0, N - 1);

    for(int i = 0; i < M; i++){
	int a, b;
	scanf("%d %d", &a, &b);
	a--; b--;
	int min = min_query(1, 0, N - 1, a, b);
	int max = max_query(1, 0, N - 1, a, b);
	printf("%d %d\n", min, max);
    }
}
