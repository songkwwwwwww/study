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
    freopen("1476.txt", "r", stdin);
    int E, S, M, e = 0, s = 0, m = 0;

    // 1 <= E <= 15 -> 0 <= E <= 14
    // 1 <= S <= 28 -> 0 <= S <= 27
    // 1 <= M <= 19 -> 0 <= M <= 18
    scanf("%d %d %d", &E, &S, &M);
    E--; S--; M--; // 14, 27, 18
    
    for(int i = 1; ;i++){
        if(e == E && s == S && m == M){
            printf("%d\n", i);
            break;
        }
        e = ( e + 1 ) % 15;
        s = ( s + 1 ) % 28;
        m = ( m + 1 ) % 19;
    }
}