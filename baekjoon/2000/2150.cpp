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
//#include <unordered_map>

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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 
이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 
다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이다. 
이 때 방향은 A->B가 된다.

출력
첫째 줄에 SCC의 개수를 K를 출력한다. 
다음 K개의 줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다. 
각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다. 
각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다. 
또한 여러 개의 SCC에 대해서는 그 안에 속해있는 가장 작은 정점의 정점 번호 순으로 출력한다.
*/
const int MAX_V = 10000;
const int MAX_E = 100000;

int V, E;

// SN : SCC 개수, sn[i] : i 가 속한 scc의 번호
int SN, sn[MAX_V];

int cnt, dfsn[MAX_V];
bool finished[MAX_V]; // SCC 분리가 끝난 정점만 true

vector<int> adj[MAX_V];
stack<int> S;
vector< vector<int> > SCC;

// 자신의 결과값을 리턴하는 DFS 함수
int dfs(int cur){
    dfsn[cur] = ++cnt; // dfsn 결정
    S.push(cur);

    // 자신의 dfsn, 자신들의 결과나 dfsn 중 가장 작은 번호를 result에 저장.
    int result = dfsn[cur];
    for(int i = 0; i < adj[cur].size(); i++){
        int there = adj[cur][i];
        // 아직 방문하지 않은 이웃
        if(dfsn[there] == 0) result = min(result, dfs(there));
        // 방문은 했으나 아직 SCC로 추출되지 않은 이웃
        else if(!finished[there]) result = min(result, dfsn[there]);
    }

    // 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
    if(result == dfsn[cur]){
        vector<int> cur_scc;
        // 스택에서 자신이 나올 떄까지 pop
        while(true){
            int t = S.top();
            S.pop();
            cur_scc.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if(t == cur) break;
        }
        // 출력을 위해 원소 정렬
        sort(cur_scc.begin(), cur_scc.end());
        // SCC 추출
        SCC.push_back(cur_scc);
        SN++;
    }
    return result;
}
    

int main(){
    freopen("2150.txt", "r", stdin);
    scanf("%d %d", &V, &E);

    for(int u, v, i = 0; i < E; i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
    }

    for(int i = 0; i < V; i++)
        if(dfsn[i] == 0)
            dfs(i);
    
    sort(SCC.begin(), SCC.end());

    printf("%d\n", SN);

    for(int i = 0; i < SCC.size(); i++ ){
        vector<int> cur_scc = SCC[i];
        for(int j = 0; j < cur_scc.size(); j++){
            printf("%d ", cur_scc[j] + 1);
        }
        printf("-1\n");
    }

}