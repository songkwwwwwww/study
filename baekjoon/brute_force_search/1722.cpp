#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // max, min, sort, swap
#include <cmath> // abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

ll factorial_array[21] = {1};
bool c[21];

int main(){
    freopen("1722.txt", "r", stdin);
    int N, problem_type; // 1<= N <=10000
    scanf("%d", &N);
    scanf("%d", &problem_type);
    vector<int> a(N);

    for(int i = 1; i <= 20; i++){
        factorial_array[i] = factorial_array[i - 1] * i; 
    }

    if(problem_type == 1){
        ll k; // 1 <= k <= N!
        scanf("%lld", &k);
        
        for(int i = 0; i < N; i++){
            for(int j = 1; j <= N; j++){
                if(c[j] == true) continue;
                if(factorial_array[N - 1 - i] < k){
                    k -= factorial_array[N - 1 - i];
                }
                else{
                    a[i] = j;
                    c[j] = true;
                    break;
                }
            }
        }

        for(int i = 0; i < N; i++) printf("%d ", a[i]);
        printf("\n");
    }
    else if(problem_type == 2){
        for(int i = 0; i < N; i++) scanf("%d", &a[i]);
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < a[i]; j++) {
                if (c[j] == false) {
                    ans += factorial_array[N - 1 - i];
                }
            }
            c[a[i]] = true;
        }
        printf("%lld\n", ans + 1);
    }
    

}