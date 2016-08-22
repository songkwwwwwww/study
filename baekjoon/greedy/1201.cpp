#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    freopen("1201.txt", "r", stdin);
    // M, K <= N <= 500
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
        
    if( (M + K - 1 <= N) && (N <= M *K) ){
        vector<int> a(N);
        for(int i = 0; i < N; i++) a[i] = i + 1;

        vector<int> g;
        if(M != 0) g.reserve(N / M + 3);
        g.push_back(0);
        g.push_back(K);

        N -= K;
        M -= 1;

        int range_step = (M == 0 ? 1 : N / M);
        int remainder = (M == 0 ? 0 : N % M);
    
        for (int i = 0; i < M; i++) {
            g.push_back(g.back() + range_step + (remainder > 0 ? 1 : 0));
            if (remainder > 0) {
                remainder--;
            }
        }

        for (int i = 1; i < g.size(); i++)
            reverse(a.begin() + g[i-1], a.begin() + g[i]);
        
        for(int i = 0; i < a.size(); i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else{
        printf("-1\n");
    }
}