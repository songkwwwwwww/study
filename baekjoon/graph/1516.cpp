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
const int MAX_V = 20000;

/*

*/

const int MAX_N = 500;
vector<int> adj[MAX_N];
int in_degree[MAX_N];
int times[MAX_N];
int result[MAX_N];
int N;


int main(){
    freopen("1516.txt", "r", stdin);
    scanf("%d", &N);

    queue<int> q;

    for(int time, val, i = 0; i < N; i++){
        scanf("%d", &time);
        times[i] = time;
        while(scanf("%d", &val) && val != -1){
            adj[val - 1].push_back(i);
            in_degree[i]++;
        }
        if(in_degree[i] == 0){
            result[i] = times[i];
            q.push(i);
        }
    } 

    while(!q.empty()){
        int here = q.front(); q.pop();
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            result[there] = max(result[there], result[here] + times[there]);
            in_degree[there]--;
            if(in_degree[there] == 0)
                q.push(there);
        }
    }
    for(int i = 0; i < N; i++)
        printf("%d\n", result[i]);
}