#include <stdio.h>

using namespace std;

const int MAX_N = 1000;
int N;

char str[MAX_N + 3];
int suffix[MAX_N + 3];
int lcp[MAX_N + 3];

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int strcmp(const char* str1, const char* str2){
    int i;
    for(i = 0; str1[i] == str2[i]; i++)
	if(str1[i] == '\0')
	    return 0;

    return str1[i] - str2[i];
}

int partition(int l, int r){
    
    int i = l - 1;
    for(int j = l; j <= r - 1; j++){
	if(strcmp( str + suffix[j], str + suffix[r] ) < 0 ){
	    i++;
	    swap(suffix[i], suffix[j]);
	}
    }
    swap(suffix[i + 1], suffix[r]);
    return i + 1;
}

void quick_sort(int l, int r){
    if(l < r){
	int p = partition(l, r);
	quick_sort(l, p - 1);
	quick_sort(p + 1, r);
    }
}

int get_lcp(const char* str1, const char* str2){
    int i = 0;
    while(str1[i] && str2[i] && str1[i] == str2[i])
	i++;
    return i;
}

int main(){
    freopen("11478.txt", "r", stdin);
    scanf("%s", str);
    for(N = 0; str[N]; N++)
	;
    for(int i = 0; i < N; i++)
	suffix[i] = i;

    quick_sort(0, N - 1);
    lcp[0] = 0;
    for(int i = 1; i < N; i++){
	lcp[i] = get_lcp( str + suffix[i - 1], str + suffix[i] );
    }
    int sum = 0;
    for(int i = 0; i < N; i++){
	int temp = N - suffix[i] - lcp[i];
	sum += temp;
    }
    printf("%d\n", sum);
}
