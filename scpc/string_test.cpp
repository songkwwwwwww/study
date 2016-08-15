#include <cstring>
#include <cstdio>

char str[1000][1001];

int main(){


	for(int i = 0; i < 1000; i++){

//		fgets( str[i], 1001, stdin );
		scanf("%s", str[i]);

		int index =strlen(str[i]) - 1;
		str[i][ index ] = '\0';
		printf("string %d : %s\n", i + 1, str[i]);
	}

}
