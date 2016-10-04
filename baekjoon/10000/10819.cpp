#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // max, min, sort, swap
#include <cmath> // abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main(){
    freopen("10819.txt", "r", stdin);

    
    int N; // 3 <= N <= 8
    scanf("%d", &N);
    vector<int> a(N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    sort(a.begin(), a.end());

    int ans = 0;
    do{
        int sum = 0;
        for(int i = 1; i < a.size(); i++){
            sum += abs(a[i] - a[i-1]);
        }
        ans = max(sum, ans);
    }while(next_permutation(a.begin(), a.end()));
    printf("%d\n", ans);
}