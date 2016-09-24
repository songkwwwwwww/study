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


const int MAX_N = 10000;
const int MAX_M = 10000;
const int MAX_R = 50000;

int N, M, R;

int find(vi& p, int a){
    if(p[a] < 0) return a;
    else return p[a] = find(p, p[a]);
}

void merge(vi& p, int a, int b){
    a = find(p, a);
    b = find(p, b);
    if(a == b) return;
    p[b] = a;
}


int main(){
    freopen("3723.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        // N girls and M boys
        scanf("%d %d %d", &N, &M, &R);
        vector<pair<int, pair<int, int> > > edges;
        edges.reserve(R * 2);
        for(int i = 0; i < R; i++){
            // girl x and boy y have a relationship d
            int x, y, d;
            scanf("%d %d %d", &x, &y, &d);
            y = N + y;
            edges.push_back(make_pair(-d, make_pair(x, y)));
            edges.push_back(make_pair(-d, make_pair(y, x)));            
        }
        ll result = 0;
        int count_edges = 0;
        sort(edges.begin(), edges.end());
        vi p(N + M, -1);

        for(int i = 0; i < edges.size(); i++){
            if(count_edges == N + M - 1) break;
            int cost = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(find(p, u) == find(p, v)) continue;
            merge(p, u, v);
            result += cost;
            count_edges++;
        }
        result += 10000 * (N + M); 
        printf("%lld\n", result);
    }
}