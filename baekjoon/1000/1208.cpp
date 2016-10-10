#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<int> vi;

const int MAX_N = 40;


int main(){
    freopen("1208.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, S;
    scanf("%d %d", &N, &S);
    vi a(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int M = N / 2;
    N = N - M;
    vi first(1 << N);
    for(int i = 0; i < (1 << N); i++){
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                first[i] += a[j];
            }
        }
    }

    vi second(1 << M);
    for(int i = 0; i < (1 << M); i++){
        for(int j = 0; j < M; j++){
            if(i & (1 << j)){
                second[i] += a[N + j];
            }
        }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end(), greater<int>());
    
    N = (1 << N);
    M = (1 << M);
    int i = 0;
    int j = 0;
    long long ans = 0;
    while(i < N && j < M){
        if(first[i] + second[j] == S){
            long long c1 = 1;
            long long c2 = 1;
            i++;
            j++;
            while(i < N && first[i] == first[i - 1]){
                c1++;
                i++;
            }
            while(j < M && second[j] == second[j - 1]){
                c2++;
                j++;
            }
            ans += c1 * c2;
        }
        else if(first[i] + second[j] < S){
            i++;
        }
        else{
            j++;
        }
    }
    if(S == 0) ans--;
    printf("%lld\n", ans);
}