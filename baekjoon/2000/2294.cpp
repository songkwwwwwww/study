#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 987654321;

const int MAX_N = 100;
const int MAX_K = 10000;


int main(){
    freopen("2294.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, K;
    scanf("%d %d", &N, &K);
    int a[MAX_N + 1];
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }
    vi d(K + 1, INF);
    d[0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = a[i]; j <= K; j++){
            d[j] = min(d[j], d[j - a[i]] + 1);
            //if(d[j] > d[j - a[i]] + 1)
            //    d[j] = d[j - a[i]] + 1;
        }
    }
    printf("%d\n", d[K] == INF ? -1 : d[K]);
}