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


const int MAX_N = 8;
const int MAX_M = 30;

int N, M, P, A, B; // A != B

int t[MAX_N];
vector< pair<int, int> > adj[MAX_M];

// d[S][v] : 남은 승차권이 S, 현재 위치 v라는 상태에 도달할 때까지의 최소 비용
double d[1 << MAX_N][MAX_M];

double solve(int state, int here){
    if(here == B) return 0;

    double& ret = d[state][here];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i].first;
        int weight = adj[here][i].second;
        for(int j = 0; j < N; j++){
            if( !(state & (1 << j)) )
                ret = min(ret, ((double)weight / t[j]) + solve(state | (1 << j) , there) );
            
        }
    }
    return ret;
}

int main(){
    freopen("4989.txt", "r", stdin);
    //setbuf(stdout, NULL);
    while(scanf("%d %d %d %d %d", &N, &M, &P, &A, &B) == 5){
        if(N == 0 && M == 0 && P == 0 && A == 0 && B == 0) break;
        for(int i = 0; i < MAX_M; i++)
            adj[i].clear();
        for (int i = 0; i < (1 << N); i++)
            for (int j = 0; j < M; j++)
                d[i][j] = -1;
        
        for(int i = 0; i < N; i++)
            scanf("%d", &t[i]);
        
        for(int i = 0; i < P; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));     
        }
        
        A--; B--;
        double res = solve(0, A);
        
        if(res == INF){
            printf("Impossible\n");
        }
        else{
            printf("%.3lf\n", res);
        }
    } // end of while
}