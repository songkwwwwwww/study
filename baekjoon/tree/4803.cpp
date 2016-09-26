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
입력은 여러 개의 테스트 케이스로 이루어져 있다. 
각 테스트 케이스의 첫째 줄에는 n ≤ 500과 m ≤ n(n-1)/2을 만족하는 정점의 개수 n과 간선의 개수 m이 주어진다. 
다음 m개의 줄에는 간선을 나타내는 두 개의 정수가 주어진다. 같은 간선은 여러번 주어지지 않는다. 
정점은 1번부터 n번까지 번호가 매겨져 있다. 입력의 마지막 줄에는 0이 두 개 주어진다.

출력
입력으로 주어진 그래프에 트리가 없다면 "No trees."를, 
한 개라면 "There is one tree."를, 
두 개 이상이라면 "A forest of T trees."를 테스트 케이스 번호와 함께 출력한다.
*/


const int MAX_N = 500;
const int MAX_M = MAX_N *(MAX_N - 1) / 2;
int N, M;

vi adj[MAX_N];
vi p;
vb visited;

int main(){
    freopen("4803.txt", "r", stdin);
    //setbuf(stdout, NULL);
    for(int tc = 1; ; tc++){
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;
        for(int u, v, i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);                       
        }
        visited = vb(N, false);
        
        int count_of_components = 0;
        for(int l = 0; l < N; l++){
            if(!visited[l]){
                qi q;
                q.push(l);
                visited[l] = true;
                int count_of_vertex = 0;
                int count_of_edges = 0;
                while(!q.empty()){
                    int here = q.front(); q.pop();
                    count_of_vertex++;
                    for(int i = 0; i < adj[here].size(); i++){
                        int there = adj[here][i];
                        count_of_edges++;

                        if(!visited[there]){
                            q.push(there);
                            visited[there] = true;
                        }
                    }
                }
                count_of_edges /= 2;
                if(count_of_vertex == count_of_edges + 1)
                    count_of_components++;
            }
        }
        if(count_of_components == 0){
            printf("Case %d: No trees.\n", tc);
        }
        else if(count_of_components == 1){
            printf("Case %d: There is one tree.\n", tc);
        }
        else{ // count_of_components >= 2
            printf("Case %d: A forest of %d trees.\n", tc, count_of_components);
        }

        for(int i = 0; i < N; i++)
            adj[i].clear();
    } // end of loop
}