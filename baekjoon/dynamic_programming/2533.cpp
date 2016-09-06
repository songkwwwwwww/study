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

/*
입력
첫 번째 줄에는 친구 관계 트리의 정점 개수 N이 주어진다. 
단, 2 <= N <= 1,000,000이며, 각 정점은 1부터 N까지 일련번호로 표현된다.
두 번째 줄부터 N-1개의 줄에는 각 줄마다 친구 관계 트리의 에지 (u, v)를 나타내는 
두 정수 u 와 v가 하나의 빈칸을 사이에 두고 주어진다. 

출력
주어진 친구 관계 그래프에서 아이디어를 전파하는데 필요한 얼리 아답터의 최소 수를
 하나의 정수로 출력한다
*/
const int INF = 987654321;

int N;
vector<int> adj[1000000], child[1000000];
int d[1000000][2];
bool visited[1000000];


int dfs(int here){
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        if(!visited[there]){
            child[here].push_back(there);
            dfs(there);
        }
    }
}

/*
    pe : parent is early-adopter
*/
int solve(int here, bool pe){
    int& ret = d[here][pe];
    if(ret != -1) return ret;

    int selected = 1, unselected = INF;
    for(int i = 0; i < child[here].size(); i++){
        int there = child[here][i];
        selected += solve(there, true);

    }
    
    if(pe == true){
        unselected = 0;
        for(int i = 0; i < child[here].size(); i++){
            int there = child[here][i];
            unselected += solve(there, false);
        }
    }

    return ret = MIN(selected, unselected);
}

int main(){
    freopen("2533.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        start--; end--;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    memset(d, -1, sizeof(d));
    dfs(0);
    printf("%d\n", solve(0, true));
}