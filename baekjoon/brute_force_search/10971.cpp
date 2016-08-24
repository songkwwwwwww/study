#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // max, min, sort, swap
#include <cmath> // abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int W[10][10];

int main(){
    freopen("10971.txt", "r", stdin);
    int N; // 2 <= N <= 10;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);
    
    vector<int> path(N-1);
    for(int i = 1; i < N; i++)
        path[i - 1] = i;
    
    int ans = 2147483647;

    do{
        bool ok = true;
        int sum = 0;
        for(int i = 0; i < N - 2; i++){
            if(W[ path[i] ][ path[i + 1] ] == 0)
                ok = false;
            else
                sum += W[ path[i] ][ path[i + 1] ];
            
        }
        if( ok && W[ 0 ][ path[0] ] != 0 && W[ path[N-2] ][ 0 ] != 0){
            sum += W[0][path[0]] + W[path[N-2]][0];
            ans = min(ans, sum);
        }
    }while(next_permutation(path.begin(), path.end()));
    printf("%d\n", ans);
}