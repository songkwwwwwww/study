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

const int INF = 987654321;
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 유저의 수 N (2 ≤ N ≤ 100)과 친구 관계의 수 M (1 ≤ M ≤ 5,000)이 주어진다. 
둘째 줄부터 M개의 줄에는 친구 관계가 주어진다. 
친구 관계는 A와 B로 이루어져 있으며, A와 B가 친구라는 뜻이다. 
A와 B가 친구이면, B와 A도 친구이며, A와 B가 같은 경우는 없다. 
친구 관계는 중복되어 들어올 수도 있으며, 친구가 한 명도 없는 사람은 없다.

출력
첫째 줄에 BOJ의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람을 출력한다. 
그런 사람이 여러 명일 경우에는 번호가 가장 작은 사람을 출력한다.
*/

int V, E;

int adj[100][100];

int main(){
    freopen("1389.txt", "r", stdin);
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;      
    
    for(int u, v, i = 0; i < E; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    
    int max_sum = INF;
    int ans;
    for(int i = 0; i < V; i++){
        int sum = 0;
        for(int j = 0; j < V; j++){
            if(i == j) continue;
            
            sum += adj[i][j];
        }
        if(max_sum > sum){
            max_sum = sum;
            ans = i;
        }
    }
    printf("%d\n", ans + 1);
}