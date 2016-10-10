#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
int N;
int a[MAX_N];

int main(){
    freopen("2437.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    sort(a, a + N);

    int prev_sum = 0;
    for(int i = 0; i < N; i++){
        if(prev_sum + 1 < a[i]){
            break;
        }
        prev_sum += a[i];
    }
    prev_sum++;
    printf("%d\n", prev_sum);
}