#include <stdio.h>

const int MAX_N = 10;

int a[MAX_N], b[MAX_N];

void swap(int& a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    freopen("5576.txt", "r", stdin);
    for(int i = 0; i < MAX_N; i++){
	scanf("%d", &a[i]);
    }
    for(int i = 0; i < MAX_N; i++){
	scanf("%d", &b[i]);
    }
    
    for(int i = 0; i < MAX_N - 1; i++){
	for(int j = i + 1; j < MAX_N; j++){
	    if(a[i] < a[j]){
		swap(a[i], a[j]);
	    }

	    if(b[i] < b[j]){
		swap(b[i], b[j]);
	    }
	}
    }

    printf("%d %d\n", a[0] + a[1] + a[2], b[0] + b[1] + b[2]);
}
