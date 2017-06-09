#include <stdio.h>

const int MAX_N = 1000;
int N, K;

struct node{
    int index, g, s, b;
};

node a[MAX_N + 3];

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

bool comp(node& a, node& b){
    if(a.g != b.g){
	return a.g > b.g;
    }
    else if(a.s != b.s){
	return a.s > b.s;
    }
    else if(a.b != b.b){
	return a.b > b.b;
    }
    else{
	return a.index == K;
    }
}

int partition(int l, int r){
    int i = l - 1;
    for(int j = l; j <= r - 1; j++){
	if(comp(a[j], a[r])){
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
    freopen("8979.txt", "r" , stdin);

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
	scanf("%d %d %d %d", &a[i].index, &a[i].g, &a[i].s, &a[i].b);
    }
    quick_sort(0, N - 1);
    for(int i = 0; i < N; i++){
	if(a[i].index == K){
	    printf("%d\n", i + 1);
	    break;
	}
    }
}
