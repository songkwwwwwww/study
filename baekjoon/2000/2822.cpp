#include <stdio.h>


struct p{
    int n, index;
};

p a[8];

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int partition(int l, int r){
    int x = a[r].n;
    int i = l - 1;
    for(int j = l; j <= r - 1; j++){
	if(a[j].n < x){
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
    freopen("2822.txt", "r", stdin);
    bool flag[8] = {false, };
    for(int i = 0; i < 8; i++){
	scanf("%d", &a[i].n);
	a[i].index = i;
    }
    quick_sort(0, 7);
    int sum = 0;
    for(int i = 7; i >= 3; i--){
	sum += a[i].n;
	flag[a[i].index] = true;
    }
    printf("%d\n", sum);
    for(int i = 0; i < 8; i++){
	if(flag[i]){
	    printf("%d ", i + 1);
	}
    }
    printf("\n");
}
