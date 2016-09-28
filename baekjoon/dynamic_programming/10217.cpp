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
입력 파일의 첫 번째 줄에 테스트 케이스의 수를 의미하는 자연수 T가 주어진다. 
그 다음에는 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 
첫 줄에는 공항의 수 N (2 ≤ N ≤ 100), 총 지원비용 M (0 ≤ M ≤ 10,000), 티켓정보의 수 K (0 ≤ K ≤ 10,000)가 
공백으로 구분되어 주어진다. 
이어서 K개의 줄에 걸쳐 
각 티켓의 출발공항 u, 도착공항 v (1 ≤ u, v ≤ N, u ≠ v), 비용 x (1 ≤ c ≤ M, 정수), 그리고 소요시간 d ( 1 ≤ d ≤ 1,000) 
가 공백으로 구분되어 주어진다. 
인천은 언제나 1번 도시이고, LA는 언제나 N번 도시이다

출력
각 테스트 케이스당 한 줄에 찬민이 LA에 도착하는 데 걸리는 가장 짧은 소요시간을 출력한다.

만약, LA에 도착할 수 없는 경우 "Poor KCM"을 출력한다.
*/


const int MAX_N = 100;
const int MAX_M = 10000;
const int MAX_K = 10000;
int N, M, K;

struct edge{
    int to, cost, time;
    bool operator < (const edge& rhs) const{
        if(this->time == rhs.time)
            return this->cost > rhs.cost;
        else
            return this->time > rhs.time;
    }
};

vector< vector<edge> > adj ;
vvi d;

int solve(int here, int money){
    // base case
    if(here == N - 1){
        return 0;
    }
    
    int& ret = d[here][money];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < adj[here].size(); i++){
        const edge& e = adj[here][i];
        if(money - e.cost >= 0){
            ret = min(ret, solve(e.to, money - e.cost) + e.time);
        }
    }

    return ret;
}

int main(){
    freopen("10217.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d", &N, &M, &K);
        adj.clear();
        adj.resize(N);
        d = vvi(N, vi(M + 1, INF));
        for(int i = 0; i < K; i++){
            int u, v, c, t;
            scanf("%d %d %d %d", &u, &v, &c, &t);
            u--; v--;
            adj[u].push_back((edge){v, c, t});
        }

        priority_queue<edge> pq;
        pq.push((edge){0, 0, 0});
        d[0][0] = 0;

        while(!pq.empty()){
            edge e_here = pq.top(); pq.pop();
            int here = e_here.to;
            int cost = e_here.cost;
            int time = e_here.time;

            if(here == N - 1) break;

            if(d[here][cost] < time) continue;
            // d[here][cost] >= time
            d[here][cost] = time;

            for(int i = 0; i < adj[here].size(); i++){
                edge& there = adj[here][i];

                if(cost + there.cost > M) continue;
                if(d[there.to][cost + there.cost] <= time + there.time) continue;

                pq.push((edge){there.to, cost + there.cost, time + there.time});
                d[there.to][cost + there.cost] = time + there.time;
            }
        }
        int result = INF;
        for(int i = 0; i <= M; i++)
            result = min(result, d[N - 1][i]);
        
        //int result = solve(0, M);
        if(result == INF) printf("Poor KCM\n");
        else printf("%d\n", result);
    }
}

/*

const int MAX_N = 100;
const int MAX_M = 10000;
const int MAX_K = 10000;
int N, M, K;

struct edge{
    int to, cost, time;
};

vector< vector<edge> > adj ;
vvi d;

int solve(int here, int money){
    // base case
    if(here == N - 1){
        return 0;
    }
    
    int& ret = d[here][money];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < adj[here].size(); i++){
        const edge& e = adj[here][i];
        if(money - e.cost >= 0){
            ret = min(ret, solve(e.to, money - e.cost) + e.time);
        }
    }

    return ret;
}

int main(){
    freopen("10217.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d", &N, &M, &K);
        adj.clear();
        adj.resize(N);
        d = vvi(N, vi(M + 1, -1));
        for(int i = 0; i < K; i++){
            int u, v, c, t;
            scanf("%d %d %d %d", &u, &v, &c, &t);
            u--; v--;
            adj[u].push_back((edge){v, c, t});
        }
        int result = solve(0, M);
        if(result == INF) printf("Poor KCM\n");
        else printf("%d\n", result);
    }
}
*/