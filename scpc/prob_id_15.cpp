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


const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;



int main(){
    freopen("prob_id_15.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d", &N, &M);
        vector< vector<pii> > adj; adj.resize(N);        
        for(int u, v, w, i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        vb check(N, false);
        for(int start = 0; start < N; start++){
            // cost, vertex
            priority_queue<pii> pq;
            pq.push(make_pair(0, start));
            vi dist(N, INF);
            dist[start] = 0;

            while(!pq.empty()){
                int here = pq.top().second;
                int cost = -pq.top().first;
                pq.pop();

                if(dist[here] < cost) continue;

                for(int i = 0; i < adj[here].size(); i++){
                    int there = adj[here][i].first;
                    int next_cost = cost + adj[here][i].second;

                    if(next_cost < dist[there]){
                        dist[there] = next_cost;
                        pq.push(make_pair(-next_cost, there));
                    }
                }
            }
            for(int here = 0; here < N; here++){
                if(start == here) continue;
                for(int i = 0; i < adj[here].size(); i++){
                    int there = adj[here][i].first;
                    int cost = adj[here][i].second;

                    if(dist[there] == dist[here] + cost){
                        check[here] = true;
                    }
                }
            }
        } // end of for(start~)

        int ans = 0;
        vi back_track; back_track.reserve(N);
        for(int i = 0; i < N; i++){
            if(check[i] == false){
                ans++;
                back_track.push_back(i + 1);
            }
        }

        printf("Case #%d\n", tc);
        printf("%d ", ans);
        int size = back_track.size();
        for(int i = 0; i < size; i++){
            printf("%d%c", back_track[i], (i == size - 1) ? '\n' : ' ');
        }
    }
}