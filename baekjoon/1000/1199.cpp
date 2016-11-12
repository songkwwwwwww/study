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


const int MAX_N = 1000;
int N;
vi in_degree, out_degree;
vvi adj;


int solve(int here, vi& trace){
    for(int there = 0; there < N; there++){
        while(adj[here][there] > 0){
            adj[here][there]--;
            adj[there][here]--;
            solve(there, trace);
        }
    }
    trace.push_back(here);
}

int main(){
    freopen("1199.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    adj = vvi(N, vi(N));
    int total_edge = 0;
    in_degree.resize(N); out_degree.resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &adj[i][j]);
            out_degree[i] += adj[i][j];
            in_degree[j] += adj[i][j];
        }
    }
    bool flag = false;
    for(int i = 0; i < N; i++){
        if( (out_degree[i] & 1) || (in_degree[i] & 1)){
            flag = true;
            break;
        }
    }

    if(flag){
        printf("-1\n");
    }
    else{
        vi trace;
        solve(0, trace);
        for(int i = 0; i < trace.size(); i++){
            printf("%d ", trace[i] + 1);
        }
        printf("\n");
    }
    
}