//
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;
int N;

char str[MAX_N + 3];
int sa[MAX_N * 2 + 3];
int group[MAX_N * 2 + 3];
int temp_group[MAX_N * 2 + 3];
int d;

int cmp(int i, int j){
    if(group[i] == group[j])
	return ( i + d < N && j + d < N )? group[i + d] < group[j + d] : i > j;
    else
	return group[i] < group[j];
}

int main(){
#ifdef SONG_INPUT
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", str);
    int i = 0;
    for(i = 0; str[i]; i++){
	sa[i] = i;
	group[i] = str[i] - 'a';
    }
    N = i;
#ifdef SONG_TEST
    printf("N : %d\n", N);
#endif
    for(d = 1; d <= N; d *= 2){
#ifdef SONG_TEST
        printf("===========\n");
        printf("d : %d\n", d);
#endif
	sort(sa, sa + N, cmp);

#ifdef SONG_TEST
    for(int k = 0; k < N; k++){
	printf("%s\n", str + sa[k]);
    }
#endif
	temp_group[sa[0]] = 0;

	for(i = 1; i < N; i++){
	    temp_group[sa[i]] = temp_group[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
	}
	for(i = 0; i < N; i++){
	    group[i] = temp_group[i];
	}
#ifdef SONG_TEST
        printf("===========\n");
#endif
    }
    for(i = 0; i < N; i++){
	printf("%s\n", str + sa[i]);
    }
}
