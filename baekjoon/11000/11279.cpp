#include <iostream>
#include <cstdio>

using namespace std;


const int MAX_N = 100000;
int N, size;

int a[MAX_N + 3];

void push(int n){
    int i;
    for (i = ++size; i > 1; i >>= 1) {
	if( n > a[i >> 1] )
	    a[i] = a[i >> 1];
	else
	    break;
    }
    a[i] = n;
}

int pop(){
    int ret = a[1];
    int x = a[size--];
    int i;
    for(i = 2; i<= size; i <<= 1){
	if(i + 1 <= size; a[i] < a[i+1])
	    i++;

	if(x < a[i])
	    a[i >> 1] = a[i];
	else
	    break;
    }
    a[i >> 1] = x;
    return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
	scanf("%d", &N);
	if ( N == 0 ) {
	    if(size == 0)
		printf("0\n");
	    else
		printf("%d\n", pop());
	}
	else {
	    push(N);
	}

    }
}
