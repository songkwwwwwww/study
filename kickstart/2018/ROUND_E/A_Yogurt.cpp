// boj 2346
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 5000;

int T, N, K;
int a[MAX_N + 3];

template<typename T>
void my_swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int partition(int l, int r){
    int x = a[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++) {
	if ( a[j] <= x ) {
	    i++;
	    my_swap(a[i], a[j]);
	}
    }
    my_swap(a[i + 1], a[r]);
    return i + 1;
}

void quick_sort(int l, int r){
    if(l < r){
	int p = partition(l, r);
	quick_sort(l, p - 1);
	quick_sort(p + 1, r);
    }
}

int main(){
//    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
	int result = 0;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++){
	    scanf("%d", &a[i]);
	}
	quick_sort(0, N - 1);

	int current_day = 1;

	for(int i = 0; i < N; i++){
	    if(current_day > a[i])
		continue;

	    int remains = N - i < K ? N - i : K;
	    result += remains;
	    i += (remains - 1);
	    current_day++;
	}

	printf("Case #%d: %d\n", tc, result);
    }
}
