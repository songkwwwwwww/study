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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

typedef pair<int, int> pii;


const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 1000;
const int MAX_M = 2000000;
const int MAX_K = 100;

int N, M, K;

int main(){
    freopen("1854.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &K);
    vector<pii> adj[N];
        
    for(int u, v, w, i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u].push_back(make_pair(v, w));
    }
    priority_queue<int> kth[N];
    
    priority_queue<pii> pq;
    pq.push(make_pair(0, 0));
    kth[0].push(0);
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = cost + adj[here][i].second;
            
            if(kth[there].size() < K){
                pq.push(make_pair(-next_dist, there));
                kth[there].push(next_dist);
            } 
            else if(kth[there].top() > next_dist){
                kth[there].push(next_dist);
                pq.push(make_pair(-next_dist, there));
                kth[there].pop();
            }
            
        }
    }

    for(int i = 0; i < N; i++){
        if(kth[i].size() != K){
            printf("-1\n");
        }
        else{
            printf("%d\n", kth[i].top());
        }
    }
}