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
const int MAX_V = 1000;
const int MAX_E = 100000;

/*
입력
첫째 줄에 컴퓨터의 수(1<=N<=1000)가 주어진다.

둘째 줄에는 연결할 수 있는 선의 수(1<=M<=100,000)가 주어진다.

셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다. 
이 비용의 정보는 세 개의 정수로 주어지는데, 
만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c만큼 든다는 것을 의미한다.

출력
모든 컴퓨터를 연결하는데 필요한 최소비용을 첫째 줄에 출력한다.
*/

int p[MAX_V + 1];

int Find(int a){
    if(a == p[a]) return a;
    else return p[a] = Find(p[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return ;
    p[b] = a;
}

int V, E;

vector<pair<int, int> > adj[MAX_V];

int kruskal(vector<pair<int, int> >& selected){
    int ret = 0;
    selected.clear();

    vector< pair<int, pair<int, int> > > edges;
    for(int u = 0; u < V; u++){
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    sort(edges.begin(), edges.end());
    
    for(int cnt = 0, i = 0; i < edges.size(); i++){
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;

        if(Find(u) == Find(v)) continue;
        Union(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
        if(selected.size() == V - 1) break;
    }
    
    return ret;
}

int main(){
    freopen("1922.txt", "r", stdin);
    scanf("%d %d", &V, &E);
    for(int i = 0; i <= V; i++){
        p[i] = i;
    }
    
    for(int u, v, w, i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u - 1].push_back(make_pair(v - 1, w));
        adj[v - 1].push_back(make_pair(u - 1, w));
    }
    vector<pair<int, int> > selected; 
    
    printf("%d\n", kruskal(selected));
}
