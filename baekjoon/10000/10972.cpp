#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // max, min, sort, swap
#include <cmath> // abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

bool my_next_permutation(vector<int>& a, int n){
    int i = n - 1;
    while(i > 0 && a[i - 1] >= a[i]) i--;
    if(i <= 0) return false;
    int j = n - 1;
    while(a[j] <= a[i - 1]) j--;
    swap(a[i-1], a[j]);
    j = n - 1;
    while(i < j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return true;
}

int main(){
    freopen("10972.txt", "r", stdin);
    int N; // 1<= N <=10000
    scanf("%d", &N);
    vector<int> a(N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    if(my_next_permutation(a, N)){
        for(int i = 0; i < N; i++) printf("%d ", a[i]);
        printf("\n");
    }
    else{
        printf("-1\n");
    }
}