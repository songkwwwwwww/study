#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
//#include <unordered_map> // c++11

#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 10000;
const int MAX_M = 100000;


int main(){
    freopen("1325.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M;
    scanf("%d %d", &N, &M);
    vi count(N + 1, 1);
    vvi adj; adj.resize(N + 1);
    
    for(int u, v, i = 0; i < M; i++){
        scanf("%d %d", &v, &u);
        adj[u].push_back(v);
    }
    int max_val = 0;
    vi ans; ans.reserve(N + 1);
    for(int start = 1; start <= N; start++){
        qi q;
        q.push(start);
        vb visited(N + 1);
        visited[start] = true;
        int cnt = 1;
        while(!q.empty()){
            int here = q.front(); q.pop();

            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];
                if(!visited[there]){
                    visited[there] = true;
                    q.push(there);
                    cnt++;
                }
            }
        }
        if(cnt > max_val){
            ans.clear();
            ans.push_back(start);
            max_val = cnt;
        }
        else if(cnt == max_val){
            ans.push_back(start);
        }
    }
    
    for(int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}


/*


int main(){
    freopen("1325.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M;
    scanf("%d %d", &N, &M);
    vi count(N + 1, 1);
    vvi adj; adj.resize(N + 1);
    vi in_degree(N + 1);
    
    for(int u, v, i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        in_degree[v]++;
    }
    qi q;
    for(int i = 1; i <= N; i++){
        if(in_degree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];

            count[there] += count[here];
            in_degree[there]--;
            if(in_degree[there] == 0){
                q.push(there);
            }
        }
    }
    vi ans; ans.reserve(N + 1);
    int max_val = 0;
    for(int i = 1; i <= N; i++){
        if(count[i] > max_val){
            ans.clear();
            ans.push_back(i);
            max_val = count[i];
        }
        else if(count[i] == max_val){
            ans.push_back(i);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}
*/