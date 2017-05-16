#include <stdio.h>

int main(){
    freopen("2490.txt", "r", stdin);
    for(int tc = 1; tc <= 3; tc++){
	int count = 0;
	char ans;
	for(int i = 0; i < 4; i++){
	    int n;
	    scanf("%d", &n);
	    count += n;
	}
	if(count == 4){
	    ans = 'E';
	}
	else if(count == 0){

	    ans = 'D';
	}
	else if(count == 1){

	    ans = 'C';
	}
	else if(count == 2){

	    ans = 'B';
	}
	else{ // n == 3

	    ans = 'A';
	}
	printf("%c\n", ans);
    }
}
