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
The first line of input contains N, the number of test cases. The first line of each test case contains 1 <= S <= 100, the number of satellite channels, and S < P <= 500, the number of outposts. P lines follow, giving the (x,y) coordinates of each outpost in km (coordinates are integers between 0 and 10,000). 

출력
For each case, output should consist of a single line giving the minimum D required to connect the network. Output should be specified to 2 decimal points.
*/
const int MAX_S = 100;
const int MAX_P = 500;
int p[MAX_P];

int Find(int a){
    if(a == p[a]) return a;
    else p[a] = Find(p[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    p[b] = a;
}

inline int square_distance(int x1, int y1, int x2, int y2){
    return ( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );
}


int main(){
    freopen("4343.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    vector<pair<int, int> > v;
    while(TC--){
        int S, P;
        scanf("%d %d", &S, &P);
        int x[P], y[P];
        for(int i = 0; i < P; i++)
            scanf("%d %d", &x[i], &y[i]);

        vector< pair<int, pair<int, int> > > edges;
        edges.reserve(P * P);

        for(int w, i = 0; i < P; i++){
            for(int j = 0; j < P; j++){
                if(i == j) continue;
                w = square_distance(x[i], y[i], x[j], y[j]);
                edges.push_back(make_pair(w, make_pair(i, j)));
            }
        }
 
        sort(edges.begin(), edges.end());
 
        for(int i = 0; i < P; i++)
            p[i] = i;
        int cnt = 0;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(Find(u) == Find(v)) continue;
            Union(u, v);
            if(++cnt== P - S){
                printf("%.2lf\n", sqrt(edges[i].first));
                break;
            }
        }
    }
}