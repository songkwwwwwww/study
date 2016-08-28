#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int MAX_N = 1000;
// 첫째 줄에 정점의 개수 N(1≤N≤1,000), 간선의 개수 M(1≤M≤10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
int N, M, V;
    
bool a[MAX_N][MAX_N];
bool visited[MAX_N];

int order[MAX_N];
int count = 0;


// depth first search
void dfs(int here){
    visited[here] = true;
    order[::count++] = here;

    for(int there = 0; there < N; there++){
        if(!visited[there] && a[here][there])
            dfs(there);
    }
}

// breadth first search
void bfs(int start){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    
    ::count = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        order[::count++] = here;
        for(int there = 0; there < N; there++){
            if(!visited[there] && a[here][there]){
                q.push(there);
                visited[there] = true;
            }
        }
    }
}

int main(){
    freopen("1260.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        s--; e--;
        a[s][e] = true;
        a[e][s] = true;
    }
    //memset(visited, false, sizeof(visited));
    V--;
    dfs(V);
    for(int i = 0; i < ::count; i++) printf("%d ", order[i] + 1);
    printf("\n");
    memset(visited, false, sizeof(visited));
    bfs(V);
    for(int i = 0; i < ::count; i++) printf("%d ", order[i] + 1);
    printf("\n");
    
}