#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

const int MAX_N = 20;


int main(){
    freopen("1507.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vvi adj(N, vi(N));   
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &adj[i][j]);

    vvb check(N, vb(N, true));
    for(int i = 0; i < N; i++) check[i][i] = false;
    
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            if(i == k) continue;
           for(int j = 0; j < N; j++){
               if(i == j) continue;
               if(k == j) continue;

               // 잘못된 인접 행렬이 있다면 종료한다.
               if(adj[i][j] > adj[i][k] + adj[k][j]){
                   printf("-1\n");
                   return 0;
               }
               if(adj[i][j] == adj[i][k] + adj[k][j]){
                   check[i][j] = false;
               }
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(check[i][j]){
                sum += adj[i][j];
            }
        }
    }
    printf("%d\n", sum / 2);
}