//
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 1000000;
char s[MAX_N + 3];
int a[26];

void my_swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

int partition(int l, int r){
    int x = a[r];
    int i = l - 1;
    for(int j = l; j <= r - 1; j++){
	if(a[j] <= x){
	    i++;
	    my_swap(a[i], a[j]);
	}
    }
    my_swap(a[i + 1], a[r]);
    return i + 1;
}
void quick_sort(int l, int r){
    if(l < r){
	int p = partition(l, r);
	quick_sort(l, p - 1);
	quick_sort(p + 1, r);
    }
}

int main(){
#ifdef SONG_TEST
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", s);
    for(int i = 0; s[i]; i++){
	int j = s[i];
	if('a' <= j){
	    j -= 32;
	}
	a[j - 65]++;
    }
    int c = 0, d = -1;
    for(int i = 0; i < 26; i++){
	if(a[i] > d){
	    d = a[i];
	    c = i;
	}
    }
    quick_sort(0, 25);
    if(a[24] == a[25]){
	printf("?\n");
    }
    else{
	printf("%c\n", c + 65);
    }
}
