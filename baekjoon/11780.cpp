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


const int MAX_N = 100;
const int MAX_M = 100000;
int N, M;
vvi adj;
vvi prev;


int main(){
    freopen("11780.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    adj = vvi(N, vi(N, INF));
    prev = vvi(N, vi(N, -1));

    for(int u, v, w, i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u][v] = w;
        prev[u][v] = v;
    }
    for(int i = 0; i < N; i++) adj[i][i] = 0;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                prev[i][j] = prev[i][k];
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(adj[i][j] == INF)
                adj[i][j] = 0;
            printf("%d%c", adj[i][j], j == N - 1 ? '\n' : ' ');
        }
    }
    for(int u = 0; u < N; u++){
        for(int v = 0; v < N; v++){
            vi path; path.reserve(N);
            path.push_back(u);
            while(true){
                if(prev[u][v] == -1)
                    break;
                else{
                    u = prev[u][v];
                    path.push_back(u);
                }
            }
            if(path.size() == 1)
                printf("0");
            else{
                printf("%d ", (int)path.size());
                for(int i = 0; i < path.size(); i++)
                    printf("%d ", path[i] + 1);
            }
            printf("\n");
        }
    }
}