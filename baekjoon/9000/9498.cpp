#include <stdio.h>


int main(){
    freopen("9498.txt", "r", stdin);
    int N;
    char ans;
    scanf("%d", &N);
    
    if(N >= 90){
	ans = 'A';
    }
    else if(80 <= N && N <= 89){
	ans = 'B';
    }
    else if(70 <= N && N <= 79){
	ans = 'C';
    }
    else if(60 <= N && N <= 69){
	ans = 'D';
    }
    else{
	ans = 'F';
    }
    printf("%c\n", ans);
}
