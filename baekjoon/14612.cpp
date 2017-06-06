#include <stdio.h>

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_T = 1000;
const int INF = 987654321;
int N, M;

char str[10];

struct node{
    int n, t;
};

node arr[MAX_T + 3];

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

bool cmp(node& a, node& b){
    if(a.t != b.t){
	return a.t < b.t;
    }
    else{
	return a.n < b.n;
    }
}


int partition(int l, int r){
    int i = l - 1;
    for(int j = l; j <= r - 1; j++){
	if(cmp(arr[j], arr[r])){
	    i++;
	    swap(arr[i], arr[j]);
	}
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quick_sort(int l, int r){
    if(l < r){
	int q = partition(l, r);
	quick_sort(l, q -  1);
	quick_sort(q + 1, r);
    }
}

void print(int n){
    for(int i = 0; i < n; i++){
	printf("%d%c", arr[i].n, i == n - 1 ? '\n' : ' ');
    }
}

int main(){
    freopen("14612.txt", "r", stdin);
    int count = 0, a, b;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
	scanf("%s", str);
	if(str[0] == 'o'){ // order
	    scanf("%d %d", &a, &b);
	    arr[count] = (node){a, b};
	    count++;
	}
	else if(str[0] == 's'){ // sort
	    quick_sort(0, count - 1);
	}
	else{ // complete
	    scanf("%d", &a);
	    int i = 0;
	    for(i = 0; i < count; i++){
		if(arr[i].n == a)
		    break;
	    }
	    for(; i < count - 1; i++){
		arr[i] = arr[i + 1];
	    }
	    count--;
	}
	if(count == 0){
	    printf("sleep\n");
	}
	else{
	    print(count);
	}
    }
}
