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

typedef vector<int> vi;
typedef vector<vi> vvi;

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


const int MAX_N = 5000;
const int MAX_R = 100000;



int main(){
    freopen("3255.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, R;
    scanf("%d %d", &N, &R);
    vector<pii> adj[N];
    for(int u, v, w, i = 0; i < R; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }
    vi dist1(N, INF), dist2(N, INF);
    dist1[0] = 0;

    priority_queue<pii> pq;
    pq.push(pii(0, 0));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist2[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = cost + adj[here][i].second;
            if(dist1[there] > next_dist){
                pq.push(pii(-next_dist, there));
                swap(dist1[there], next_dist);
            }
            if(dist1[there] < next_dist && next_dist < dist2[there]){
                dist2[there] = next_dist;
                pq.push(pii(-next_dist, there));                
            }
        }
    }
    printf("%d\n", dist2[N - 1]);

}