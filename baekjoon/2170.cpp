#include <cstdio>

#define MAX(x, y) ( (x) < (y) ? (y) : (x)  )

using namespace std;

const int INF = 1000000001;
const int MAX_N = 1000000;
int N;

struct point{
    int s, e;
};

point a[MAX_N + 3];


template <typename T>
void swap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

int partition(int l, int r){
    point x = a[r];
    int i = l - 1;

    for(int j = l; j <= r - 1; j++){
	if(a[j].s <= x.s){
	    i++;
	    swap(a[i], a[j]);
	}
    }
    swap(a[i + 1], a[r]);
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
    freopen("2170.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
	scanf("%d %d", &a[i].s, &a[i].e);
    }

    quick_sort(0, N - 1);

    int s = -INF, e = -INF, ans = 0;
    
    for(int i = 0; i < N; i++){
	// 포함되는 경우
	if(a[i].s <= e){
	    e = MAX(e, a[i].e);
	}
	// 포함되지 않는 경우
	else{
	    ans += (e - s);
	    s = a[i].s;
	    e = a[i].e;
	}
    }
    ans += (e - s);
    printf("%d\n", ans);
}
