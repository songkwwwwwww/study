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


const int MAX_N = 100;
int N;
double locations[MAX_N][2];
double dist[MAX_N][MAX_N];

bool check(double m){
    int count = 0;

    qi q;
    q.push(0);
    
    vb visited(N);
    visited[0] = true;

    while(!q.empty()){
        int here = q.front(); q.pop();
        count++;

        for(int there = 0; there < N; there++){
            if(!visited[there] && dist[here][there] <= m * m){
                q.push(there);
                visited[there] = true;
            }
        }
    }
    return count == N;
}

// calculate dist
void preprocess(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // locations[i] locations[j]
            dist[i][j] = (locations[i][0] - locations[j][0]) * (locations[i][0] - locations[j][0])
                + (locations[i][1] - locations[j][1]) * (locations[i][1] - locations[j][1]);
        }
    }
}

int main(){
    freopen("ARCTIC.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%lf %lf", &locations[i][0], &locations[i][1]);
        preprocess();

        double l = 0, r = 1000, m;
        for(int i = 0; i < 100; i++){
            m = (l + r) / 2;
            if(check(m))
                r = m;
            else
                l = m;
        }
        printf("%.2lf\n", r);
    }
}