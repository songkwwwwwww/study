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

/*
입력
첫째 줄에 테스트 케이스의 수 K (1 ≤ K ≤ 1000)가 주어진다.

각 테스트 케이스의 첫째 줄에는 K, M, P가 주어진다. 
K는 테스트 케이스 번호, M은 노드의 수, P는 간선의 수이다. (2 ≤ M ≤ 1000) 
다음 P개 줄에는 간선의 정보를 나타내는 A, B가 주어지며, A에서 B로 물이 흐른다는 뜻이다. (1 ≤ A, B ≤ M) 
M은 항상 바다와 만나는 노드이며, 밖으로 향하는 간선은 존재하지 않는다.

출력
각 테스트 케이스마다 테스트 케이스 번호와 입력으로 주어진 하천계의 Strahler 순서를 출력한다.
*/

const int MAX_M = 1000;

int in_degree[MAX_M];
int K, M, P;

int main(){
    freopen("9470.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d", &K, &M, &P);
        queue<int> q;
        vector<int> adj[M];
        vector< pair<int, int> > vec(M);
        for(int u, v, i = 0; i < P; i++){
            scanf("%d %d", &u, &v);
            u--; v--;
            in_degree[v]++;
            adj[u].push_back(v);
        }

        for(int i = 0; i < M; i++){
            if(in_degree[i] == 0){
                q.push(i);
                vec[i] = make_pair(1, 1);
            }
        }

        while(!q.empty()){
            int here = q.front(); q.pop();
            int& strahler = vec[here].first;
            int& count = vec[here].second;
            if(count >= 2){
                strahler++;
                count = 1;
            }

            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];
                int& next_strahler = vec[there].first;
                int& next_count = vec[there].second;

                if(strahler > next_strahler){
                    next_strahler = strahler;
                    next_count = 1;
                }
                else if(strahler == next_strahler){
                    next_count++;
                }
                

                in_degree[there]--;
                if(in_degree[there] == 0){
                    q.push(there);
                }
            }
        }
        printf("%d %d\n", K, vec[M - 1].first);
        memset(in_degree, 0, sizeof(in_degree));
    }
}