#include <cstdio>
#include <cmath>
using namespace std;
 
int main(){
    freopen("1541.txt", "r", stdin);
    int val[26], N = 0, result = 0, i;
    for(i=0; scanf("%d", val+i) > 0; i++) N++;

    for(i=0; i < N; i++){
	printf("%d ", *(val + i));
    }
    //for(i=0; i<N && val[i]>=0; i++) result += val[i];
    //for(; i<N; i++) result -= abs(val[i]);
    //printf("%d\n", result);

    printf("\n");
}
