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
// 정점의 개수 N과 간선의 개수 M이 주어진다. 
// (1 ≤ N ≤ 1,000, 1 ≤ M ≤ N×(N-1)/2) 
int N, M;

bool a[MAX_N][MAX_N];
bool visited[MAX_N];

void dfs(int here){
    visited[here] = true;
    for(int there = 0; there < MAX_N; there++){
        if(!visited[there] && a[here][there])
            dfs(there);
    }
}

void dfs_all(){
    int count = 0;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    printf("%d\n", count);
}

int main(){
    freopen("11724.txt", "r", stdin);
    int s, e;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &s, &e);
        s--; e--;
        a[s][e] = true;
        a[e][s] = true;
    }

    dfs_all();
}