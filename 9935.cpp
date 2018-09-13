//
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 1000000;
const int MAX_M = 36;
int n, m;

char a[MAX_N + 3], b[MAX_M + 3];
char s[MAX_N + 3];
int p = 0;


int main(){
#ifdef SONG_TEST
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", a);
    scanf("%s", b);
    for(; a[n]; n++)
	;
    for(; b[m]; m++)
	;
#ifdef SONG_TEST
    printf("a : %s\n", a);
    printf("n : %d\n", n);

    printf("b : %s\n", b);
    printf("m : %d\n", m);
#endif
    for(int i = 0; i < n; i++){
	s[p++] = a[i];

	if(s[p - 1] == b[m - 1] && m <= p){
	    bool flag = true;
	    for(int j = 0; j < m; j++){
		if(s[p - 1 - j] != b[m - 1 - j]){
		    flag = false;
		    break;
		}
	    }
	    if(flag)
		p -= m;
	}
    }
    s[p] = '\0';
    if(p == 0){
	printf("FRULA\n");
    }
    else{
	printf("%s\n", s);
    }
}
