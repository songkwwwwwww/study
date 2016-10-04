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
const int MAX_V = 20000;

/*

*/

const int MAX_N = 32000;
const int MAX_M = 100000;
int in_degree[MAX_N];
int N, M;

int main(){
    freopen("1766.txt", "r", stdin);
    
    
    scanf("%d %d", &N, &M);
    vector<int> adj[N];
    /*
    for(int i = 0; i < N; i++)
        in_degree[i]=0;
        */
    for(int u, v, i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        in_degree[v - 1]++;
    }
    priority_queue<int> pq;
    for(int i = 0; i < N; i++)
        if(in_degree[i] == 0)
            pq.push(-i);
    vector<int> order;
    //order.reserve(N);

    while(!pq.empty()){
        int here = -pq.top(); pq.pop();
        //order.push_back(here);
        printf("%d ", here+1);
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            in_degree[there]--;
            if(in_degree[there] == 0){
                pq.push(-there);
            }
        }
    }
    /*
    for(int i = 0; i < N; i++){
        printf("%d ", order[i] + 1);
    }
    printf("\n");*/
}