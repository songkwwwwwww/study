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

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스의 첫째 줄에는 n과 m (2 ≤ n, m ≤ 50)이 주어지며, n은 격자의 행 개수, m은 격자의 열 개수를 나타낸다. 
그 다음 n개의 줄에 각각 격자의 해당 행에 있는 m개의 정수가 열 순서대로 주어진다. 
각 정수는 0 이상 1,000 이하이다.

출력
각 테스트 케이스마다 필요한 연산의 최소 횟수를 한 줄에 출력한다.
*/

const int MAX_N = 50;
const int MAX_M = 50;
const int MAX_V = MAX_N * MAX_M + 2;

int N, M;
int m[MAX_N + 3][MAX_M + 3];


inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int main(){
    freopen("11495.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        int V = N * M + 2;
        int S = V - 2, T = V - 1;
        vvi adj; adj.resize(V);
        vvi c(V, vi(V)), f(V, vi(V));

        int total_sum = 0;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                scanf("%d", &m[x][y]);
                total_sum += m[x][y];
            }
        }

        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                int here = x * M + y;
                if( (x + y) % 2 != 0 ){
                    c[here][T] = m[x][y];
                    adj[here].push_back(T);
                    adj[T].push_back(here);
                }
                else{
                    c[S][here] = m[x][y];
                    adj[S].push_back(here);
                    adj[here].push_back(S);

                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        int there = nx * M + ny;
                        if(is_range(nx, ny)){
                            c[here][there] = INF;
                            adj[here].push_back(there);
                            adj[there].push_back(here);
                        }
                    }
                }
            }
        }
        int total_flow = 0;
        while(true){
            qi q;
            q.push(S);
            vi prev(V, -1);

            while(!q.empty()){
                int here = q.front(); q.pop();

                for(int i = 0; i < adj[here].size(); i++){
                    int there = adj[here][i];

                    if(c[here][there] - f[here][there] > 0 && prev[there] == -1){
                        q.push(there);
                        prev[there] = here;
                    }
                }
            }

            if(prev[T] == -1) break;
                
            int flow = INF;
            for(int i = T; i != S; i = prev[i])
                flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
                
            for(int i = T; i != S; i = prev[i]){
                f[prev[i]][i] += flow;
                f[i][prev[i]] -= flow;
            }
            total_flow += flow;
        }
        printf("%d\n", total_sum - total_flow);
    } // end of TC
}