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
입력
첫째 줄에는 가수들의 수 N과 보조 PD들의 수 M 이 주어진다. 가수들은 번호 1, 2,…,N 으로 표시한다. 
둘째 줄부터 각 보조 PD가 정한 순서들이 한 줄에 하나씩 나온다. 
각 줄의 맨 앞에는 보조 PD가 담당한 가수의 수가 나오고 그 뒤로는 그 가수들의 순서가 나온다. 
N은 1이상 1,000이하의 정수이고, M은 1이상 100이하의 정수이다.

출력
출력은 N 개의 줄로 이뤄지며, 한 줄에 하나의 번호를 출력한 다. 
이들은 남일이가 정한 가수들의 출연 순서를 나타낸다. 답이 여럿일 경우에는 아무거나 하나를 출력 한다. 
만약 남일이가 순서를 정하는 것이 불가능할 경우에는 첫째 줄에 0을 출력한다.
*/

const int MAX_N = 1000;

int N, M;


vector<int> adj[MAX_N];

int main(){
    freopen("2623.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    vector<int> in_degree(N);
    
    for(int i = 0; i < M; i++){
        int k, prev, cur;
        scanf("%d", &k);

        if(k == 0) continue;
        scanf("%d", &prev);
        for(int j = 1; j < k; j++){
            scanf("%d", &cur);
            in_degree[cur - 1]++;
            adj[prev - 1].push_back(cur - 1);
            prev = cur;
        }
    }
    int result[1000];
    queue<int> q;
    for(int i = 0; i < N; i++)
        if(in_degree[i] == 0)
            q.push(i);
    vector<int> order;
    order.reserve(N);
    while(!q.empty()){
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            in_degree[v]--;
            if(in_degree[v] == 0)
                q.push(v);
        }
    }
    if(order.size() == N){
        for(int i = 0; i < order.size(); i++){
            printf("%d\n", order[i] + 1);
        }
    }
    else{
        printf("0\n");
    }
}