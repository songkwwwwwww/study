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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

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


const int MAX_N = 8;
const int MAX_K = 8;


int main(){
    freopen("prob_id_29.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int N, K;
        scanf("%d %d", &N, &K);
        int V = 402;
        int S = V - 2;
        int T = V - 1;
        vvi adj; adj.resize(V);
        vvi c(V, vi(V));
        vvi f(V, vi(V));
        int p_sum = 0;
        // S -> 장인[0, 100) -> 시간[100, 200) -> 구두[200, 400) -> T;
        // 구두 i에 대한 입력
        for(int a, f, p, i = 0; i < N; i++){
            scanf("%d %d %d", &a, &f, &p);
            p_sum += p;
            
            // 구두에서 T
            adj[i + 200].push_back(T);
            adj[T].push_back(i + 200);
            c[i + 200][T] = p;

            // 시간에서 구두
            for(int j = a + 1; j <= f; j++){
                adj[j + 100].push_back(i + 200);
                adj[i + 200].push_back(j + 100);
                c[j + 100][i + 200] = 1;
            }
        }
        // 장인 i에 대한 입력
        for(int s, e, i = 0; i < K; i++){
            scanf("%d %d", &s, &e);

            // S에서 장인
            adj[S].push_back(i);
            adj[i].push_back(S);
            c[S][i] = e - s;

            // 장인에서 시간
            for(int j = s + 1; j <= e; j++){
                adj[i].push_back(j + 100);
                adj[j + 100].push_back(i);
                c[i][j + 100] = 1;
            }
        }
        int total_flow = 0;
        while(true){
            vi prev(V, -1);
            qi q;
            q.push(S);

            while(!q.empty()){
                int here = q.front(); q.pop();
                if(here == T) break;
                for(int i = 0; i < adj[here].size(); i++){
                    int there = adj[here][i];

                    if(c[here][there] - f[here][there] > 0 && prev[i] == -1){
                        q.push(there);
                        prev[there] = here;
                    }
                }
            }
            // 더이상 유량이 없음
            if(prev[T] == -1) break;

            int flow = INF;
            for(int i = T; i != S; i = prev[i])
                flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

            for(int i = T; i != S; i = prev[i]){
                f[prev[i]][i] += flow;
                f[i][prev[i]] -= flow;
            }
            total_flow += flow;
        } // end of while

        printf("p_sum : %d\ntotal_flow : %d\n", p_sum, total_flow);
        printf("Case #%d\n%d\n", tc, total_flow == p_sum ? 1 : 0);
    }
}