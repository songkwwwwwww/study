#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("11399.txt", "r", stdin);
    int N; // 1 <= N <= 1000
    int a[1000];

    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    
    sort(a, a+N);
    int sum = a[0];
    for(int i = 1; i < N; i++){
        a[i] += a[i-1];
        sum += a[i];
    }
    printf("%d\n", sum);
}