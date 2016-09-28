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
문제
그래프의 한 정점 S에서 다른 한 정점 T로 이동하려 한다. 
이동할 때 T에 가까워지며 이동하는 경우, 이를 합리적인 이동경로라 한다. 
물론 이러한 경로는 최단경로가 아닐 수도 있다.

그래프가 주어졌을 때 가능한 합리적인 이동경로의 개수를 구하는 프로그램을 작성하시오. S=1, T=2 인 경우로 한다.

입력
첫째 줄에 정점의 개수 N(1<N≤1,000), 간선의 개수 M이 주어진다. 
다음 M개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
이는 A번 정점과 B번 정점이 길이 C(>0)인 간선으로 연결되어 있다는 의미이다. 
두 정점은 최대 한 개의 간선으로만 연결될 수 있다. 간선은 방향성이 없다.

출력
첫째 줄에 답을 출력한다. 답은 2147483647을 넘지 않는다.
*/


const int MAX_N = 1000;
const int MAX_M = 8;
int N, M;
int S = 0, T = 1;

vector< vector< pii > > adj;
//vvi dist;
vi dist;
vi d;

int solve(int here){
    // base case
    if(here == T) return 1;

    int& ret = d[here];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i].first;

        if(dist[there] < dist[here]){
            ret += solve(there);
        }
    }

    return ret;
}

int main(){
    freopen("2176.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    adj.resize(N);
    dist = vi(N, INF);

    for(int A, B, C, i = 0; i < M; i++){
        scanf("%d %d %d", &A, &B, &C);
        A--; B--;
        adj[A].push_back(make_pair(B, C));
        adj[B].push_back(make_pair(A, C));
    }
   
    // (길이, 정점) 순으로 저장한다.
    priority_queue<pii> pq;
    pq.push(make_pair(0, T));
    dist[T] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;

        for(int j = 0; j < adj[here].size(); j++){
            int there = adj[here][j].first;
            int next_cost = adj[here][j].second + cost;

            if(next_cost < dist[there]){
                dist[there] = next_cost;
                pq.push(make_pair(-next_cost, there));
            }
        }
    }
    
    
    d = vi(N, -1);
    printf("%d\n", solve(S));
}


/*

const int MAX_N = 1000;
const int MAX_M = 8;
int N, M;
int S = 0, T = 1;

vector< vector< pii > > adj;
vvi dist;
vi d;

int solve(int here){
    // base case
    if(here == T) return 1;

    int& ret = d[here];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i].first;

        if(dist[there][T] < dist[here][T]){
            ret += solve(there);
        }
    }

    return ret;
}

int main(){
    freopen("2176.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    adj.resize(N);
    dist = vvi(N, vi(N, INF));

    for(int A, B, C, i = 0; i < M; i++){
        scanf("%d %d %d", &A, &B, &C);
        A--; B--;
        adj[A].push_back(make_pair(B, C));
        adj[B].push_back(make_pair(A, C));
    }
    for(int i = 0; i < N; i++){
        // (길이, 정점) 순으로 저장한다.
        priority_queue<pii> pq;
        pq.push(make_pair(0, i));
        dist[i][i] = 0;

        while(!pq.empty()){
            int cost = -pq.top().first;
            int here = pq.top().second;
            pq.pop();
            if(dist[i][here] < cost) continue;

            for(int j = 0; j < adj[here].size(); j++){
                int there = adj[here][j].first;
                int next_cost = adj[here][j].second + cost;

                if(next_cost < dist[i][there]){
                    dist[i][there] = next_cost;
                    pq.push(make_pair(-next_cost, there));
                }
            }
        }
    }
    
    d = vi(N, -1);
    printf("%d\n", solve(S));
}
*/