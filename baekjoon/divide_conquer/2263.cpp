#include <stdio.h>

using namespace std;

int N; // 1 <= N <= 10,0000

int in_order[100000];
int post_order[100000];
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end){
    if (in_start > in_end || post_start > post_end) return;
    int root = post_order[post_end];
    printf("%d ", root);
    int p = position[root];

    int left = p-in_start;
    solve(in_start, p-1, post_start, post_start + left - 1);
    solve(p+1, in_end, post_start+left, post_end-1);
}

int main(){
    freopen("2263.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &in_order[i]);
        position[in_order[i]] = i;
    }
    for (int i = 0; i < N; i++) scanf("%d", &post_order[i]);

    solve(0, N - 1, 0, N - 1);
    printf("\n");
    return 0;
}