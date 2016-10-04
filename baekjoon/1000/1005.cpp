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
첫째 줄에는 테스트케이스의 개수 T가 주어진다. 
각 테스트 케이스는 다음과 같이 주어진다. 
첫째 줄에 건물의 개수 N 과 건물간의 건설순서규칙의 총 개수 K이 주어진다. (건물의 번호는 1번부터 N번까지 존재한다) 

둘째 줄에는 각 건물당 건설에 걸리는 시간 D가 공백을 사이로 주어진다. 

셋째 줄부터 K+2줄까지 건설순서 X Y가 주어진다. (이는 건물 X를 지은 다음에 건물 Y를 짓는 것이 가능하다는 의미이다) 

마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W가 주어진다. 
(1 ≤ N ≤ 1000, 1 ≤ K ≤ 100000 , 1≤ X,Y,W ≤ N, 0 ≤ D ≤ 1000)

출력
건물 W를 건설완료 하는데 드는 최소 시간을 출력한다. 편의상 건물을 짓는 명령을 내리는 데는 시간이 소요되지 않는다고 가정한다.

모든 건물을 지을 수 없는 경우는 없다.
*/

const int MAX_N = 1000;
const int MAX_K = 10000;
const int MAX_D = 1000;

int N, K, W;

int times[MAX_N];
int in_degree[MAX_N];
int result[MAX_N];

int main(){
    freopen("1005.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &K);
        vector<int> adj[N];
        queue<int> q;
        for(int time, i = 0; i < N; i++){
            scanf("%d", &time);
            times[i] = time;
        }
        for(int x, y, i = 0; i < K; i++){
            scanf("%d %d", &x, &y);
            x--; y--;
            in_degree[y]++;
            adj[x].push_back(y);
        }
        scanf("%d", &W);
        W--;
        for(int i = 0; i < N; i++)
            if(in_degree[i] == 0){
                result[i] = times[i];
                q.push(i);
            }
        
        while(!q.empty()){
            int here = q.front(); q.pop();

            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];
                result[there] = max(result[there], result[here] + times[there]);
                in_degree[there]--;
                if(in_degree[there] == 0){
                    q.push(there);
                }
            }
            if(in_degree[W] == 0)
                break;
        }
        printf("%d\n", result[W]);
        memset(in_degree, 0, sizeof(in_degree));
        memset(result, 0, sizeof(result));
    }
}