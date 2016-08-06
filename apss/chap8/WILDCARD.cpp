//unsolved
/*
https://algospot.com/judge/problem/read/WILDCARD
*/

#include <cstdio>

char wildcard[100];
int n; // 1<= n <= 50;
char str[50][100];

int calc(){


}


int main(){
	freopen("WILDCARD.txt", "r", stdin);

	int TC;
//	for(int i = 0; i < 50; i++)
//		printf("%d'th size : %ld\n", i+1, sizeof(str[i]));



	scanf("%d", &TC);
	for(int i = 0; i < TC; i++){
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			fgets(str[j], sizeof(str[j]), stdin);
			str[j][sizeof(str[j])-1]='\0';
			printf("string[%d] : %s\n", j, str[j]);
		}
		
	}

}

