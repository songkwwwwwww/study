#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;

const int MAX_N = 10000;

int main(){
    freopen("2056.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vi time(N);
    vi result(N);
    vvi adj;
    adj.reserve(N);
    vi in_degree(N);

    for(int u, i = 0; i < N; i++){
        scanf("%d", &time[i]);
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &u);
            adj[i].push_back(u - 1);
            in_degree[u - 1]++;
        }
    }
    qi q;
    for(int i = 0; i < N; i++){
        if(in_degree[i] == 0){
            q.push(i);
            result[i] = time[i];
        }
    }
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            in_degree[there]--;
            result[there] = max(result[there], result[here] + time[there]);
            if(in_degree[there] == 0)
                q.push(there);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, result[i]);
    }
    printf("%d\n", ans);
}