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

const int INF = 987654321;
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*

*/

int N;

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}
int main(){
    freopen("4485.txt", "r", stdin);
    int count = 1;

    while(scanf("%d", &N) && N != 0){
        int W[N][N];

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &W[i][j]);
        
        vector< pair<int, int> > adj[N * N];

        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){

                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(is_range(nx, ny)){
                        adj[x * N + y].push_back(make_pair(nx * N + ny, W[nx][ny]));
                    }
                }
            }
        }

        vector<int> dist(N * N, INF);
        dist[0] = 0;
        priority_queue< pair<int, int> > pq;
        pq.push(make_pair(0, 0));
        while(!pq.empty()){
            int cost = -pq.top().first;
            int here = pq.top().second;
            pq.pop();

            if(dist[here] < cost) continue;

            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i].first;
                int next_dist = cost + adj[here][i].second;
                if(dist[there] > next_dist){
                    dist[there] = next_dist;
                    pq.push(make_pair(-next_dist, there));
                }
            }
        }
        printf("Problem %d: %d\n", count++, W[0][0] + dist[N * N - 1]);
    }
}