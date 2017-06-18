#include <stdio.h>

const int MAX_N = 150;
int N;

char a[31];
int count[26];

int main(){
    freopen("1159.txt", "r", stdin);
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
	scanf("%s", a);
	count[a[0] - 'a']++;
    }
    bool flag = false;
    for(int i = 0; i < 26; i++){
	if(count[i] >= 5){
	   printf("%c", i + 'a');
	   flag = true;
	}
    }
    if(!flag)
	printf("PREDAJA");
    printf("\n");
}
