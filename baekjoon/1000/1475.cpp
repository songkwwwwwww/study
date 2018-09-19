//
#include <iostream>
#include <cstdio>

#define MAX(a, b) ( ((a) < (b)) ? (b) : (a))

using namespace std;

const int MAX_N = 1000000;
int N;
int count[10];

int main(){
#ifdef SONG_TEST
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    int result = 0;
    do{
	int a = N % 10;
	count[a]++;
	N /= 10;
    } while(N);
    for(int j = 0; j < 10; j++){
	if(j == 6 || j == 9)
	    continue;
	if(result < count[j])
	    result = count[j];
    }
    int temp = count[6] + count[9];
    temp = (temp >> 1) + (temp & 1);
    result = MAX(result, temp);
    printf("%d\n", result);
}
