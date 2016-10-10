#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;

const int MAX_N = 32000;
const int MAX_M = 100000;
int N, M;


int main(){
    freopen("2252.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    vvi adj;
    adj.resize(N);
    vi in_degree(N);
    for(int A, B, i = 0; i < M; i++){
        scanf("%d %d", &A, &B);
        A--; B--;
        adj[B].push_back(A);
        in_degree[A]++;
    }
    qi q;
    for(int i = 0; i < N; i++){
        if(in_degree[i] == 0)
            q.push(i);
    }
    int p = 0;
    int ans[MAX_N];
    while(!q.empty()){
        int here = q.front(); q.pop();
        ans[p] = here;
        p++;
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            in_degree[there]--;
            if(in_degree[there] == 0){
                q.push(there);

            }
        }
    }
    for(int i = p - 1; i >= 0; i--){
        printf("%d ", ans[i] + 1);
    }
}