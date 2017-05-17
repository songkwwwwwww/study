#include <stdio.h>

int main(){
    freopen("5063.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
	int r, e, c;
	scanf("%d %d %d", &r, &e, &c);
	if(r == e - c){
	    printf("does not matter\n");
	}
	else if(r > e - c){
	    printf("do not advertise\n");
	}
	else{
	    printf("advertise\n");
	}
    }
}
