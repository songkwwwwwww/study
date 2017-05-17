#include <stdio.h>

using namespace std;

int main(){
    freopen("5565.txt", "r", stdin);
    int sum = 0;
    scanf("%d", &sum);
    for(int i = 0; i < 9; i++){
	int n;
	scanf("%d", &n);
	sum -= n;
    }
    printf("%d\n", sum);
}
