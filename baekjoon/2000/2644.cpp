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
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
입력
사람들은 1, 2, 3, …, n (1≤n≤100)의 연속된 번호로 각각 표시된다. 
입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고, 
둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다. 
그리고 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다. 
넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다. 
이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.

출력
입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이 때에는 -1을 출력해야 한다.
*/
int N;
int S, E;
int m;

const int INF = 987654321;

vector<int> adj[100];

int bfs(int start, int end){
    queue<int> q;
    vector<int> dist(N + 1, -1);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == end) break;
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            if(dist[there] == -1){
                q.push(there);
                dist[there] = dist[here] + 1;
            }
        }
    }
    return dist[end] - dist[start];
}

int main(){
    freopen("2644.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%d %d", &S, &E);
    scanf("%d", &m);
    int s, e;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &s, &e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    printf("%d\n", bfs(S, E));
}