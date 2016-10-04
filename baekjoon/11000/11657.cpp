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
입력
첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500), 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다. 
둘째 줄부터 M개의 줄에는 버스 노선의 정보 A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)가 주어진다. 

출력
첫째 줄에는 2번 도시까지 가는 가장 빠른 시간, ..., N-1번째 줄에는 N번 도시까지 가는 가장 빠른 시간을 출력한다. 
어떤 도시로 가는 가장 빠른 시간이 없는 경우에는 -1을 출력한다.

만약, 타임머신으로 되어있는 사이클이 존재해 가장 빠른 시간이 존재하지 않는 경우에는 -1을 출력한다.
*/


const int MAX_N = 500;
const int MAX_M = 6000;

int main(){
    freopen("11657.txt", "r", stdin);
    //setbuf(stdout, NULL);

    int N, M;
    scanf("%d %d", &N, &M);
    vector<pii> adj[N];
    for(int i = 0; i < M; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        adj[a].push_back(make_pair(b, c));
    }
    bool minus_cycle = false;
    vi dist(N, INF);
    dist[0] = 0;
    for(int l = 0; l < N; l++){
        for(int here = 0; here < N; here++){
            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i].first, d = adj[here][i].second;
                if(dist[here] != INF && dist[there] > dist[here] + d){
                    dist[there] = dist[here] + d;
                    if(l == N - 1) minus_cycle = true;
                }
            }
        }
    }
    if(minus_cycle) printf("-1\n");
    else{
        for(int i = 1; i < N; i++){
            if(dist[i] != INF)
                printf("%d\n", dist[i]);
            else
                printf("-1\n");
        }
    }
}